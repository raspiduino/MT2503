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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__MMI_XT9__)

#include "MMI_features.h"
  
#ifdef  __MMI_T9__

#include "GlobalConstants.h"
#include "Fat_fs.h"
#include "Word_Engine.h"  
#include "IMERes.h"     /* include cfor sIMEModeDetails */
#include "mmi_frm_gprot.h"

#include "ImeGprot.h"


    #include "MMIDataType.h"
    #include "gui_data_types.h"
    #include "kal_general_types.h"
    #include "fs_type.h"
    #include "string.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "ImmProt.h"
    //#include "xxt9oem.h"
    #include "Unicodexdcl.h"
    #include "fs_func.h"

#ifndef ET9_ALPHABETIC_MODULE 
#define ET9_ALPHABETIC_MODULE
#endif

#ifdef __MMI_T9_MULTITAP__
#include "Multitap_engine.h"
#endif /* __MMI_T9_MULTITAP__ */

#include "Imc.h"

#include "et9api.h"
#include "et9awapi.h"
#include "et9ldb.h"
#include "et9keydb.h"
#include "et9kbdef.h"

#define T9STATUS ET9STATUS
#define T9STATNONE ET9STATUS_NONE


#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)|| defined(__MMI_T9_HK_CHINESE__)
#ifndef ET9_CHINESE_MODULE
#define ET9_CHINESE_MODULE
#endif
#define __T9_CHINESE
#include "et9cpapi.h"
#endif /* defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */

/*****************************************************************************
 * Define
 *****************************************************************************/
#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
#define MMI_IME_T9_MAX_TEXT_BUFFSIZE            (MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE * 2 + 1)
#else
#define MMI_IME_T9_MAX_TEXT_BUFFSIZE            (MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE)
#endif

#define MMI_MULTITAP_T9_PAGE_BUFFSIZE   (32 + 1)

#if defined(__MMI_IME_USER_DATABASE__)

#define MMI_IME_T9_UDB_SIZE (20 * 1024) /* 20k bytes (T9 recommended), if we don't turn on word completion
                                         * it should be 4k butes. It should be bigger than T9MINUDBDATABYTES */

#define MMI_IME_T9_CDB_SIZE (4 * 1024)  /* 4k bytes */

#define MMI_IME_USER_DATABASE_FILE_UDB        L"ime_udb.dat"
#define MMI_IME_USER_DATABASE_FILE_CDB        L"ime_cdb.dat"

#endif
    

#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
#define MMI_IME_T9_MAX_PREDICTION_WORD_NUM     (6)     /* Default value from T9 */
#endif


#define SEL_LIST_SIZE   32

/*****************************************************************************
 * Global variables
 *****************************************************************************/
static void mmi_ime_xt9_set_vk_type(U16 key);

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
}   mmi_ime_t9_init_type_enum;

/*
typedef enum
{
    IME_XT9_HQR,
    IME_XT9_HQD,
    IME_XT9_HPD,
    IME_XT9_SQD 

}INPUTMODE; */


typedef enum
{
    OLD_CANDIDATE,
    NEW_CANDIDATE 

}CANDIDATE_FLAG;	

CANDIDATE_FLAG candidate_flag;



#ifdef __T9_CHINESE

static const ET9U8  g_t9_keys_chinese[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] =
{
#ifdef __MMI_T9_DEFAULT_KEY_DEFINITION__
    ET9CPgKEYAMBIGB, // IME_SYMB_KEY_0
#else /* __MMI_T9_DEFAULT_KEY_DEFINITION__ */
    ET9CPgKEYAMBIGA, // IME_SYMB_KEY_0
#endif /* __MMI_T9_DEFAULT_KEY_DEFINITION__ */
    
    ET9CPgKEYAMBIG1, // MMI_IMC_SYMB_KEY_1
    ET9CPgKEYAMBIG2, // MMI_IMC_SYMB_KEY_2
    ET9CPgKEYAMBIG3, // MMI_IMC_SYMB_KEY_3
    ET9CPgKEYAMBIG4, // MMI_IMC_SYMB_KEY_4
    ET9CPgKEYAMBIG5, // MMI_IMC_SYMB_KEY_5
    ET9CPgKEYAMBIG6, // MMI_IMC_SYMB_KEY_6
    ET9CPgKEYAMBIG7, // MMI_IMC_SYMB_KEY_7
    ET9CPgKEYAMBIG8, // MMI_IMC_SYMB_KEY_8
    ET9CPgKEYAMBIG9, // MMI_IMC_SYMB_KEY_9

#ifdef __MMI_T9_DEFAULT_KEY_DEFINITION__
    ET9CPgKEYAMBIGA, // MMI_IMC_SYMB_KEY_STAR
    ET9CPgKEYAMBIGC, // MMI_IMC_SYMB_KEY_POUND
#else /* __MMI_T9_DEFAULT_KEY_DEFINITION__ */
   ET9CPgKEYNONE, // MMI_IMC_SYMB_KEY_STAR
   ET9CPgKEYNONE, // MMI_IMC_SYMB_KEY_POUND
#endif /* __MMI_T9_DEFAULT_KEY_DEFINITION__ */
};

static const mmi_imc_symb_stroke_enum g_t9_keys_stroke[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] =
{
    0,                                /* MMI_IMC_SYMB_KEY_0 */
    MMI_IMC_SYMB_STROKE_OVER,         /* MMI_IMC_SYMB_KEY_1 */
    MMI_IMC_SYMB_STROKE_DOWN,         /* MMI_IMC_SYMB_KEY_2 */
    MMI_IMC_SYMB_STROKE_LEFT,         /* MMI_IMC_SYMB_KEY_3 */
    MMI_IMC_SYMB_STROKE_DOT,          /* MMI_IMC_SYMB_KEY_4 */
    MMI_IMC_SYMB_STROKE_OVER_DOWN,    /* MMI_IMC_SYMB_KEY_5 */
    MMI_IMC_SYMB_STROKE_WILDCARD,     /* MMI_IMC_SYMB_KEY_6 */
    0,                                /* MMI_IMC_SYMB_KEY_7 */
    0,                                /* MMI_IMC_SYMB_KEY_8 */
    0,                                /* MMI_IMC_SYMB_KEY_9 */
    0,                                /* MMI_IMC_SYMB_KEY_STAR */
    0                                 /* MMI_IMC_SYMB_KEY_POUND */
};

#endif /* __T9_CHINESE */

#ifdef __T9_CHINESE

/* Symbol code mapping, for query */
static const ET9U8  g_t9_codes_tone[MMI_IMC_SYMB_TONE_MAX - MMI_IMC_SYMB_TONE_BASE] =
{
    0,           /* MMI_IMC_SYMB_TONE_NONE */
    ET9CPTONE1, /* MMI_IMC_SYMB_TONE_1 */
    ET9CPTONE2, /* MMI_IMC_SYMB_TONE_2 */
    ET9CPTONE3, /* MMI_IMC_SYMB_TONE_3 */
    ET9CPTONE4, /* MMI_IMC_SYMB_TONE_4 */
    ET9CPTONE5  /* MMI_IMC_SYMB_TONE_5 */
};



static const ET9U8  g_t9_codes_stroke[MMI_IMC_SYMB_STROKE_MAX - MMI_IMC_SYMB_STROKE_BASE] =
{
ET9CPgKEYAMBIG6,        /* MMI_IMC_SYMB_STROKE_WILDCARD, */                                        
ET9CPgKEYAMBIG2,        /* MMI_IMC_SYMB_STROKE_DOWN, */                                            
ET9CPgKEYAMBIG4,        /* MMI_IMC_SYMB_STROKE_DOT, */                                             
    0,                  /* MMI_IMC_SYMB_STROKE_CURVED_HOOK, */
ET9CPgKEYAMBIG1,        /* MMI_IMC_SYMB_STROKE_OVER, */                                            
ET9CPgKEYAMBIG5,        /* MMI_IMC_SYMB_STROKE_OVER_DOWN, */                                       
    0,                  /* MMI_IMC_SYMB_STROKE_DOWN_OVER, */
ET9CPgKEYAMBIG3,        /* MMI_IMC_SYMB_STROKE_LEFT, */                                            
    0,                  /* MMI_IMC_SYMB_STROKE_OVER_DOWN_OVER, */
    0,                  /* MMI_IMC_SYMB_STROKE_MORE, */
    0,                  /* MMI_IMC_SYMB_STROKE_TURN, */
    0,                  /* MMI_IMC_SYMB_STROKE_DOT_OR_LEFT, */
};

static const UI_character_type  g_t9_unicodes_stroke[MMI_IMC_SYMB_STROKE_MAX - MMI_IMC_SYMB_STROKE_BASE] =
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


#endif /* #ifdef __T9_CHINESE */

#ifdef __MMI_T9_SM_CHINESE__

/* T9 use pinyin unicode (a-z) to query, not internal symbol code */
static const ET9U8  g_t9_codes_pinyin[MMI_IMC_SYMB_PY_MAX - MMI_IMC_SYMB_PY_BASE] = 
{
    'a',  /* MMI_IMC_SYMB_PY_A */
    'b',  /* MMI_IMC_SYMB_PY_B */
    'c',  /* MMI_IMC_SYMB_PY_C */

    'd',  /* MMI_IMC_SYMB_PY_D */
    'e',  /* MMI_IMC_SYMB_PY_E */
    'f',  /* MMI_IMC_SYMB_PY_F */

    'g',  /* MMI_IMC_SYMB_PY_G */
    'h',  /* MMI_IMC_SYMB_PY_H */
    'i',  /* MMI_IMC_SYMB_PY_I */

    'j',  /* MMI_IMC_SYMB_PY_J */
    'k',  /* MMI_IMC_SYMB_PY_K */
    'l',  /* MMI_IMC_SYMB_PY_L */

    'm',  /* MMI_IMC_SYMB_PY_M */
    'n',  /* MMI_IMC_SYMB_PY_N */
    'o',  /* MMI_IMC_SYMB_PY_O */

    'p',  /* MMI_IMC_SYMB_PY_P */
    'q',  /* MMI_IMC_SYMB_PY_Q */
    'r',  /* MMI_IMC_SYMB_PY_R */
    's',  /* MMI_IMC_SYMB_PY_S */

    't',  /* MMI_IMC_SYMB_PY_T */
    'u',  /* MMI_IMC_SYMB_PY_U */
    'v',  /* MMI_IMC_SYMB_PY_V */

    'w',  /* MMI_IMC_SYMB_PY_W */
    'x',  /* MMI_IMC_SYMB_PY_X */
    'y',  /* MMI_IMC_SYMB_PY_Y */
    'z'   /* MMI_IMC_SYMB_PY_Z */
};
#endif /* #ifdef __MMI_T9_SM_CHINESE__ */

#ifdef __MMI_T9_TR_CHINESE__

static const UI_character_type  g_t9_unicodes_zhuyin[MMI_IMC_SYMB_ZY_MAX - MMI_IMC_SYMB_ZY_B] =
{
    0x3105, /*MMI_IMC_SYMB_ZY_B*/
    0x3106, /*MMI_IMC_SYMB_ZY_P*/
    0x3107, /*MMI_IMC_SYMB_ZY_M*/
    0x3108, /*MMI_IMC_SYMB_ZY_F*/
    0x3109, /*MMI_IMC_SYMB_ZY_D*/
    0x310A, /*MMI_IMC_SYMB_ZY_T*/
    0x310B, /*MMI_IMC_SYMB_ZY_N*/
    0x310C, /*MMI_IMC_SYMB_ZY_L*/
    0x310D, /*MMI_IMC_SYMB_ZY_G*/
    0x310E, /*MMI_IMC_SYMB_ZY_K*/
    0x310F, /*MMI_IMC_SYMB_ZY_H*/
    0x3110, /*MMI_IMC_SYMB_ZY_J*/
    0x3111, /*MMI_IMC_SYMB_ZY_Q*/
    0x3112, /*MMI_IMC_SYMB_ZY_X*/
    0x3113, /*MMI_IMC_SYMB_ZY_ZH*/
    0x3114, /*MMI_IMC_SYMB_ZY_CH*/
    0x3115, /*MMI_IMC_SYMB_ZY_SH*/
    0x3116, /*MMI_IMC_SYMB_ZY_R*/
    0x3117, /*MMI_IMC_SYMB_ZY_Z*/
    0x3118, /*MMI_IMC_SYMB_ZY_C*/
    0x3119, /*MMI_IMC_SYMB_ZY_S*/
    0x311A, /*MMI_IMC_SYMB_ZY_A*/
    0x311B, /*MMI_IMC_SYMB_ZY_O*/
    0x311C, /*MMI_IMC_SYMB_ZY_E*/
    0x311D, /*MMI_IMC_SYMB_ZY_EH*/
    0x311E, /*MMI_IMC_SYMB_ZY_AI*/
    0x311F, /*MMI_IMC_SYMB_ZY_EI*/
    0x3120, /*MMI_IMC_SYMB_ZY_AU*/
    0x3121, /*MMI_IMC_SYMB_ZY_OU*/
    0x3122, /*MMI_IMC_SYMB_ZY_AN*/
    0x3123, /*MMI_IMC_SYMB_ZY_EN*/
    0x3124, /*MMI_IMC_SYMB_ZY_ANG*/
    0x3125, /*MMI_IMC_SYMB_ZY_ENG*/
    0x3126, /*MMI_IMC_SYMB_ZY_ER*/
    0x3127, /*MMI_IMC_SYMB_ZY_I*/
    0x3128, /*MMI_IMC_SYMB_ZY_U*/
    0x3129  /*MMI_IMC_SYMB_ZY_IU*/
};

static const ET9U8 g_t9_codes_zhuyin[MMI_IMC_SYMB_ZY_MAX - MMI_IMC_SYMB_ZY_B] = 
{
    'b', /*MMI_IMC_SYMB_ZY_B*/
    'p', /*MMI_IMC_SYMB_ZY_P*/
    'm', /*MMI_IMC_SYMB_ZY_M*/
    'f', /*MMI_IMC_SYMB_ZY_F*/
    'd', /*MMI_IMC_SYMB_ZY_D*/
    't', /*MMI_IMC_SYMB_ZY_T*/
    'n', /*MMI_IMC_SYMB_ZY_N*/
    'l', /*MMI_IMC_SYMB_ZY_L*/
    'g', /*MMI_IMC_SYMB_ZY_G*/
    'k', /*MMI_IMC_SYMB_ZY_K*/
    'h', /*MMI_IMC_SYMB_ZY_H*/
    'j', /*MMI_IMC_SYMB_ZY_J*/
    'q', /*MMI_IMC_SYMB_ZY_Q*/
    'x', /*MMI_IMC_SYMB_ZY_X*/
    0xdf,/*MMI_IMC_SYMB_ZY_ZH*/
    0xe7,/*MMI_IMC_SYMB_ZY_CH*/
    0x9a,/*MMI_IMC_SYMB_ZY_SH*/
    'r', /*MMI_IMC_SYMB_ZY_R*/
    'z', /*MMI_IMC_SYMB_ZY_Z*/
    'c', /*MMI_IMC_SYMB_ZY_C*/
    's', /*MMI_IMC_SYMB_ZY_S*/
    'a', /*MMI_IMC_SYMB_ZY_A*/
    'o', /*MMI_IMC_SYMB_ZY_O*/
    'e', /*MMI_IMC_SYMB_ZY_E*/
    0xe9,/*MMI_IMC_SYMB_ZY_EH*/
    0xe4,/*MMI_IMC_SYMB_ZY_AI*/
    0xf6,/*MMI_IMC_SYMB_ZY_EI*/
    0xe5,/*MMI_IMC_SYMB_ZY_AU*/
    0xfd,/*MMI_IMC_SYMB_ZY_OU*/
    0xe3,/*MMI_IMC_SYMB_ZY_AN*/
    0xf5,/*MMI_IMC_SYMB_ZY_EN*/
    0xe2,/*MMI_IMC_SYMB_ZY_ANG*/
    0xf4,/*MMI_IMC_SYMB_ZY_ENG*/
    0xf8,/*MMI_IMC_SYMB_ZY_ER*/
    'i', /*MMI_IMC_SYMB_ZY_I*/
    'u', /*MMI_IMC_SYMB_ZY_U*/
    0xfc /*MMI_IMC_SYMB_ZY_IU*/
};
#endif /* #ifdef __MMI_T9_TR_CHINESE__ */


typedef struct
{
UI_character_type   unicode_value;
ET9U8                   key_value;
}key_to_character_map;

static const key_to_character_map g_t9_code_map[]={
    
{0x3107,10},      
{0x3119,23},      
{0x3112,21},      
{0x310E,12},                
{0x310D,2},               
{0x3111,13},            
{0x3115,14},               
{0x3118,15} ,             
{0x311B,7},          
{0x311E,7},               
{0x3128,16},              
{0x311C,17},               
{0x3120,18},          
{0x3124,18},               
{0x311D,25},               
{0x3129,24},                
{0x311F,8},          
{0x3122,8},               
{0x3123,9},          
{0x3126,9},               
{0x3105,0},          
{0x3106,0},               
{0x3110,3},                
{0x310B,11},               
{0x3113,4},          
{0x3114,4},               
{0x3127,6},          
{0x311A,6},               
{0x3116,22},            
{0x3109,1},          
{0x310A,1},               
{0x310F,20},               
{0x3117,5},               
{0x3108,19},          
{0x310C,19}

};


static const key_to_character_map g_t9_thai_code_map[]={

{0x0E46,0 },
{0x0E44,1 },
{0x0E33,2 },
{0x0E43,2 },
{0x0E1E,3 },
{0x0E30,4 },
{0x0E31,5 },
{0x0E38,5 },
{0x0E35,6 },
{0x0E36,6 },
{0x0E23,7 },
{0x0E19,8 },
{0x0E15,8 },
{0x0E22,9 },
{0x0E0A,9 },
{0x0E03,9 },
{0x0E1F,10},
{0x0E2B,11},
{0x0E01,12},
{0x0E16,12},
{0x0E20,12},
{0x0E14,13},
{0x0E04,13},
{0x0E40,14},
{0x0E49,15},
{0x0E48,16},
{0x0E32,17},
{0x0E45,17},
{0x0E27,17},
{0x0E2A,18},
{0x0E25,18},
{0x0E07,18},
{0x0E1C,19},
{0x0E1d,19},
{0x0E1B,20},
{0x0E1A,20},
{0x0E41,21},
{0x0E2D,22},
{0x0E34,23},
{0x0E37,24},
{0x0E17,25},
{0x0E02,25},
{0x0E08,25},
{0x0e21,26},
{0x0E3f,0 },
{0x0E26,1 },
{0x0E0E,2 },
{0x0E11,3 },
{0x0E18,4 },
{0x0E4D,5 },
{0x0E39,5 },
{0x0E4A,6 },
{0x0E13,7 },
{0x0E2F,8 },
{0x0E0D,9 },
{0x0E24,10},
{0x0E06,11},
{0x0E0F,12},
{0x0E42,13},
{0x0E0C,14},
{0x0E47,15},
{0x0E4B,16},
{0x0E29,17},
{0x0E28,18},
{0x0E0B,18},
{0x0E05,19},
{0x0E10,20},
{0x0E09,21},
{0x0E2E,22},
{0x0E3A,23},
{0x0E4C,24},
{0x0E12,25},
{0x0e2C,26} 


};



typedef struct
{
ime_mode_attr_enum  caps_state;
ET9U16                   page_num;
}caps_state_to_page_num;


static const caps_state_to_page_num g_t9_state_page_map[]={

#if defined (__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
{GUI_VIRTUAL_KEYBOARD_THAI_LOWERCASE,1},
{GUI_VIRTUAL_KEYBOARD_THAI,0},
#endif
{0,0},

};

typedef union T9CCAWFieldInfo_u
{
#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) 
   ET9CPLingInfo    CCFieldInfo;
#endif /* defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_SM_CHINESE__) */    
    ET9AWLingInfo  AWFieldInfo;
} T9CCAWFieldInfo;



typedef struct
{
    mmi_imm_input_mode_enum         input_mode;
    const ET9U8                         *key_map_ptr;
    const ET9U8       *qwerty_map_ptr;
    mmi_ime_t9_init_type_enum       init_type;
    ET9UINT                          nLdbNum;
    U32                             required_keys;
    U32                             symbol_keys;
    mmi_ime_get_spellings_funcptr   get_spell_funcptr;
    mmi_ime_get_associates_funcptr  get_assoc_funcptr;
    mmi_ime_get_candidates_funcptr  get_cand_funcptr;
}  mmi_ime_t9_mode_info_struct, * mmi_ime_t9_mode_info_struct_p;

typedef struct
{
    ET9SYMB        text_buff[MMI_IME_T9_MAX_TEXT_BUFFSIZE + 1];
    ET9U16           aux_buff[MMI_IME_T9_MAX_TEXT_BUFFSIZE + 1];
    T9CCAWFieldInfo     field_info;

#ifdef __MMI_T9_MULTITAP__
    ET9SYMB              multitap_page[MMI_MULTITAP_T9_PAGE_BUFFSIZE];
    UI_character_type   multitap_string[MMI_MULTITAP_T9_PAGE_BUFFSIZE];
#endif /* __MMI_T9_MULTITAP__ */
    
#if defined(__MMI_IME_USER_DATABASE__)
    U16                udb_data[MMI_IME_T9_UDB_SIZE / 2];
    U16                cdb_data[MMI_IME_T9_CDB_SIZE / 2];
#endif

#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
    UI_character_type   ass_alpha_cand[MMI_IME_T9_MAX_PREDICTION_WORD_NUM][MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
    S32                 ass_alpha_count;
#endif
    U32 key_type ;
}   mmi_ime_t9_data_struct, *mmi_ime_t9_data_struct_p;


typedef struct
{
    ET9AWLingCmnInfo    sLingCmnInfo;
    ET9WordSymbInfo     sWordSymbInfo;
    ET9KDBInfo          sKdbInfo;
    ET9AWPrivWordInfo   pSelList[SEL_LIST_SIZE];
    mmi_ime_t9_data_struct data;


    ET9U8               bTotWords;
    ET9U8               bActiveWordIndex;

    U32                 curr_keyboard_type;
    ET9BOOL             bActiveOTFM;
    ET9BOOL             bSupressSubstitutions;
    ET9U8               bLastKeyMT;
 INPUTMODE           eInputMode;

  /* data structure from T9 */
  MMI_BOOL        is_inited;
  const ET9U8 *key_map_ptr;       
    const ET9U8 *qwerty_map_ptr;
  mmi_ime_t9_mode_info_struct_p     t9_mode_info;
  mmi_imm_input_mode_enum     input_mode;
  mmi_ime_word_capital_state_enum  case_type;
    U32 first_upper;  
    U32 function_key_state;
    U32 function_flag ;
    U16 active_qwerty_sequence[32];
    U16 curr_qwerty_key;
  MMI_BOOL is_multitap;

#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)
    ET9U8    bActiveSpell;   
    ET9U8 pbSpellIndex[40];  /* the 0 based spell index in core */// cpimeapi.h,T9CPIME_MAX_NUM_SPELLs
     ET9CPSpell sActiveSpell;
#endif
} mmi_ime_xt9_word_engine_struct;



/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef U8     (*mmi_ime_symb_conv_funcptr)( U8 symb_value, U8 *symb_map );

/*****************************************************************************
 * Local Functions
 *****************************************************************************/
 
/* Utility functions */
static UI_character_type mmi_ime_t9_t9code_to_code(ET9U8 t9code, mmi_imm_input_mode_enum mode);

/* multitap functions */
#ifdef __T9_CHINESE
static U8  mmi_ime_t9_from_symb_to_t9key( U16 symb_key );
#endif

/* word functions */
//static ET9STATUS T9_handle_request( T9FieldInfo *field_info_ptr, T9Request *request_ptr );

static void  mmi_ime_t9_change_candidates_case(mmi_ime_query_result_struct_p result_str);

#ifdef __T9_CHINESE
static MMI_BOOL mmi_ime_t9_init_stroke_chn( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr );
static MMI_BOOL mmi_ime_t9_init_phonetic_chn( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr );
#endif /* __T9_CHINESE */

static MMI_BOOL mmi_ime_t9_init_alphabetic( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr );
static MMI_BOOL mmi_ime_t9_init_number( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr );

static mmi_ime_t9_mode_info_struct_p  mmi_ime_t9_get_mode_info( mmi_imm_input_mode_enum input_mode );

/* Query functions */

static void mmi_ime_t9_get_candidates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );

static void mmi_ime_t9_get_associates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );

#if defined  __T9_CHINESE
static void     mmi_ime_t9_get_spellings_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
static void     mmi_ime_t9_get_candidates_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
static void     mmi_ime_t9_get_associates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
static void     mmi_ime_t9_get_candidates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr);
#endif /* #if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */

/* Simplified Chinese functions */
#if defined(__MMI_T9_SM_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
static void mmi_ime_t9_get_spellings_pinyin_multitap( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_T9_SMART_PHONETIC_INPUT__)
static void mmi_ime_t9_get_spellings_pinyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
static void mmi_ime_t9_get_candidates_pinyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_T9_SMART_PHONETIC_INPUT__) */

static void mmi_ime_t9_get_candidates_pinyin( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );

#endif /* #if defined(__MMI_T9_SM_CHINESE__) */

/* Traditional Chinese functions */
#if defined(__MMI_T9_TR_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
static void mmi_ime_t9_get_spellings_zhuyin_multitap( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__)
static void mmi_ime_t9_get_spellings_zhuyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_T9_SMART_PHONETIC_INPUT__) */

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
#if defined(__MMI_MIXED_LANG_SUPPORT__)
static U32 mmi_ime_t9_get_lang_ldb(mmi_imm_support_writing_lang_enum writing_lang);
#endif

INPUTMODE mmi_ime_xt9_get_vk_type();

static ET9U8  mmi_ime_t9_from_symb_to_12key( U16 symb_key );

U16 mmi_ime_convert_char_to_keyno(U16 key_char);


/*---------------------------------------------------------------------------*/
/**
 * Handle core input module requests.
 *
 * @param pKdbInfo             pointer to keyboard information structure
 * @param pRequest             request data
 *
 * @return ET9STATUS_NONE on success, otherwise return ET9 error code
 */

static ET9STATUS ET9Handle_KDB_Request(ET9KDBInfo      * const pKdbInfo,
                                       ET9WordSymbInfo * const pWordSymbInfo,
                                       ET9KDB_Request  * const pRequest)
{

    return ET9STATUS_NONE;
}

/*****************************************************************************
 * Local variables
 *****************************************************************************/





static const ET9U8 pcMapKeyHQR[] =
{
  10,23,21,12,2,13,14,15,7,16,17,18,25,24,8,9,0,3,11,4,6,22,1,20,5,19,1    
};

static const ET9U8 keymapchar[] =
{
    97, 98, 99, 
    100,101,102,
    103,104,105,
    106,107,108,
    109,110,111,
    112,113,114,
    115,116,117,
    118,119,120,
    121,122
};

static const ET9U8 pcMapKeyHPD[] =
{
    9, 0, 1, 2, 3, 4, 5, 6, 7, 8
};

static const ET9U8 pcMapKeythaiHPD[] =
{
    9, 0, 1, 2, 3, 4, 5, 6, 7, 8,10,11
};

static const mmi_ime_t9_mode_info_struct  g_mode_infos[] = 
{

#if defined(__MMI_T9_MULTITAP__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ENGLISH__)*/


#if defined(__MMI_T9_ENGLISH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_ABC,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_ENGLISH__) */

#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_THAI__)
    {   
        IMM_INPUT_MODE_MULTITAP_THAI,
        pcMapKeythaiHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDThai,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_THAI__)*/

#if defined(__MMI_T9_THAI__)
    {   
        IMM_INPUT_MODE_SMART_THAI,
        pcMapKeythaiHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDThai,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_KEYS,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_THAI__) */

#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_VIETNAMESE__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDVietnamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDVietnamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_VIETNAMESE__)*/

#if defined(__MMI_T9_VIETNAMESE__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDVietnamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDVietnamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_VIETNAMESE__) */

#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ITALIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDItalian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDItalian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ITALIAN__)*/

#if defined(__MMI_T9_ITALIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_ITALIAN,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDItalian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDItalian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_ITALIAN__) */

#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_INDONESIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDIndonesian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDIndonesian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_INDONESIAN__)*/

#if defined(__MMI_T9_INDONESIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDIndonesian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        ET9PLIDIndonesian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_INDONESIAN__) */

#if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
    {
        IMM_INPUT_MODE_SM_MULTITAP_PINYIN,
        pcMapKeyHPD, //g_t9_keys_chinese
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        ET9PLIDChineseSimplified,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_1),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_1) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_pinyin_multitap,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_pinyin
    },
    {
        IMM_INPUT_MODE_QUICK_SEARCH_PINYIN,
         pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        ET9PLIDChineseSimplified,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_1),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_1) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_pinyin_multitap,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_pinyin
    },
#endif /* #if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)
    {
        IMM_INPUT_MODE_SM_PINYIN,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        ET9PLIDChineseSimplified,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_1),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_1) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_pinyin_smart,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_pinyin
    },
#endif /* #if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__) */

#if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
    {   
        IMM_INPUT_MODE_TR_MULTITAP_BOPOMO,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        ET9PLIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS,
    #if defined(__MMI_T9_DEFAULT_KEY_DEFINITION__)
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_0),
    #else
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
    #endif
        mmi_ime_t9_get_spellings_zhuyin_multitap,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_zhuyin
    },
    {   
        IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        ET9PLIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS,
#if defined(__MMI_T9_DEFAULT_KEY_DEFINITION__)
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_0),
#else
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
#endif
        mmi_ime_t9_get_spellings_zhuyin_multitap,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_zhuyin
    },
#endif /* #if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__)
    {   
        IMM_INPUT_MODE_TR_BOPOMO,
        pcMapKeyHPD,
        pcMapKeyHQR,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        ET9PLIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS,
#if defined(__MMI_T9_DEFAULT_KEY_DEFINITION__)
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_0),
#else
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
#endif
        mmi_ime_t9_get_spellings_zhuyin_smart,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_zhuyin
    },
#endif /* #if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__) */   

  #if defined(__MMI_T9_TR_CHINESE__)
    {
        IMM_INPUT_MODE_TR_STROKE, 
        g_t9_keys_chinese,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_STROKE,
        ET9PLIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_stroke,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_stroke
    },
    {
        IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE,
        g_t9_keys_chinese,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_STROKE,
        ET9PLIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_stroke,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_stroke
    },
#endif /* #if defined(__MMI_T9_TR_CHINESE__) */

  #if defined(__MMI_T9_SM_CHINESE__)
    {
        IMM_INPUT_MODE_SM_STROKE,
        g_t9_keys_chinese,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_STROKE,
        ET9PLIDChineseSimplified,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_stroke,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_stroke
    },
    {
        IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE,
        g_t9_keys_chinese,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_STROKE,
        ET9PLIDChineseSimplified,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_stroke,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_stroke
    },
#endif /* #if defined(__MMI_T9_SM_CHINESE__) */

    {
        IMM_INPUT_MODE_MAX_NUM,
        NULL,
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

mmi_ime_xt9_word_engine_struct     g_engine;

#if defined(__MMI_MIXED_LANG_SUPPORT__)
mmi_ime_t9_writing_lang_ldb_map_struct  writing_lang_ldb_map[]=
{
#if defined(__MMI_T9_ENGLISH__)
    {IME_WRITING_LANG_ABC,ET9PLIDEnglish},
#endif

  {IME_WRITING_LANG_NONE, NULL}
};
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */
/*****************************************************************************
 * Local variables
 *****************************************************************************/

ET9U8 mmi_ime_t9_from_symb_to_char(U16 );


/*****************************************************************************
 * FUNCTION
 *  ime_init_engine
 * DESCRIPTION
 * Initializes input engine
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
    
    if ( g_engine.is_inited )
        return MMI_TRUE;

    memset( &g_engine, 0x0, sizeof(mmi_ime_xt9_word_engine_struct) );    
    
    g_engine.is_inited = MMI_TRUE;
    g_engine.input_mode = IMM_INPUT_MODE_MAX_NUM;
    

#if defined(__MMI_IME_USER_DATABASE__)
    g_engine.is_inited = mmi_ime_word_load_user_database();
#endif
    
#ifdef __MMI_T9_MULTITAP__
  //  g_engine.is_inited = mmi_ime_multitap_init();
  //  MMI_ASSERT(g_engine.is_inited);
#endif
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
  g_engine.eInputMode = IME_XT9_HQD;
#else
  g_engine.eInputMode = IME_XT9_HPD;
#endif
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

    memset( &g_engine, 0x0, sizeof(mmi_ime_xt9_word_engine_struct) );
    g_engine.input_mode = IMM_INPUT_MODE_MAX_NUM;
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
    g_engine.t9_mode_info = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_change_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_change_mode(const sIMEModeDetails * mode_details_ptr, U32 reserved )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    MMI_BOOL                ret_val = MMI_FALSE;
    mmi_ime_t9_mode_info_struct_p   mode_info_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if ( g_engine.is_inited == MMI_FALSE )
        return MMI_FALSE;

    else
    {

        memset(&g_engine.sWordSymbInfo, 0x0, sizeof(ET9WordSymbInfo)); 
        g_engine.is_inited = MMI_TRUE; 
        g_engine.input_mode = IMM_INPUT_MODE_MAX_NUM;
    }

    if ( mode_details_ptr->imm_mode_id >= IMM_INPUT_MODE_MAX_NUM )
        return MMI_FALSE;
    
    mode_info_ptr = mmi_ime_t9_get_mode_info( mode_details_ptr->imm_mode_id );
    
    g_engine.t9_mode_info = NULL;
    
    if ( NULL == mode_info_ptr )
        return MMI_FALSE;

    g_engine.t9_mode_info = mode_info_ptr;
    
    switch ( mode_info_ptr->init_type )
    { 
        case MMI_IME_T9_INIT_TYPE_ALPHABETIC:
            ret_val = mmi_ime_t9_init_alphabetic(mode_info_ptr, (sIMEModeDetails *)mode_details_ptr);
            break;
#if defined __T9_CHINESE       
    case MMI_IME_T9_INIT_TYPE_PHONETIC:
        ret_val = mmi_ime_t9_init_phonetic_chn(mode_info_ptr, (sIMEModeDetails *)mode_details_ptr);
        break;

    case MMI_IME_T9_INIT_TYPE_STROKE:
        ret_val = mmi_ime_t9_init_stroke_chn(mode_info_ptr, (sIMEModeDetails *)mode_details_ptr);
        break;
#endif        
    case MMI_IME_T9_INIT_TYPE_DIRECT:
        ret_val = mmi_ime_t9_init_number(mode_info_ptr, (sIMEModeDetails *)mode_details_ptr);
        break;
        default:
            ret_val = MMI_FALSE;
            break;
    }


    if ( (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE) )
    {
        g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_UPPER;
    }
    else if ( mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE )
    {
        g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_LOWER;
    }
    else if ( mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE )
    {
        g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
    }
    else
    {
        g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_NONE;
    }

    
    if ( ret_val == MMI_FALSE )
    {
        return MMI_FALSE;
    }

    g_engine.key_map_ptr   = mode_info_ptr->key_map_ptr;
    g_engine.qwerty_map_ptr   = mode_info_ptr->qwerty_map_ptr;
    g_engine.input_mode     = mode_details_ptr->imm_mode_id;
    
    return MMI_TRUE;
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

    if (g_engine.t9_mode_info)
    {
        if ( NULL != g_engine.t9_mode_info->get_spell_funcptr )
        {
            g_engine.t9_mode_info->get_spell_funcptr( param_ptr, result_ptr );
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

    if (g_engine.t9_mode_info)
    {
        if ( NULL != g_engine.t9_mode_info->get_assoc_funcptr )
        {
            g_engine.t9_mode_info->get_assoc_funcptr( param_ptr, result_ptr );
        }
    }
    
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

    if (g_engine.t9_mode_info)
    {
        if ( NULL != g_engine.t9_mode_info->get_cand_funcptr )
        {
            g_engine.t9_mode_info->get_cand_funcptr( param_ptr, result_ptr );
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
    switch(symbol)
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
        /* Klocwork */
        MMI_ASSERT(symbol <  MMI_IMC_SYMB_STROKE_MAX );
        return g_t9_unicodes_stroke[symbol  - MMI_IMC_SYMB_STROKE_BASE];
    }
#endif /* defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */
#if defined(__MMI_T9_SM_CHINESE__)
    else if (MMI_IMC_IS_SYMB_PY(symbol))
    {
         MMI_ASSERT(symbol <  MMI_IMC_SYMB_PY_MAX );
        return g_t9_codes_pinyin[symbol  - MMI_IMC_SYMB_PY_BASE];
    }
#endif /* #if defined(__MMI_T9_SM_CHINESE__) */
#if defined(__MMI_T9_TR_CHINESE__)
    else if (MMI_IMC_IS_SYMB_ZY(symbol))
    {
        MMI_ASSERT(symbol <  MMI_IMC_SYMB_ZY_MAX );
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
        else if (code >= 'A' && code <= 'Z')
        {
            return code - 'A' + MMI_IMC_SYMB_PY_A;
        }
        else 
#endif /* __MMI_T9_SM_CHINESE__ */
#ifdef __MMI_T9_TR_CHINESE__
        if ( code >= 0x3105 && code <= 0x3129)
        {
            return code - 0x3105 + MMI_IMC_SYMB_ZY_B ;
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
 *  mmi_ime_word_set_context
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void  mmi_ime_word_set_context( U8 context )
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_valid_key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL  mmi_ime_word_is_valid_key( mmi_imm_input_mode_enum input_mode, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_t9_mode_info_struct_p  mode_info_p;
    U32 required_key;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_info_p = mmi_ime_t9_get_mode_info(input_mode);

    if (mode_info_p == NULL)
        return MMI_FALSE;

    required_key = mode_info_p->required_keys;
    
    switch(key_code)
    {
    case KEY_LSK:
    case KEY_RSK:
    case KEY_CSK:
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
 * RETURNS
 *****************************************************************************/
MMI_BOOL  mmi_ime_word_is_symbol_key( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined __MMI_XT9__
    if(key_code == MMI_IMC_KEY_SYM_QWERTY)
        return MMI_TRUE;
#endif

    
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
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_engine_get_char_info(UI_character_type code, UI_string_type info_buffer, S32 buffer_size, mmi_imm_input_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_t9_mode_info_struct_p   mode_info_ptr;
    sIMEModeDetails * mode_details_ptr;
    MMI_BOOL ret_val = MMI_FALSE;
    UI_character_type temp_string[2];
    ET9STATUS    status;
    S32 i=0;
	#ifdef __T9_CHINESE
  ET9CPSpell temp_buffer;
	#endif
  ET9U8 pbBuf[20]; // need to change this 20 , manik
    ET9U8 pbLen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_details_ptr = (sIMEModeDetails *)mmi_imm_get_input_mode_array_item(mode);

    MMI_ASSERT(mode_details_ptr != NULL);
    
    switch(mode)
    {
    case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:
    case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:
    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:
    case IMM_INPUT_MODE_TR_BOPOMO:
    case IMM_INPUT_MODE_SM_PINYIN:
    case IMM_INPUT_MODE_SM_STROKE:
    case IMM_INPUT_MODE_TR_STROKE:
    case IMM_INPUT_MODE_HK_STROKE:
        mode_info_ptr = mmi_ime_t9_get_mode_info(mode);
        break;

    default:
        return MMI_FALSE;
        break;
    }

    MMI_ASSERT(mode_info_ptr != NULL);
    
    switch ( mode_info_ptr->init_type )
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

    temp_string[0] = code;
    temp_string[1] = 0;
        
    switch(mode)
    {
#ifdef __T9_CHINESE
    case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:
    case IMM_INPUT_MODE_TR_BOPOMO:
    case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:
    case IMM_INPUT_MODE_SM_PINYIN:

    status = ET9CPGetCharSpell(&g_engine.data.field_info.CCFieldInfo,(ET9SYMB) code,0, 0, &temp_buffer);
/* MANIK TODO:*/
    if (status == ET9STATUS_NONE)
    {
    i=0;
      while (i < temp_buffer.bLen - 1)
      {
        info_buffer[i] = mmi_ime_t9_t9code_to_code((ET9U8)temp_buffer.pSymbs[i], mode);
        i++;
      }
      
      info_buffer[i] = 0;
    }
        break;
        
    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:
    case IMM_INPUT_MODE_SM_STROKE:
    case IMM_INPUT_MODE_TR_STROKE:
    case IMM_INPUT_MODE_HK_STROKE:
/* Manik toDO */
       status = ET9CPGetCharStrokes(&g_engine.data.field_info.CCFieldInfo,(ET9SYMB) code, pbBuf, &pbLen,0);

        
    if (status == ET9STATUS_NONE)
    {
    i=0;
      while (i < pbLen - 1)
      {
        info_buffer[i] = mmi_ime_t9_t9code_to_code((ET9U8)pbBuf[i], mode);
        i++;
      }
      
      info_buffer[i] = 0;
    }
    
        break;
#endif
    default:
        return MMI_FALSE;
        break;
    }

  mode_details_ptr = (sIMEModeDetails *)mmi_imm_get_input_mode_array_item(g_engine.input_mode);

  if (mode_details_ptr)
    {
        /* Resume current input mode */
        mmi_ime_word_change_mode(mode_details_ptr, 0); 
  }

    if (status == ET9STATUS_NONE)
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
 *  mmi_ime_word_change_word_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void   mmi_ime_word_change_word_case(mmi_ime_word_capital_state_enum capital_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_engine.case_type = capital_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_map_char_to_symbol
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_imc_symbol_key_enum mmi_ime_word_map_char_to_symbol(mmi_imm_input_mode_enum input_mode, UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails      *mode_info_ptr = NULL;
    mmi_ime_t9_mode_info_struct_p   t9_mode_info_ptr = NULL;
    ET9STATUS sStatus=ET9STATUS_NONE;
    ET9U8 t9_sym_key;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_info_ptr = mmi_imm_get_input_mode_array_item(input_mode);

    if ( NULL == mode_info_ptr )
        return MMI_IMC_SYMB_KEY_INVALID;

    t9_mode_info_ptr = mmi_ime_t9_get_mode_info( mode_info_ptr->imm_mode_id );

    if ( NULL == t9_mode_info_ptr )
        return MMI_IMC_SYMB_KEY_INVALID;

    if ( t9_mode_info_ptr->init_type != MMI_IME_T9_INIT_TYPE_ALPHABETIC )
        return MMI_IMC_SYMB_KEY_INVALID;
/*
    if (t9_mode_info_ptr->nLdbNum != g_engine.t9_mode_info->nLdbNum)
    {
        
    sStatus = ET9AWLdbSetLanguage(&g_engine.data.field_info.AWFieldInfo,t9_mode_info_ptr->nLdbNum, ET9PLIDNone);
    
        if (sStatus != ET9STATUS_NONE)
        {
            return MMI_IMC_SYMB_KEY_INVALID;
        }
    }

    sStatus = T9GetKeyForSym(&(g_engine.data.field_info.AWFieldInfo.G), (T9SYMB)char_code, &t9_sym_key);

    if (t9_mode_info_ptr->nLdbNum != g_engine.t9_mode_info->nLdbNum)
    {
        sStatus = T9AWSetLanguage( &(g_engine.data.field_info.AWFieldInfo), g_engine.t9_mode_info->nLdbNum, &(g_engine.data.field_info.AWFieldInfo.G), NULL );

        if (sStatus != T9STATNONE)
        {
            return MMI_IMC_SYMB_KEY_INVALID;
        }
    }*/
/* Manik*/
    if ((sStatus != T9STATNONE ))// && (sStatus != ET9STATNOWRD))
    {
        return MMI_IMC_SYMB_KEY_INVALID;
    }

	
#ifdef __T9_CHINESE
    if (t9_sym_key >= ET9CPgKEYAMBIG1 && t9_sym_key <= ET9CPgKEYAMBIG9)
    {
        return t9_sym_key - ET9CPgKEYAMBIG1 + MMI_IMC_SYMB_KEY_1;
    }
    else if (t9_sym_key == ET9CPgKEYAMBIGA)
    {
        return MMI_IMC_SYMB_KEY_0;
    }
	else if (t9_sym_key == ET9CPgKEYAMBIGB)
    {
        return MMI_IMC_SYMB_KEY_STAR;
    }
	else if (t9_sym_key == ET9CPgKEYAMBIGC)
    {
        return MMI_IMC_SYMB_KEY_POUND;
    }
    else
    {
        return MMI_IMC_SYMB_KEY_INVALID;
    }
#else 
     return MMI_IMC_SYMB_KEY_INVALID;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_t9code_to_code
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static UI_character_type mmi_ime_t9_t9code_to_code(ET9U8 t9code, mmi_imm_input_mode_enum mode)
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
    case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
    case IMM_INPUT_MODE_SM_PINYIN:
    case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:
        return (UI_character_type)t9code;
        break;

#ifdef __MMI_T9_TR_CHINESE__

    case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
    case IMM_INPUT_MODE_TR_BOPOMO:
  case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:
        
        while(i < MMI_IMC_SYMB_ZY_MAX - MMI_IMC_SYMB_ZY_BASE)
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
    case IMM_INPUT_MODE_TR_STROKE:
    case IMM_INPUT_MODE_HK_STROKE:
    case IMM_INPUT_MODE_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:

        while(i < MMI_IMC_SYMB_STROKE_MAX - MMI_IMC_SYMB_STROKE_BASE)
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
 * RETURNS
 *****************************************************************************/
static mmi_ime_t9_mode_info_struct_p   mmi_ime_t9_get_mode_info(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U8  i;
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    const sIMEModeDetails * mode_details_ptr;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( input_mode >= IMM_INPUT_MODE_MAX_NUM )
        return NULL;

#if defined(__MMI_SMART_FIRST_UPPERCASE__)

    mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);
    
    if (!mode_details_ptr)
    {
        return NULL;
    }

    if ((mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
        && (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART))
    {
        mode_details_ptr = mmi_imm_get_corresponding_smart_lower_case_mode(input_mode);

        if (mode_details_ptr)
        {
            input_mode = mode_details_ptr->imm_mode_id;
        }
        else
        {
            return NULL;
        }
    }

#endif /* defined(__MMI_SMART_FIRST_UPPERCASE__) */

    for ( i = 0; g_mode_infos[i].input_mode != IMM_INPUT_MODE_MAX_NUM; ++i )
    {
        if ( g_mode_infos[i].input_mode == input_mode )
            return (mmi_ime_t9_mode_info_struct_p)&g_mode_infos[i];
    }

    return NULL;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_init_number
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_number( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr)
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

#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_init_stroke_chn
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_stroke_chn( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr )
{

 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        ET9STATUS       status;
        ET9U16             kdbid;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
     status = ET9CPSysInit(&g_engine.data.field_info.CCFieldInfo, &g_engine.sWordSymbInfo, NULL);
    if (status)
    {
       ASSERT(0) ;
    }
    status = ET9CPLdbValidate(&g_engine.data.field_info.CCFieldInfo,t9_mode_info->nLdbNum,ET9CPReadLdbData);
    if (status)
    {
       ASSERT(0) ;
    }
    status =ET9CPLdbInit(&g_engine.data.field_info.CCFieldInfo,t9_mode_info->nLdbNum,ET9CPReadLdbData);
    if (status)
    {
       ASSERT(0) ;
    }



    kdbid =  ET9PLIDChinese|ET9SKIDPhonePadPinyin;

   /* intialize kdb */
    status = ET9KDB_Init(&g_engine.sKdbInfo,kdbid, 0, 0, 0, &ET9KDBReadData, &ET9Handle_KDB_Request, &g_engine);
        if (status) 
        {
            ASSERT(0) ;
        }

        status = ET9KDB_Validate(&g_engine.sKdbInfo, kdbid, &ET9KDBReadData);
        if (status) 
        {
            ASSERT(0) ;
        }

        status = ET9CPSetInputMode(&g_engine.data.field_info.CCFieldInfo, ET9CPMODE_STROKE);
         if (status) 
        {
            ASSERT(0) ;
        }

        status = ET9CPClearComponent(&g_engine.data.field_info.CCFieldInfo);
          if (status)
        {
           ASSERT(0) ;
        }
 


    /*Configuring the chinese module*/
    /*
    status = ET9CPClearSpellType(&g_engine.data.field_info.CCFieldInfo, ET9CPSpellType_Jianpin);
    if (status)
    {
       ASSERT(0) ;
    }

    status = ET9CPClearNameInput(&g_engine.data.field_info.CCFieldInfo);
      if (status)
    {
       ASSERT(0) ;
    }
  /*     status =  ET9CPSetMohuPairs(&g_engine.data.field_info.CCFieldInfo, ET9U16 wMohuPairBitMask)
     if (status)
    {
       ASSERT(0) ;
    }*/

/*
  status = ET9CPClearComponent(&g_engine.data.field_info.CCFieldInfo);
    if (status)
    {
       ASSERT(0) ;
    }*/

      
  return MMI_TRUE;

    

   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_init_phonetic_chn
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_phonetic_chn( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        ET9STATUS       status;
        ET9U16             kdbid;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/





    #if defined __MMI_IME_FTE_ENHANCE__
       g_engine.eInputMode = IME_XT9_HPD ;
    #else
    #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
       g_engine.eInputMode = IME_XT9_HQD ; 
    #else
       g_engine.eInputMode = IME_XT9_HPD;
    #endif
    #endif
    
  
     status = ET9CPSysInit(&g_engine.data.field_info.CCFieldInfo, &g_engine.sWordSymbInfo, NULL);
    if (status)
    {
       ASSERT(0) ;
    }
    status = ET9CPSetSpellType(&g_engine.data.field_info.CCFieldInfo, ET9CPSpellType_Jianpin);
    if (status)
    {
       ASSERT(0) ;
    }
    status = ET9CPClearSpellType(&g_engine.data.field_info.CCFieldInfo, ET9CPSpellType_Num);
    if (status)
    {
       ASSERT(0) ;
    }
    status = ET9CPLdbValidate(&g_engine.data.field_info.CCFieldInfo,t9_mode_info->nLdbNum,ET9CPReadLdbData);
    if (status)
    {
       ASSERT(0) ;
    }
    status =ET9CPLdbInit(&g_engine.data.field_info.CCFieldInfo,t9_mode_info->nLdbNum,ET9CPReadLdbData);
    if (status)
    {
       ASSERT(0) ;
    }

    if( mmi_ime_xt9_get_vk_type() == IME_XT9_HPD)
   {
       if (t9_mode_info->nLdbNum == ET9PLIDChineseSimplified) 
           kdbid =  (ET9PLIDChinese | ET9SKIDPhonePadPinyin);
       else if (t9_mode_info->nLdbNum == ET9PLIDChineseTraditional)
           kdbid =  (ET9PLIDChinese | ET9SKIDPhonePadPinyin);
   }
   /* Qwerty hard */
   else if ( mmi_ime_xt9_get_vk_type() == IME_XT9_HQD || mmi_ime_xt9_get_vk_type() == IME_XT9_SQD)
   {
        kdbid =  (t9_mode_info->nLdbNum | ET9SKIDATQwerty); 
   }


   /* intialize kdb */
    status = ET9KDB_Init(&g_engine.sKdbInfo,kdbid, 0, 0, 0, &ET9KDBReadData, &ET9Handle_KDB_Request, &g_engine);
        if (status) 
        {
            ASSERT(0) ;
        }

      /*  status = ET9KDB_Validate(&g_engine.sKdbInfo, kdbid, &ET9KDBReadData);
        if (status) 
        {
            ASSERT(0) ;
        }*/

        if(t9_mode_info->nLdbNum == ET9PLIDChineseSimplified)
            {
                status = ET9CPSetInputMode(&g_engine.data.field_info.CCFieldInfo, ET9CPMODE_PINYIN);
            }
        else if (t9_mode_info->nLdbNum == ET9PLIDChineseTraditional)
            {
                status = ET9CPSetInputMode(&g_engine.data.field_info.CCFieldInfo, ET9CPMODE_BPMF);
            }
         if (status) 
        {
            ASSERT(0) ;
        }
 



    /*Configuring the chinese module*/
    /*
    status = ET9CPClearSpellType(&g_engine.data.field_info.CCFieldInfo, ET9CPSpellType_Jianpin);
    if (status)
    {
       ASSERT(0) ;
    }

    status = ET9CPClearNameInput(&g_engine.data.field_info.CCFieldInfo);
      if (status)
    {
       ASSERT(0) ;
    }



  /*     status =  ET9CPSetMohuPairs(&g_engine.data.field_info.CCFieldInfo, ET9U16 wMohuPairBitMask)
     if (status)
    {
       ASSERT(0) ;
    }*/

/*
  status = ET9CPClearComponent(&g_engine.data.field_info.CCFieldInfo);
    if (status)
    {
       ASSERT(0) ;
    }*/
    
  return MMI_TRUE;
}
#endif /* #ifdef __T9_CHINESE */

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_init_alphabetic
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_alphabetic( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    ET9STATUS       wStatus;
    ET9UINT     wkdbnum;
    ET9U16     kdbid;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* decide whihc keyboard is being used */
#if defined __MMI_IME_FTE_ENHANCE__
   if(mmi_imm_get_keyboard_type() == MMI_VK_TYPE_ALPHANUMERIC )
       g_engine.eInputMode = IME_XT9_HPD ;
   else
       g_engine.eInputMode = IME_XT9_SQD ;
#else
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
       g_engine.eInputMode = IME_XT9_HQD ;
#else
       g_engine.eInputMode = IME_XT9_HPD;
#endif
#endif

    /* initialize the linguistic module */

    wStatus = ET9AWSysInit(&g_engine.data.field_info.AWFieldInfo, &g_engine.sLingCmnInfo, &g_engine.sWordSymbInfo, 1, SEL_LIST_SIZE, g_engine.pSelList, NULL);
    if (wStatus) 
    {
       ASSERT(0) ;
    }

    if(!mmi_imm_is_auto_completion_enabled())
        wStatus = ET9AWClearDBCompletion(&g_engine.data.field_info.AWFieldInfo);
    if (wStatus) 
    {
       ASSERT(0) ;
    }

    if(!mmi_imm_is_alphabetic_word_prediction_enabled())
        wStatus = ET9AWClearDBPrediction(&g_engine.data.field_info.AWFieldInfo);
    if (wStatus) 
    {
       ASSERT(0) ;
    }


     /*  validate and initialize the language database (LDB) in the linguistic module */
    wStatus = ET9AWLdbInit(&g_engine.data.field_info.AWFieldInfo, &ET9AWLdbReadData);
    if (wStatus)
    {
       ASSERT(0) ;
    }
    wStatus = ET9AWLdbValidate(&g_engine.data.field_info.AWFieldInfo,t9_mode_info->nLdbNum, &ET9AWLdbReadData);
    if (wStatus)
    {
       ASSERT(0) ;
    }
    wStatus = ET9AWLdbSetLanguage(&g_engine.data.field_info.AWFieldInfo, t9_mode_info->nLdbNum, ET9PLIDNone);
    if (wStatus)
    {
        ASSERT(0) ;
    }
 
   /* 12 key */
   if( mmi_ime_xt9_get_vk_type() == IME_XT9_HPD)
   {
        kdbid =  (t9_mode_info->nLdbNum | ET9SKIDPhonePad);
   }
   /* Qwerty hard */
   else if ( mmi_ime_xt9_get_vk_type() == IME_XT9_HQD || mmi_ime_xt9_get_vk_type() == IME_XT9_SQD) 
   {
        kdbid =  (t9_mode_info->nLdbNum | ET9SKIDATQwerty); 
   }

   /* intialize kdb */
    wStatus = ET9KDB_Init(&g_engine.sKdbInfo,kdbid, 0, 0, 0, &ET9KDBReadData, &ET9Handle_KDB_Request, &g_engine);
    if (wStatus) 
    {
        ASSERT(0) ;
    }

    if (mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP ) 
    {
        wStatus = ET9KDB_SetMultiTapMode(&g_engine.sKdbInfo, 0, 0, &g_engine.sWordSymbInfo);
        g_engine.is_multitap = MMI_TRUE;
        if (wStatus != ET9STATUS_NONE)
        {
            ASSERT(0) ;
        }

    }
    else if (mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
    {
        wStatus = ET9KDB_SetAmbigMode(&g_engine.sKdbInfo, 0, 0, &g_engine.sWordSymbInfo);
        g_engine.is_multitap = MMI_FALSE;
        if (wStatus != ET9STATUS_NONE)
        {
           ASSERT(0) ;
        }

    }
  

     /* validate and initialize the user database (UDB) in the linguistic module */
 #if defined (__MMI_IME_USER_DATABASE__)
    wStatus = ET9AWRUDBInit(&g_engine.data.field_info.AWFieldInfo, (ET9AWRUDBInfo*)g_engine.data.udb_data, MMI_IME_T9_UDB_SIZE, 0);
    if (wStatus)
    {
       ASSERT(0) ;
    }
     
    /*  initialize the context database (CDB) in the linguistic module */
    wStatus = ET9AWCDBInit(&g_engine.data.field_info.AWFieldInfo, (ET9AWCDBInfo*)g_engine.data.cdb_data, MMI_IME_T9_CDB_SIZE, 0);
    if (wStatus)
    {
       ASSERT(0) ;
    }

     /* configure the linguistic module */
    ET9AWClearUDBDelayedReorder(&g_engine.data.field_info.AWFieldInfo);



#endif /* defined(__MMI_IME_USER_DATABASE__) */

    g_engine.first_upper = 0;
    g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_LOWER;
    g_engine.function_key_state  == 0;

    /* The below API is to stop the appearance of same candidates twice in the list*/
    wStatus =  ET9SetDownshiftAllLDBWords(&g_engine.data.field_info.AWFieldInfo);
    if (wStatus != ET9STATUS_NONE)
    { 
        ASSERT(0);
    }
    wStatus =  ET9ClearDownshiftDefault(&g_engine.data.field_info.AWFieldInfo);
    if (wStatus != ET9STATUS_NONE)
    { 
        ASSERT(0);
    }

    wStatus = ET9SetUnShift(&g_engine.sWordSymbInfo);
    if (wStatus != ET9STATUS_NONE)
    { 
        ASSERT(0);
    }

    /*wStatus = ET9AWRUDBReset(&g_engine.data.field_info.AWFieldInfo);
     if (wStatus != ET9STATUS_NONE)
    { 
        ASSERT(0);
    }*/

    if (wStatus == ET9STATUS_NONE)
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
 * RETURNS
 *****************************************************************************/
static void  mmi_ime_t9_get_candidates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{

  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    ET9STATUS status = ET9STATUS_ERROR;
    S32 i, j,k;
    ET9U16 t9_key;
    ET9UINT cnt = 0;
    UI_string_type temp_ptr;
    S32 can_len;
    ET9SYMB sFunctionKey;
    ET9U8           bCandidateIndex;
    ET9AWWordInfo *pWord;
    U32 function_flag = 0;
    ET9SYMB         tempword[ET9MAXWORDSIZE];  
    ET9U16      templength =0;
    ET9U16 temp;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Error Checks */
    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    if ( 0 == param_ptr->elembuf_cnt )
    {
        ASSERT(0);
    }

   /* Initialize kdb as per key pressed */
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    mmi_ime_xt9_set_vk_type((U16)param_ptr->elembuf_ptr[0]);
#endif
    status =  ET9ClearAllSymbs(&g_engine.sWordSymbInfo);
    if (status != ET9STATUS_NONE)
    { 
        ASSERT(0);
    }
 
      
  /* determine key and process it */

    #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {

        t9_key = mmi_ime_t9_from_symb_to_char(param_ptr->elembuf_ptr[i] );
   

        
            status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, (ET9U16)t9_key, g_engine.bActiveWordIndex, &sFunctionKey);
            if (status != ET9STATUS_NONE)
            {
                    ASSERT(0);
            }
        
  }

    #else

    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
#if defined (__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)

        if( mmi_ime_xt9_get_vk_type() == IME_XT9_SQD)
        {
                if (g_engine.active_qwerty_sequence[i] == ','|| g_engine.active_qwerty_sequence[i] == '.')
            {
              status = ET9AddExplicitSymb(&g_engine.sWordSymbInfo,g_engine.active_qwerty_sequence[i],0,0);        
                          
                if (status != ET9STATUS_NONE)
                {
                  ASSERT(0);
                } 
              continue;
            }
            if (g_engine.t9_mode_info->nLdbNum != ET9PLIDThai)
            {
              
                t9_key = g_engine.qwerty_map_ptr[toupper(g_engine.active_qwerty_sequence[i])- 65];

                status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, (ET9U16)t9_key, g_engine.bActiveWordIndex, &sFunctionKey);
                     
                if (status ==  ET9STATUS_OUT_OF_RANGE)
                {            
                    status = ET9AddExplicitSymb(&g_engine.sWordSymbInfo,g_engine.active_qwerty_sequence[i],0,0);        

                    if (status != ET9STATUS_NONE)
                    {
                      ASSERT(0);
                    }

                }
                else  if (status != ET9STATUS_NONE)
                {
                    ASSERT(0);
                }
            }
            else
            {
                    for (k=0;;k++)
                    { 
                       if(g_t9_thai_code_map[k].unicode_value == g_engine.active_qwerty_sequence[i])
                       {
                           t9_key = g_t9_thai_code_map[k].key_value;
                         status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, (ET9U16)t9_key, g_engine.bActiveWordIndex, &sFunctionKey);
                if (status != ET9STATUS_NONE)
                {
                        ASSERT(0);
                }
                         break;
                       } 
                    }
					/*status = ET9AddExplicitSymb(&g_engine.sWordSymbInfo,g_engine.active_qwerty_sequence[i],0,0);        
                          
                if (status != ET9STATUS_NONE)
                {
                        ASSERT(0);
                        }*/
            
            }

        }

        else if( mmi_ime_xt9_get_vk_type() == IME_XT9_HPD)
        {
            t9_key = mmi_ime_t9_from_symb_to_char(param_ptr->elembuf_ptr[i]);
            status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, (ET9U16)t9_key, g_engine.bActiveWordIndex, &sFunctionKey);
            if (status != ET9STATUS_NONE)
            {
                ASSERT(0);
            }

        }  
        

      #else
      
        if( mmi_ime_xt9_get_vk_type() == IME_XT9_HPD)
        {
                    t9_key = mmi_ime_t9_from_symb_to_char(param_ptr->elembuf_ptr[i]);
                    
                    status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, (ET9U16)t9_key, g_engine.bActiveWordIndex, &sFunctionKey);
                    if (status != ET9STATUS_NONE)
                    {
                        ASSERT(0);
        }

             }
        else
        {
            for(i = 0; i< param_ptr->elembuf_cnt; i++)
            {
                status = ET9AddExplicitSymb(&g_engine.sWordSymbInfo,g_engine.active_qwerty_sequence[i],0,0);        
                if (status != ET9STATUS_NONE)
                {
                    ASSERT(0);
                }
            }

        }
      #endif
        }

       #endif

    status =  ET9AWSelLstBuild(&g_engine.data.field_info.AWFieldInfo, &g_engine.bTotWords, &g_engine.bActiveWordIndex);
    if (status != ET9STATUS_NONE)
    {
        return;
    }

    if (param_ptr->first_index >= g_engine.bTotWords)
    {
        return;
    }

   

    temp_ptr = result_ptr->result_buffer;
    j = param_ptr->first_index;

    while (j < (param_ptr->desired_cnt +param_ptr->first_index) && j<g_engine.bTotWords)
    {

        status = ET9AWSelLstGetWord(&g_engine.data.field_info.AWFieldInfo, &pWord, j);
        if (status != ET9STATUS_NONE)
        {
            return;
        }

#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        if (ET9_KDB_MULTITAP_MODE(g_engine.sKdbInfo.dwStateBits))
        {
            memcpy(temp_ptr, &pWord->sWord, pWord->wWordLen * sizeof(UI_character_type));
            temp_ptr += pWord->wWordLen; 
        }
    else
    { 
#endif
        memcpy(temp_ptr, &pWord->sWord, pWord->wWordLen * sizeof(UI_character_type));
        temp_ptr += pWord->wWordLen; 
        *temp_ptr = 0;
        temp_ptr++;          

#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    }
#endif          
        j++;
    }

    
    if(param_ptr->first_index ==0 && (g_engine.is_multitap == 0))
    {
        memcpy(temp_ptr, &tempword, templength * sizeof(UI_character_type));
        temp_ptr += pWord->wWordLen; 
        *temp_ptr = 0;
    }
    else
    {
        *temp_ptr = 0;
    }
    result_ptr->result_cnt = j-param_ptr->first_index;
  
    if(g_engine.bTotWords>param_ptr->desired_cnt)
    {
        result_ptr->next_page = MMI_TRUE;
    }
    else
    {
        result_ptr->next_page = MMI_FALSE;
    }
    
    if ( result_ptr->result_cnt > 0 )
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

#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_associates_alphabetic
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_associates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{

     UI_string_type temp_ptr;
     ET9U16     j;
     ET9U16     i=0;
     ET9STATUS status;
     ET9AWWordInfo *pWord;
     U32 str_len= 0;


     if(g_engine.sWordSymbInfo.SymbsInfo->DataPerBaseSym[0].sChar[0]==0 && param_ptr->first_index == 0)
     {
         str_len = mmi_ucs2strlen((const S8 *)param_ptr->pre_string);

           for(i=0;i<str_len;i++)
            {
                param_ptr->pre_string[i] = (UI_character_type)mmi_towlower((kal_wchar)param_ptr->pre_string[i]);
            }
         
         status =ET9AWNoteWordDone(&g_engine.data.field_info.AWFieldInfo,param_ptr->pre_string, (ET9U16)str_len);

     }

    status = ET9ClearAllSymbs(&g_engine.sWordSymbInfo );
    if (status != ET9STATUS_NONE)
    {
        ASSERT(0);
    }


    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

        ET9AWSelLstBuild(&g_engine.data.field_info.AWFieldInfo, &g_engine.bTotWords, &g_engine.bActiveWordIndex);

        temp_ptr = result_ptr->result_buffer;
        j = param_ptr->first_index;

        while (j < param_ptr->desired_cnt && j<g_engine.bTotWords)
        {

            status = ET9AWSelLstGetWord(&g_engine.data.field_info.AWFieldInfo, &pWord, j);
            if (status != ET9STATUS_NONE)
            {
            return;
            }

            memcpy(temp_ptr, &pWord->sWord, pWord->wWordLen * sizeof(UI_string_type));

            temp_ptr += pWord->wWordLen; 

            *temp_ptr = 0;
            temp_ptr++;
            j++;
        }

    result_ptr->result_cnt = j-param_ptr->first_index;
 
    if(j<g_engine.bTotWords)
    {
        result_ptr->next_page = MMI_TRUE;
    }
    else
    {
        result_ptr->next_page = MMI_FALSE;
    }
                

}
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_associates_alphabetic
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_associates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}
#endif /* #if defined(__MMI_IME_USER_DATABASE__) */

#ifdef __T9_CHINESE

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_from_symb_to_t9key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static U8  mmi_ime_t9_from_symb_to_t9key( U16 symb_key )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( NULL == g_engine.key_map_ptr )
        return ET9KTINVALID;


    if(ET9CPIsModeStroke(&g_engine.data.field_info.CCFieldInfo))
    {
        if ( symb_key >= MMI_IMC_SYMB_KEY_0 && symb_key <= MMI_IMC_SYMB_KEY_POUND )
        {
            return g_engine.key_map_ptr[symb_key - MMI_IMC_SYMB_KEY_0-1]; // -1 is done to match the array position
        }    
    }

    if ( symb_key >= MMI_IMC_KEY_SYM_A && symb_key <= MMI_IMC_KEY_SYM_Z )
    {
        return g_engine.key_map_ptr[symb_key - MMI_IMC_KEY_SYM_POUND];
    }

   // return T9KEYNONE;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_from_symb_to_char
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
ET9U8  mmi_ime_t9_from_symb_to_char( U16 symb_key  )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( NULL == g_engine.qwerty_map_ptr )
        return ET9KTINVALID;


#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    if ( symb_key >= MMI_IMC_SYMB_KEY_A && symb_key <= MMI_IMC_SYMB_KEY_Z )
    {
        return g_engine.qwerty_map_ptr[symb_key - MMI_IMC_SYMB_KEY_A];
    }
    /*the below check is to handle the key '.' on qwerty support on which thai characters are mapped*/
    if (g_engine.input_mode == IMM_INPUT_MODE_SMART_THAI && symb_key == 0x003b)
    {
        return 26; // this is to handel the key '.' on which characters are mapped in thai
    }
#endif

  if (mmi_ime_xt9_get_vk_type() == IME_XT9_SQD) 
  {
    return g_engine.qwerty_map_ptr[symb_key];
  }
  else if (mmi_ime_xt9_get_vk_type() == IME_XT9_HPD)
  {
    return g_engine.key_map_ptr[symb_key];
  }

  return ET9KTINVALID;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_from_symb_to_12key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static ET9U8  mmi_ime_t9_from_symb_to_12key( U16 symb_key )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( NULL == g_engine.key_map_ptr )
        return ET9KTINVALID;

    if (g_engine.input_mode == IMM_INPUT_MODE_MULTITAP_THAI)
    {
        if ( symb_key >= MMI_IMC_KEY_SYM_0 && symb_key <= MMI_IMC_KEY_SYM_POUND )
        {
        return g_engine.key_map_ptr[symb_key - MMI_IMC_KEY_SYM_0];
        }
    }


    if ( symb_key >= MMI_IMC_KEY_SYM_0 && symb_key <= MMI_IMC_KEY_SYM_9 )
    {
        return g_engine.key_map_ptr[symb_key - MMI_IMC_KEY_SYM_0];
    }

    return ET9KTINVALID;
}


#if defined  __T9_CHINESE
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_stroke
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  i;
    U8  symb;
    UI_string_type temp_str;
    ET9STATUS status = ET9STATUS_ERROR;
    ET9U8  t9_key;
    ET9SYMB sFunctionKey =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    
    if ( 0 == param_ptr->elembuf_cnt )
        return;
    
    temp_str = result_ptr->result_buffer;
    
    
    for ( i = 0; i < param_ptr->elembuf_cnt; ++i )
    {
        symb = param_ptr->elembuf_ptr[i];
        t9_key = mmi_ime_t9_from_symb_to_t9key(symb);

        if ( MMI_FALSE != MMI_IMC_IS_SYMB_KEY(symb) )
        {

            *temp_str = mmi_ime_word_symbol_to_code((U8)g_t9_keys_stroke[symb - MMI_IMC_SYMB_KEY_BASE]);
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


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_candidates_stroke
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    ET9STATUS status = ET9STATUS_ERROR;
    U16 i;
    U16 j;
    U8  symb;
    ET9UINT nSpellCount;
        ET9SYMB sFunctionKey;
    ET9U8  t9_key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

        if (param_ptr->first_index > 0) 
    {
       mmi_ime_t9_get_candidates(param_ptr, result_ptr); 
        return;
    }

     ASSERT(ET9CPIsModeStroke(&g_engine.data.field_info.CCFieldInfo));

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    
    status =  ET9ClearAllSymbs(&g_engine.sWordSymbInfo);
    
    if (status != ET9STATUS_NONE)
    { 
        return;
    }
    


    for ( i = 0; i < param_ptr->elembuf_cnt; ++i )
    {
            symb = param_ptr->elembuf_ptr[i];
        for (j=0;j<12;j++ )
        {
			if(param_ptr->elembuf_ptr[i] == 0)
			{
				return;
			}
            if (g_t9_keys_stroke[j]==param_ptr->elembuf_ptr[i])
            {
                t9_key = j-1;
                break;
            }
        }
        //t9_key = mmi_ime_t9_from_symb_to_t9key(symb);

        //if ( MMI_FALSE != MMI_IMC_IS_SYMB_KEY(symb) )
        {
                 
            status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, (ET9U16)t9_key, g_engine.bActiveWordIndex, &sFunctionKey);
            if (status != ET9STATUS_NONE)
            {
                    ASSERT(0);
            }
            
            
        }
            
            
        }



      status = ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);
                if (status != ET9STATUS_NONE)
            {
                    return;
            }

    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
}

#endif /* #if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */


#if defined(__MMI_T9_SM_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_pinyin_multitap
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_pinyin_multitap( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
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

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    
    if ( 0 == param_ptr->elembuf_cnt )
        return ;
   
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

#endif /* #if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#ifdef __MMI_T9_SMART_PHONETIC_INPUT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_pinyin_smart
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_pinyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16          ret_val;
    U8          i;
    U16          j;
    U8          k;
    ET9STATUS    status;
    ET9U8     t9_key;
    ET9U8        *buff_ptr;

    ET9UINT nSpellCount;
    ET9CPPhrase sPhrase;
    ET9CPSpell sActiveSpell;
    ET9SYMB sFunctionKey;
    UI_string_type  temp_ptr;    
    ET9CPSpell   psSpell; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     ASSERT(ET9CPIsModePinyin(&g_engine.data.field_info.CCFieldInfo));

    mmi_ime_xt9_set_vk_type((U16)param_ptr->elembuf_ptr[0]-MMI_IMC_SYMB_KEY_BASE);

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    result_ptr->result_cnt = 0;

    if ( MMI_FALSE == g_engine.is_inited )
        return ;
   
       status =  ET9ClearAllSymbs(&g_engine.sWordSymbInfo);
   
    for ( i = 0; i < param_ptr->elembuf_cnt; i++ )
    {
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        t9_key = mmi_ime_t9_from_symb_to_t9key(param_ptr->elembuf_ptr[i],0);        
       
#else
        if (mmi_ime_xt9_get_vk_type((U16)param_ptr->elembuf_ptr[i]) == IME_XT9_HPD)
        {
          t9_key = mmi_ime_t9_from_symb_to_12key((U16)(param_ptr->elembuf_ptr[i]-MMI_IMC_SYMB_KEY_BASE));
        }
        else
        {
          t9_key = mmi_ime_t9_from_symb_to_t9key(param_ptr->elembuf_ptr[i]);  
        }

#endif

        status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, (ET9U16)t9_key, g_engine.bActiveWordIndex, &sFunctionKey);
        if (status != ET9STATUS_NONE)
        {
                ASSERT(0);
        }
    }

   /* set spell type */
    status = ET9CPSetSpellType(&g_engine.data.field_info.CCFieldInfo, ET9CPSpellType_Pinyin);

    if (status != ET9STATUS_NONE)
    {
        ASSERT(0);
    }
    


    status = ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);
    if (status != ET9STATUS_NONE)
    {
        ASSERT(0);
    }


     /* specify index of spelling for which candidate is required for first time its 0*/
    status = ET9CPSetActiveSpell(&g_engine.data.field_info.CCFieldInfo,0+ param_ptr->first_index);
    if (status == ET9STATUS_OUT_OF_RANGE)
    {
        return;
    }

    if (0 == nSpellCount || param_ptr->first_index >= nSpellCount)
        return;

  //  calculate remaining candidates count 
    
    ret_val = nSpellCount - param_ptr->first_index;
    if (ret_val > param_ptr->desired_cnt)
    {
        ret_val = param_ptr->desired_cnt;
        result_ptr->next_page = MMI_TRUE;
        result_ptr->result_cnt = param_ptr->desired_cnt;

    }
    else
    {
        result_ptr->next_page = MMI_FALSE;
        result_ptr->result_cnt = ret_val;
    }
    
    temp_ptr = result_ptr->result_buffer;
    for(i=param_ptr->first_index;i<(param_ptr->first_index+param_ptr->desired_cnt)&& i<nSpellCount ; i++) //param_ptr->desired_cnt && i<param_ptr->elembuf_cnt
    {

        status =  ET9CPGetSpell(&g_engine.data.field_info.CCFieldInfo, i, &sActiveSpell);

        if(status == ET9STATUS_OUT_OF_RANGE)
             break;
        if (status != ET9STATUS_NONE)
        {
            ASSERT(0);
        }
            
        if ((sActiveSpell.pSymbs[1] ==  ET9CPSpellType_Jianpin)  && (sActiveSpell.pSymbs[0] ==  0 ))  
        {
            /* Show Jianpin */
            memcpy(temp_ptr, L"JP", 6);
        }
        else
        {
          memcpy(temp_ptr, &sActiveSpell.pSymbs, sActiveSpell.bLen*sizeof(UI_character_type));
        }
        temp_ptr += sActiveSpell.bLen; 
        *temp_ptr = 0;
        temp_ptr++;    
        
    }


}

/* this api is going to get merged to get_candidates_pinyin* waiting for it to get tested/
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_candidates_pinyin
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_pinyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ET9STATUS    status;
    S32 i;
    U8 tone_value =0;
    ET9U8     t9_key;
    ET9SYMB sFunctionKey;
    ET9UINT nSpellCount;
    ET9CPSpell sActiveSpell;
    ET9CPPhrase sPhrase;

    ET9SYMB sprefix[256];
    ET9U16 pwsize;
    ET9CPSpell spell;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    
    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    mmi_ime_xt9_set_vk_type(param_ptr->elembuf_ptr[0]);

    /* basically changing spell index */


    status = ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);
    if (status != ET9STATUS_NONE)
    {
        ASSERT(0);
    }

     /* setup for getting active spell  in case its not direct spell */
    if(param_ptr->comp_selected !=  0xff )
    {
        status = ET9CPSetActiveSpell(&g_engine.data.field_info.CCFieldInfo,param_ptr->comp_selected);
        if (status != ET9STATUS_NONE)
        {
            ASSERT(0);
        }
    }
  
    if (MMI_IMC_IS_SYMB_TONE(param_ptr->elembuf_ptr[param_ptr->elembuf_cnt - 1]))
    {
        tone_value = param_ptr->elembuf_ptr[param_ptr->elembuf_cnt - 1];
    }

    if (MMI_IMC_IS_SYMB_TONE(param_ptr->tone_value))
    {
        tone_value = param_ptr->tone_value;
    }
    else if (MMI_IMC_IS_SYMB_TONE(tone_value))
    {
        status = ET9CPAddToneSymb(&g_engine.sWordSymbInfo, &sActiveSpell,g_t9_codes_tone[tone_value - MMI_IMC_SYMB_TONE_BASE]);
        if (status != ET9STATUS_NONE)
        {
                ASSERT(0);
        }
    }

    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
   
}


#endif /* defined(__MMI_T9_SMART_PHONETIC_INPUT__) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_candidates_pinyin
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_pinyin( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ET9STATUS    status;
    S32 i;
    U8 tone_value = 0;
    ET9U8     t9_key;
    ET9SYMB sFunctionKey;
    ET9UINT nSpellCount;
    ET9CPSpell sActiveSpell;
    ET9CPPhrase sPhrase;

    ET9SYMB sprefix[256];
    ET9U16 pwsize;
    ET9CPSpell spell;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((param_ptr->first_index > 0) ||  (candidate_flag == OLD_CANDIDATE &&  param_ptr->first_index == 0)) 
    {
       mmi_ime_t9_get_candidates(param_ptr, result_ptr); 
        return;
    }
    if (param_ptr->elembuf_cnt>0x20) //to set the limit on the number of characters
    {
        return;
    }

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    mmi_ime_xt9_set_vk_type(param_ptr->elembuf_ptr[0]);
    
    /*the below if condition is to make sure that it works only for the smart mode HPD and not SQD*/
    if (g_engine.input_mode == IMM_INPUT_MODE_SM_PINYIN && param_ptr->comp_selected !=  0xff ) 
    {
    /* basically changing spell index */

        status = ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);
        if (status != ET9STATUS_NONE)
        {
            ASSERT(0);
        }

         /* setup for getting active spell  in case its not direct spell */
        if(param_ptr->comp_selected !=  0xff )
        {
        status = ET9CPSetActiveSpell(&g_engine.data.field_info.CCFieldInfo,param_ptr->comp_selected);
        if (status != ET9STATUS_NONE)
        {
            ASSERT(0);
        }
        }

    }
    else
    {
        status =  ET9ClearAllSymbs(&g_engine.sWordSymbInfo);
        
        if (status != ET9STATUS_NONE)
        { 
            ASSERT(0);
        }

      
        for (i =0; i < param_ptr->elembuf_cnt; i++)
        {
            if (MMI_IMC_IS_SYMB_PY(param_ptr->elembuf_ptr[i]))
            {

                t9_key = g_t9_codes_pinyin[param_ptr->elembuf_ptr[i] - MMI_IMC_SYMB_PY_BASE];
           
                #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                
                 t9_key = g_engine.qwerty_map_ptr[t9_key-97];

                #else

                if( (mmi_ime_xt9_get_vk_type() == IME_XT9_HPD) && (!ET9_KDB_MULTITAP_MODE(g_engine.sKdbInfo.dwStateBits)))
                {
                    t9_key = mmi_ime_t9_from_symb_to_12key(t9_key-97);
                }
                else
                {
                    t9_key = mmi_ime_t9_from_symb_to_char((t9_key-97) ); //+MMI_IMC_SYMB_KEY_A
                }
                    
                #endif
                    
                status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, (ET9U16)t9_key, g_engine.bActiveWordIndex, &sFunctionKey);
                if (status != ET9STATUS_NONE)
                {
                        ASSERT(0);
                }
                    
            }
          else if (MMI_IMC_IS_SYMB_TONE(param_ptr->elembuf_ptr[i]) && i == param_ptr->elembuf_cnt - 1)
          {
          }
          else
            {
                return;
            }
            
           
        }

     }


    if (MMI_IMC_IS_SYMB_TONE(param_ptr->elembuf_ptr[param_ptr->elembuf_cnt - 1]))
    {
        tone_value = param_ptr->elembuf_ptr[param_ptr->elembuf_cnt - 1];
    }

    if (MMI_IMC_IS_SYMB_TONE(param_ptr->tone_value))
    {
        tone_value = param_ptr->tone_value;
    }
    else if (MMI_IMC_IS_SYMB_TONE(tone_value))
    {
        status = ET9CPAddToneSymb(&g_engine.sWordSymbInfo, &sActiveSpell,g_t9_codes_tone[tone_value - MMI_IMC_SYMB_TONE_BASE]);
        if (status != ET9STATUS_NONE)
        {
                ASSERT(0);
        }
    }

    if (!(g_engine.input_mode == IMM_INPUT_MODE_SM_PINYIN)|| (g_engine.input_mode == IMM_INPUT_MODE_SM_PINYIN && param_ptr->comp_selected ==  0xff))
    {
        status = ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);
        if (status != ET9STATUS_NONE)
        {
                ASSERT(0);
        }
    }

    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
   
}

#endif /* #if defined(__MMI_T9_SM_CHINESE__) */

#if defined(__MMI_T9_TR_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_zhuyin_multitap
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_zhuyin_multitap( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
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

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    if ( 0 == param_ptr->elembuf_cnt )
        return;

    temp_str = result_ptr->result_buffer;
    
    for ( i = 0; i < param_ptr->elembuf_cnt; i++ )
    {
        symb = param_ptr->elembuf_ptr[i];
        if ( MMI_FALSE != MMI_IMC_IS_SYMB_ZY( symb ) )
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
#endif /* #if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__)
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
static void mmi_ime_t9_get_spellings_zhuyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U16          ret_val;
    U8          i;
    U16          j;
    U8          k;
    ET9STATUS    status;
    ET9U8        key_val;
    ET9U8        *buff_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    
    result_ptr->result_cnt = 0;

    if ( MMI_FALSE == g_engine.is_inited )
        return ;
   
       status = ET9ClearAllSymbs(&g_engine.sWordSymbInfo );
    if (status != ET9STATUS_NONE)
    {
        ASSERT(0);
    }
   
    for ( i = 0; i < param_ptr->elembuf_cnt; i++ )
    {
        key_val = mmi_ime_t9_from_symb_to_t9key(param_ptr->elembuf_ptr[i]);
        
        status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, (ET9U16)t9_key, g_engine.bActiveWordIndex, &sFunctionKey);
        if (status != ET9STATUS_NONE)
        {
                ASSERT(0);
        }
    }

    status =  ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);                 if (status != ET9STATUS_NONE)
    {
            ASSERT(0);
    }
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
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_zhuyin( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS    status;
    S32 i;
    ET9CPSpell sActiveSpell;
    ET9UINT nSpellCount;
    ET9U8 tone_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (param_ptr->first_index > 0) 
    {
       mmi_ime_t9_get_candidates(param_ptr, result_ptr); 
       return;
    }
    if (param_ptr->elembuf_cnt>0x20) //to set the limit on the number of characters
    {
        return;
    }

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    status = ET9ClearAllSymbs(&g_engine.sWordSymbInfo );
    if (status != ET9STATUS_NONE)
    {
        ASSERT(0);
    }


    for (i =0; i < param_ptr->elembuf_cnt; i++)
    {
        if (MMI_IMC_IS_SYMB_ZY(param_ptr->elembuf_ptr[i]))
        {
            status = ET9AddExplicitSymb(&g_engine.sWordSymbInfo,g_t9_unicodes_zhuyin[param_ptr->elembuf_ptr[i] - MMI_IMC_SYMB_ZY_BASE],0,0);
        }
        else if (MMI_IMC_IS_SYMB_TONE(param_ptr->elembuf_ptr[i]) && i == param_ptr->elembuf_cnt - 1)
        {
            
        }
        else
        {
            return;
        }
        
        if ( T9STATNONE != status )
        {
            /* add error */
            return ;
        }


    }

      status = ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);
       if (status != ET9STATUS_NONE)
                {
                        ASSERT(0);
                }
       status =  ET9CPGetSpell(&g_engine.data.field_info.CCFieldInfo, 0, &sActiveSpell);

    if (MMI_IMC_IS_SYMB_TONE(param_ptr->elembuf_ptr[param_ptr->elembuf_cnt - 1]))
    {
        tone_value = param_ptr->elembuf_ptr[param_ptr->elembuf_cnt - 1];
    }
    else if (MMI_IMC_IS_SYMB_TONE(param_ptr->tone_value))
    {
        tone_value = param_ptr->tone_value;
    }

	if (MMI_IMC_IS_SYMB_TONE(tone_value))
    {
        status = ET9CPAddToneSymb(&g_engine.sWordSymbInfo, &sActiveSpell,g_t9_codes_tone[tone_value-1]);
    }

    if (status == ET9STATUS_NONE)
    {
            
    }
    else if ( status ==  ET9STATUS_INVALID_INPUT)
    {

    }

    else 
    {
        /* add error */
         ASSERT(0);
    }



    status = ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);
         if (status == ET9STATUS_INVALID_INPUT)
         {
            result_ptr->result_cnt =0;
            return;
         }
        if (status = ET9STATUS_NONE)
    {
            ASSERT(0);
    }

  
    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
}
#endif /* #if defined(__MMI_T9_TR_CHINESE__) */

#ifdef __T9_CHINESE

static void mmi_ime_t9_get_associates(mmi_ime_query_param_struct_p param_ptr,mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ET9STATUS status = ET9STATUS_ERROR;
    ET9UINT nSpellCount;
    ET9CPPhrase phraseUnicode;
    ET9CPSpell spell;
    ET9CPSpell * pSpell = &spell;
    ET9U8  bSelectedSymb;
    ET9U16 i;
    ET9U16 pos;
    ET9CPPhrase sPhrase;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
/* TODO :check output*/
		if (param_ptr->first_index == 0 && candidate_flag == NEW_CANDIDATE)
    {
        for(i=0;; i++) //param_ptr->desired_cnt && i<param_ptr->elembuf_cnt
        {
            status = ET9CPGetPhrase(&g_engine.data.field_info.CCFieldInfo,(ET9U16)i,&sPhrase);
       
            if(status == ET9STATUS_OUT_OF_RANGE)
            {
                
            }
            else if (status != ET9STATUS_NONE)
            {
                    ASSERT(0);
            }

            if(sPhrase.pSymbs[0] == param_ptr->pre_string[0])
            {
                pos = i;
                break;
            }
        }
        status = ET9CPSelectPhrase(&g_engine.data.field_info.CCFieldInfo, pos, 0, 0);
        status = ET9CPCommitSelection(&g_engine.data.field_info.CCFieldInfo);            



        status =  ET9ClearAllSymbs(&g_engine.sWordSymbInfo);
        status =  ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);
        if (status != ET9STATUS_NONE)
        {
            ASSERT(0);
        }
        

        result_ptr->result_cnt = i;
    }

    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
            
}


static void mmi_ime_t9_get_candidates(mmi_ime_query_param_struct_p param_ptr,mmi_ime_query_result_struct_p result_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ET9UINT first_index, first_part_size;
    ET9STATUS status = ET9STATUS_ERROR;
    UI_character_type candidate_buffer[6+2];//T9CCSELECTPAGEMAXSIZE + 2
    ET9CPSpell sActiveSpell;
    
    UI_string_type  temp_ptr;
    ET9U16 i;
    ET9CPPhrase sPhrase;
    ET9CPSpellType eType;
    ET9U16 j;
    ET9UINT nSpellCount;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    memset(result_ptr->result_buffer,0,param_ptr->desired_cnt*4);

    result_ptr->next_page = MMI_FALSE;

    #if defined (__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
        if (g_engine.t9_mode_info->nLdbNum == ET9PLIDChineseTraditional)
        {
        if (param_ptr->elembuf_cnt > 5)
        {
          return;
        }
        }
    #endif


    temp_ptr = result_ptr->result_buffer;
    for(i=param_ptr->first_index;i<(param_ptr->desired_cnt+param_ptr->first_index); i++) //param_ptr->desired_cnt && i<param_ptr->elembuf_cnt
    {

        status = ET9CPGetPhrase(&g_engine.data.field_info.CCFieldInfo,i,&sPhrase);

        if(status == ET9STATUS_OUT_OF_RANGE)
        break;
        else if (status == ET9STATUS_NEED_SELLIST_BUILD)
        {
        status =  ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);
        status = ET9CPSetActiveSpell(&g_engine.data.field_info.CCFieldInfo,param_ptr->comp_selected);
        i--;
        continue;
        }
        else if (status == ET9STATUS_INVALID_INPUT)
        break;
        if (status != ET9STATUS_NONE)
        {
            ASSERT(0);
        }
        /*if (i<param_ptr->first_index)
        {
            continue;
        }*/
          
        memcpy(temp_ptr, &sPhrase.pSymbs, sPhrase.bLen*sizeof(UI_character_type));


        temp_ptr += sPhrase.bLen; 
        *temp_ptr = 0;
        temp_ptr++;    

    }

    if ((i==(param_ptr->desired_cnt+param_ptr->first_index)) && (status != ET9STATUS_OUT_OF_RANGE))
    {
        status = ET9CPGetPhrase(&g_engine.data.field_info.CCFieldInfo,i,&sPhrase);

        if(status == ET9STATUS_OUT_OF_RANGE)
            result_ptr->next_page = MMI_FALSE;
        else
        result_ptr->next_page = MMI_TRUE;
    }
    else
    {
       result_ptr->next_page = MMI_FALSE;
    }


     result_ptr->result_cnt = i-param_ptr->first_index;

}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_get_associates_chinese_when_tapped
 * DESCRIPTION
    This is a wrapper to get the chinese associates prediciton when taped near the candidate
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_get_associates_chinese_when_tapped( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
#ifdef __T9_CHINESE

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	ET9STATUS status;
	ET9UINT temp =1;
	ET9UINT nSpellCount; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	status = ET9ClearAllSymbs(&g_engine.sWordSymbInfo );
    if (status != ET9STATUS_NONE)
    {
        ASSERT(0);
    }
	
	status = ET9CPFlushContext(&g_engine.data.field_info.CCFieldInfo);
	if (status != ET9STATUS_NONE)
    {
        ASSERT(0); 
    }

	status = ET9CPSetContext(&g_engine.data.field_info.CCFieldInfo,(ET9SYMB *)&param_ptr->pre_string[0],temp);
	if (status != ET9STATUS_NONE)
    {
        ASSERT(0);
    }
	status = ET9CPBuildSpellings(&g_engine.data.field_info.CCFieldInfo, &nSpellCount);
    if (status != ET9STATUS_NONE)
    {
            ASSERT(0);
}

    mmi_ime_t9_get_candidates(param_ptr,result_ptr);
    
#endif

}

 
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
#if defined __MMI_XT9__
        status = ET9AWScanBufForCustomWords(&g_engine.data.field_info.AWFieldInfo, 
                                             str_buf, 
                                             str_len);
#else
        
        status = T9AWUdbScanBufForCustWords(&g_engine.data.field_info.AWFieldInfo, 
                                             (T9SYMB *)str_buf, 
                                             (T9MINOR)str_len);
#endif
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
 *  mmi_ime_word_scan_and_add_new_words
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
#if defined __MMI_XT9__
        ET9AWScanBufForCustomWords(&g_engine.data.field_info.AWFieldInfo, 
                                             str_ptr, 
                                             str_len);
#else
        
  T9AWUdbScanBufForCustWords(&g_engine.data.field_info.AWFieldInfo, (T9SYMB *)str_ptr, (T9MINOR)str_len);
#endif

  

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
    ET9STATUS status = ET9STATUS_NONE;
    ET9UINT cnt = 0;
    S32 i, str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

/* next word doesnt need first upper of last */
    /* SInce word has been selected , e need to rreset active qwerty sequence */
    memset(&g_engine.active_qwerty_sequence, 0 ,64);
    mode_info_p = (mmi_ime_t9_mode_info_struct_p)mmi_ime_t9_get_mode_info(input_mode);
    

    if (mode_info_p == NULL)
    {
        return MMI_FALSE;
    }
    
    if (mode_info_p->init_type == MMI_IME_T9_INIT_TYPE_ALPHABETIC)
    {

        if (status != T9STATNONE)
        {
            return MMI_FALSE;
        }
        cnt =  g_engine.bTotWords;

        if (cnt > 0)
        {
            str_len = mmi_ucs2strlen((const S8 *) str_ptr);
         
            for(i=0;i<str_len;i++)
            {
                str_ptr[i] = (UI_character_type)mmi_towlower((kal_wchar)str_ptr[i]);
            }
         
            for (i = 0; i < cnt; i++)
            {
       /* Inform XT9 we have confirmed this candidate by inject T9KEYSPACE */
                if ( g_engine.pSelList[i].Base.wWordLen != 0
          && !mmi_ucs2nicmp((const S8 *)g_engine.pSelList[i].Base.sWord, (const S8 *) str_ptr, str_len) 
                    && g_engine.pSelList[i].Base.wWordLen  == str_len)
                {
                        ET9AWWordInfo *pWord;

                    ET9AWSelLstSelWord(&g_engine.data.field_info.AWFieldInfo, i);

                    ET9AWSelLstGetWord(&g_engine.data.field_info.AWFieldInfo, &pWord,i);
                
                    status =ET9AWNoteWordDone(&g_engine.data.field_info.AWFieldInfo,str_ptr, (ET9U16)str_len);
                    if (status != ET9STATUS_NONE)
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
                        
                }
                    
                if (status != ET9STATUS_NONE)
                {
                    return MMI_FALSE;
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


    return MMI_TRUE;

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
    U32 bytes_written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_handle < 0)
        return 0;

    bytes_written = 0;
    ret_val = FS_Write(file_handle, (void*)data_ptr, size_in_byte, &bytes_written);
    if (ret_val < 0)
        return 0;

    return bytes_written;
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
    U32 bytes_read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_handle < 0)
        return 0;

    bytes_read = 0;
    ret_val = FS_Read(file_handle, (void*)data_ptr, size_in_byte, &bytes_read);
    if (ret_val < 0)
        return 0;

    return bytes_read;
}


#endif /* defined(__MMI_IME_USER_DATABASE__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_word_add_qwerty_key_to_active_seq
 * DESCRIPTION
 * Add qwerty character to active sequence
 * PARAMETERS
 * RETURNS
 *****************************************************************************/ 
void mmi_imc_word_add_qwerty_key_to_active_seq(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_engine.curr_qwerty_key = ch ;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_word_add_qwerty_key_to_active_seq
 * DESCRIPTION
 * Add qwerty character to active sequence
 * PARAMETERS
 * RETURNS
 *****************************************************************************/ 
void mmi_imc_word_add_qwerty_unicode_to_active_seq(UI_character_type ch , U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_engine.active_qwerty_sequence[index]   = ch ;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_xt9_get_vk_type
 * DESCRIPTION
 * Get vk for which we need to generate candidates
 * PARAMETERS
 * RETURNS
 *****************************************************************************/ 
INPUTMODE mmi_ime_xt9_get_vk_type()
{


#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    return IME_XT9_HQD;
#else
switch(g_engine.input_mode)
{

    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:

    case IMM_INPUT_MODE_SM_STROKE:
    case IMM_INPUT_MODE_TR_STROKE:
    case IMM_INPUT_MODE_HK_STROKE:
    g_engine.eInputMode = IME_XT9_HPD ;
    return g_engine.eInputMode;
  default:
    return  g_engine.eInputMode;
}

    

#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_xt9_set_vk_type
 * DESCRIPTION
 * Get vk for which we need to generate candidates
 * PARAMETERS
 * RETURNS
 *****************************************************************************/ 
void mmi_ime_xt9_set_vk_type(U16 key)
{


#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    g_engine.eInputMode = IME_XT9_HQD;
#else


    ET9STATUS       wStatus;
    ET9UINT     wkdbnum;
    ET9U16          kdbid;
    INPUTMODE key_type = IME_XT9_HPD; // DONE TO INITIALIZE key_temp

  switch(g_engine.input_mode)
{

    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:

    case IMM_INPUT_MODE_SM_STROKE:
    case IMM_INPUT_MODE_TR_STROKE:
    case IMM_INPUT_MODE_HK_STROKE:
    g_engine.eInputMode = IME_XT9_HPD ;
      return;

}
  

  if (g_engine.t9_mode_info->nLdbNum == ET9PLIDThai)
  {
    if ((MMI_IMC_KEY_SYM_0 <= key) && (key <= MMI_IMC_KEY_SYM_POUND) )
        key_type = IME_XT9_HPD ;
        else
        key_type = IME_XT9_SQD ;
  }
  else
  {
  if ((MMI_IMC_KEY_SYM_0 <= key) && (key <= MMI_IMC_KEY_SYM_9) )
        key_type = IME_XT9_HPD ;
    else
        key_type = IME_XT9_SQD ;

  }
    if (key_type != g_engine.eInputMode)
        g_engine.eInputMode = key_type ;
    else
        return; 

   // initialize t9
  if(g_engine.eInputMode == IME_XT9_HPD  )
  {
    if (g_engine.t9_mode_info->nLdbNum == ET9PLIDChineseSimplified||g_engine.t9_mode_info->nLdbNum == ET9PLIDChineseTraditional)
      kdbid = (ET9PLIDChinese|ET9SKIDPhonePadPinyin);
    else
    kdbid =  (g_engine.t9_mode_info->nLdbNum | ET9SKIDPhonePad);
    wStatus = ET9KDB_Init(&g_engine.sKdbInfo, kdbid, 0, 0, 0, &ET9KDBReadData, &ET9Handle_KDB_Request, &g_engine);
          
  }

  else if(g_engine.eInputMode == IME_XT9_SQD  )
  {
    kdbid =  (g_engine.t9_mode_info->nLdbNum | ET9SKIDATQwerty);
    wStatus = ET9KDB_Init(&g_engine.sKdbInfo, kdbid, 0, 0, 0, &ET9KDBReadData, &ET9Handle_KDB_Request, &g_engine);         
          
  }
  if (wStatus) 
  {
    ASSERT(0) ;
  } 



#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_convert_char_to_keyno
 * DESCRIPTION
 * 
 * PARAMETERS
 * RETURNS
 *****************************************************************************/

U16 mmi_ime_convert_char_to_keyno(U16 key_char)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   /*----------------------------------------------------------------*/
    int i;
    U16 temp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
 
    temp = tolower(key_char);
    return (temp-97);
    
}
void mmi_ime_confirm_word_callback()
{
 /* NEED TO MOVE THIS TO IMC */

#ifdef __MMI_CLIPBOARD__
    if (mmi_imc_is_clipboard_state())
    {
        mmi_imc_clipboard_go_back_to_initial();
    }
    else
#endif
	{
    mmi_imc_key_smart_alphabetic_confirm_candidate();
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
	}
    mmi_imc_redraw_screen_by_state();    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_set_shift_caps
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_set_shift_caps(U32  special_key, MMI_BOOL  lock)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
	if (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_UPPER && special_key == 0 && lock == 0)
	{
		mmi_ime_confirm_word_callback();		
	}
    if (special_key == MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT )
    {
    /* Abc */
        if (!lock)
        {
	    mmi_ime_confirm_word_callback();
            g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
            g_engine.first_upper = MMI_TRUE;
            return ;
        }
        /* ABC */
        else
        {
                       
            mmi_ime_confirm_word_callback();
            g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_UPPER;
            g_engine.first_upper = MMI_FALSE;
            return ;
        }
    }

    if ( special_key == MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN )
    {
        mmi_ime_confirm_word_callback();
        if (!lock)
        {
            g_engine.function_key_state = 1;
            return ;
        }
        /* ABC */
        else
        {
            g_engine.function_key_state = 2;
            return ;
        }
    }
    else
    {
        g_engine.function_key_state = 0;

		/* this is a hack for 4N issue ; need to make sure imc state is not used */
		if(mmi_imc_get_state() == MMI_IMC_STATE_INITIAL )
		mmi_ime_word_reset_first_upper_flag();


        return;
    }

     if ( special_key !=  MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
    {
        g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_LOWER;
    }


}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_change_page_of_kdb
 * DESCRIPTION
 * Changes input mode to t9 multitap mode
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_change_page_of_kdb(ime_mode_attr_enum temp_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 i=0;
    ET9U16 page_number;
    ET9STATUS status;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    while(g_t9_state_page_map[i].caps_state != 0)
    {
        if(g_t9_state_page_map[i].caps_state == temp_state)
        {
            page_number = g_t9_state_page_map[i].page_num;
            break;
        }   
        else
            i++;
    }  

    if (g_t9_state_page_map[i].caps_state == 0)
    {
        return;
    }

    status = ET9KDB_SetPageNum(&g_engine.sKdbInfo,(ET9U16)page_number,0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_reset_first_upper_flag
 * DESCRIPTION 
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_reset_first_upper_flag()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
		{
			g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_LOWER;     
			g_engine.first_upper = MMI_FALSE;
		}
	
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
 * Function which returns multitap string for given key
 * PARAMETERS
 * S32 key pressed
 * RETURNS
 * UI_string_type multitap string mapped on input key
 *****************************************************************************/
 UI_string_type mmi_ime_multitap_vendor_get_string_ext(S32 index , S32 input_mode )
{
      /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    ET9STATUS    status;
    ET9U8     t9key;
    U8     i;
    UI_string_type  str_ptr;
    ET9SYMB sFunctionKey ;  
    ET9AWWordInfo *  pWord;
  ET9AWWordInfo *word;
    ET9U16 ret_val;
    ET9U8 val;
    ET9SYMB* page_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    str_ptr = g_engine.data.multitap_string;

	mmi_ime_xt9_set_vk_type((U16)index);

  status = ET9KDB_SetMultiTapMode(&g_engine.sKdbInfo, 0, 0, &g_engine.sWordSymbInfo);
      if (status != ET9STATUS_NONE)
        {
            ASSERT(0) ;
        }

    t9key = mmi_ime_t9_from_symb_to_12key( (U16)index );
        
    page_ptr = g_engine.data.multitap_page;
        
   
    /* setting the case in which candidates are to be extracted */
    if( (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_LOWER) || (g_engine.case_type ==MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER))
    {
        status = ET9SetUnShift(&g_engine.sWordSymbInfo);
    }
    else if (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_UPPER)
    {
        status = ET9SetCapsLock(&g_engine.sWordSymbInfo);
    }

    status =  ET9ClearAllSymbs(&g_engine.sWordSymbInfo);
    if (status != ET9STATUS_NONE) 
    {
        return;
    }
    

  status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, t9key, g_engine.bActiveWordIndex, &sFunctionKey);
  if (status)
    {
      ASSERT(0);
    }

   status = ET9KDB_GetMultiTapSequence(&g_engine.sKdbInfo,page_ptr,100,&ret_val,&val);
   if (status != ET9STATUS_NONE)
            {
    
                ASSERT(0);
            }

  


/* to make sure space comes in multitap mode  on key 0*/
    if ( t9key == 9 && g_engine.input_mode != IMM_INPUT_MODE_MULTITAP_THAI)
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
    
    ET9STATUS    status;
    ET9U8     t9key;
    U8     i;
    UI_string_type  str_ptr;
    ET9SYMB sFunctionKey ;  
    ET9AWWordInfo *  pWord;
  ET9AWWordInfo *word;
    ET9U16 ret_val;
    ET9U8 val;
    ET9SYMB* page_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    str_ptr = g_engine.data.multitap_string;

	mmi_ime_xt9_set_vk_type((U16)index);

  status = ET9KDB_SetMultiTapMode(&g_engine.sKdbInfo, 0, 0, &g_engine.sWordSymbInfo);
      if (status != ET9STATUS_NONE)
        {
            ASSERT(0) ;
        }

    t9key = mmi_ime_t9_from_symb_to_12key( (U16)index );
        
    page_ptr = g_engine.data.multitap_page;
        
   
    /* setting the case in which candidates are to be extracted */
    if( (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_LOWER) || (g_engine.case_type ==MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER))
    {
        status = ET9SetUnShift(&g_engine.sWordSymbInfo);
    }
    else if (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_UPPER)
    {
        status = ET9SetCapsLock(&g_engine.sWordSymbInfo);
    }

    status =  ET9ClearAllSymbs(&g_engine.sWordSymbInfo);
    if (status != ET9STATUS_NONE) 
    {
        return;
    }
    

  status =  ET9KDB_ProcessKey(&g_engine.sKdbInfo, &g_engine.sWordSymbInfo, t9key, g_engine.bActiveWordIndex, &sFunctionKey);
  if (status)
    {
      ASSERT(0);
    }

   status = ET9KDB_GetMultiTapSequence(&g_engine.sKdbInfo,page_ptr,100,&ret_val,&val);
   if (status != ET9STATUS_NONE)
            {
    
                ASSERT(0);
            }

  


/* to make sure space comes in multitap mode  on key 0*/
    if ( t9key == 9 && g_engine.input_mode != IMM_INPUT_MODE_MULTITAP_THAI)
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
U32 mmi_ime_t9_get_lang_ldb(mmi_imm_support_writing_lang_enum writing_lang)
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

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_change_candidates_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void  mmi_ime_t9_change_candidates_case(mmi_ime_query_result_struct_p result_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* to make sure first uppercase works */

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
 if ( g_engine.first_upper  )
    {
        while (j < result_str->result_cnt)
        {
            result_str->result_buffer[i] = (UI_character_type)mmi_towupper((kal_wchar)result_str->result_buffer[i]);

            i++;

            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = (UI_character_type)mmi_towlower((kal_wchar)result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }


else if (mmi_imm_get_current_input_case() == MMI_IME_HINT_FLAG_UPPER_CASE)
    {
        while (j < result_str->result_cnt)
        {
            result_str->result_buffer[i] = (UI_character_type)mmi_towupper((kal_wchar)result_str->result_buffer[i]);
            i++;
            
            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = (UI_character_type)mmi_towupper((kal_wchar)result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }

#else 

    if ( g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
    {
        while (j < result_str->result_cnt)
        {
            result_str->result_buffer[i] = (UI_character_type)mmi_towupper((kal_wchar)result_str->result_buffer[i]);

            i++;

            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = (UI_character_type)mmi_towlower((kal_wchar)result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }
else if (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_UPPER)
    {
        while (j < result_str->result_cnt)
        {
            result_str->result_buffer[i] = (UI_character_type)mmi_towupper((kal_wchar)result_str->result_buffer[i]);
            i++;
            
            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = (UI_character_type)mmi_towupper((kal_wchar)result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }
    else if (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_LOWER)
    {
        while (j < result_str->result_cnt)
        {
            result_str->result_buffer[i] = (UI_character_type)mmi_towlower((kal_wchar)result_str->result_buffer[i]);
            i++;
            
            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = (UI_character_type)mmi_towlower((kal_wchar)result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }
#endif
}
#endif


#else /* XT9 */

#include "MMI_features.h"

#ifdef  __MMI_T9__

#include "GlobalConstants.h"
#include "Fat_fs.h"
#include "Word_Engine.h"  
#include "IMERes.h"     /* include cfor sIMEModeDetails */
#include "mmi_frm_gprot.h"

#include "ImeGprot.h"

#include "Imc_symbol.h"
#include "Imc_config.h"


#include "t9.h"
#include "t9awapi.h"


    #include "MMIDataType.h"
    #include "gui_data_types.h"
    #include "kal_general_types.h"
    #include "fs_type.h"
    #include "string.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "ImmProt.h"
    #include "xxt9oem.h"
    #include "Unicodexdcl.h"
    #include "fs_func.h"

#if defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_HK_CHINESE__)   
#include "t9ccapi.h"
#endif /* defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_SM_CHINESE__) */   

#if defined(__MMI_T9_KOREAN__)
#include "t9kcapi.h"
#endif
#include "t9api.h"

#include "t9gen.h"

#ifdef __MMI_T9_MULTITAP__
#include "Multitap_engine.h"
#endif /* __MMI_T9_MULTITAP__ */

#include "Imc.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)|| defined(__MMI_T9_HK_CHINESE__)
#define __T9_CHINESE
#endif /* defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */

#if defined(__MMI_T9_KOREAN__)
#define __T9_KOREAN
#endif
/*****************************************************************************
 * Define
 *****************************************************************************/
#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
#define MMI_IME_T9_MAX_TEXT_BUFFSIZE            (MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE * 2 + 1)
#else
#define MMI_IME_T9_MAX_TEXT_BUFFSIZE            (MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE)
#endif
#define MMI_IME_T9_DYNAMIC_CONTEXT_FENCE           (0)
#define MMI_IME_T9_DYNAMIC_CONTEXT_SEARCH_DEPTH    (4)

#define MMI_MULTITAP_T9_PAGE_BUFFSIZE   (32 + 1)

#if defined(__MMI_IME_USER_DATABASE__)

#define MMI_IME_T9_UDB_SIZE (20 * 1024) /* 20k bytes (T9 recommended), if we don't turn on word completion
                                         * it should be 4k butes. It should be bigger than T9MINUDBDATABYTES */

#define MMI_IME_T9_CDB_SIZE (4 * 1024)  /* 4k bytes */

#define MMI_IME_USER_DATABASE_FILE_UDB        L"ime_udb.dat"
#define MMI_IME_USER_DATABASE_FILE_CDB        L"ime_cdb.dat"

#endif


#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
#define MMI_IME_T9_MAX_PREDICTION_WORD_NUM     (6)     /* Default value from T9 */
#endif

/*****************************************************************************
 * Global variables
 *****************************************************************************/


/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef enum
{
    MMI_IME_T9_INIT_TYPE_ALPHABETIC = 0,
    MMI_IME_T9_INIT_TYPE_PHONETIC,
    MMI_IME_T9_INIT_TYPE_STROKE,
    MMI_IME_T9_INIT_TYPE_DIRECT,
    MMI_IME_T9_INIT_TYPE_KOREAN,
    MMI_IME_T9_INIT_TYPE_MAX
}   mmi_ime_t9_init_type_enum;

typedef union T9CCAWFieldInfo_u
{
#if defined __T9_CHINESE 
    T9CCFieldInfo CCFieldInfo;
#endif /* defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_SM_CHINESE__) */   
#if defined __T9_KOREAN
     T9KCFieldInfo KCFieldInfo;
#endif /* defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_SM_CHINESE__) */    
    T9AWFieldInfo AWFieldInfo;
} T9CCAWFieldInfo;

typedef struct
{
    mmi_imm_input_mode_enum         input_mode;
    const T9MINOR                         *key_map_ptr;
    mmi_ime_t9_init_type_enum       init_type;
    T9UINT                          nLdbNum;
    U32                             required_keys;
    U32                             symbol_keys;
    mmi_ime_get_spellings_funcptr   get_spell_funcptr;
    mmi_ime_get_associates_funcptr  get_assoc_funcptr;
    mmi_ime_get_candidates_funcptr  get_cand_funcptr;
}  mmi_ime_t9_mode_info_struct, * mmi_ime_t9_mode_info_struct_p;


typedef struct
{
#ifdef __MMI_T9_MULTITAP__
    T9SYMB              multitap_page[MMI_MULTITAP_T9_PAGE_BUFFSIZE];
    UI_character_type   multitap_string[MMI_MULTITAP_T9_PAGE_BUFFSIZE];
#endif /* __MMI_T9_MULTITAP__ */
    
    T9CCAWFieldInfo     field_info;

#if defined(__MMI_IME_USER_DATABASE__)
    U16                udb_data[MMI_IME_T9_UDB_SIZE / 2];
    U16                cdb_data[MMI_IME_T9_CDB_SIZE / 2];
#endif
#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
    UI_character_type   ass_alpha_cand[MMI_IME_T9_MAX_PREDICTION_WORD_NUM][MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
    S32                 ass_alpha_count;
#endif

    T9SYMB              text_buff[MMI_IME_T9_MAX_TEXT_BUFFSIZE + 1];
    T9AuxType           aux_buff[MMI_IME_T9_MAX_TEXT_BUFFSIZE + 1];
}   mmi_ime_t9_data_struct, *mmi_ime_t9_data_struct_p;


typedef struct
{
    mmi_ime_t9_data_struct          data;
    const T9MINOR                         *key_map_ptr;
    mmi_ime_t9_mode_info_struct_p   t9_mode_info;
    MMI_BOOL                        is_inited;
    mmi_imm_input_mode_enum        input_mode;
    mmi_ime_word_capital_state_enum case_type;
}   mmi_ime_t9_word_engine_struct, *mmi_ime_t9_word_engine_struct_p;

#if defined(__MMI_MIXED_LANG_SUPPORT__)
typedef struct
{
    mmi_imm_support_writing_lang_enum writing_lang;
    T9UINT ldb_num;
}mmi_ime_t9_writing_lang_ldb_map_struct;
#endif

/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef T9MINOR     (*mmi_ime_symb_conv_funcptr)( U8 symb_value, T9MINOR *symb_map );

/*****************************************************************************
 * Local Functions
 *****************************************************************************/
 
/* Utility functions */
static UI_character_type mmi_ime_t9_t9code_to_code(T9U8 t9code, mmi_imm_input_mode_enum mode);

/* multitap functions */
static T9MINOR  mmi_ime_t9_from_symb_to_t9key( U16 symb_key );

/* word functions */
static T9STATUS T9_handle_request( T9FieldInfo *field_info_ptr, T9Request *request_ptr );

#if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_SMART_FIRST_UPPERCASE__)
static void  mmi_ime_t9_change_candidates_case(mmi_ime_query_result_struct_p result_str);
#endif

#ifdef __T9_CHINESE
static MMI_BOOL mmi_ime_t9_init_stroke_chn( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr );
static MMI_BOOL mmi_ime_t9_init_phonetic_chn( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr );
#endif /* __T9_CHINESE */

static MMI_BOOL mmi_ime_t9_init_alphabetic( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr );
static MMI_BOOL mmi_ime_t9_init_number( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr );
#if defined __T9_KOREAN
static MMI_BOOL mmi_ime_t9_init_korean(mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr );
#endif
static mmi_ime_t9_mode_info_struct_p  mmi_ime_t9_get_mode_info( mmi_imm_input_mode_enum input_mode );

/* Query functions */

static void mmi_ime_t9_get_candidates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );

static void mmi_ime_t9_get_associates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );

#if defined  __T9_CHINESE
static void     mmi_ime_t9_get_spellings_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
static void     mmi_ime_t9_get_candidates_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
static void     mmi_ime_t9_get_associates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
static void     mmi_ime_t9_get_candidates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr);
#endif /* #if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */

/* Simplified Chinese functions */
#if defined(__MMI_T9_SM_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
static void mmi_ime_t9_get_spellings_pinyin_multitap( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

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

#if defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__)
static void mmi_ime_t9_get_spellings_zhuyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_T9_SMART_PHONETIC_INPUT__) */

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
#if defined(__MMI_MIXED_LANG_SUPPORT__)
static T9UINT mmi_ime_t9_get_lang_ldb(mmi_imm_support_writing_lang_enum writing_lang);
#endif
#if defined __T9_KOREAN
static void  mmi_ime_t9_get_candidates_korean( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif
/*****************************************************************************
 * Local variables
 *****************************************************************************/

/* Symbol keys mapping (by language) */
static const T9MINOR  g_t9_keys_alphabetic[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] =
{
    T9KEYAMBIGA, // MMI_IMC_SYMB_KEY_0
    T9KEYAMBIG1, // MMI_IMC_SYMB_KEY_1
    T9KEYAMBIG2, // MMI_IMC_SYMB_KEY_2
    T9KEYAMBIG3, // MMI_IMC_SYMB_KEY_3
    T9KEYAMBIG4, // MMI_IMC_SYMB_KEY_4
    T9KEYAMBIG5, // MMI_IMC_SYMB_KEY_5
    T9KEYAMBIG6, // MMI_IMC_SYMB_KEY_6
    T9KEYAMBIG7, // MMI_IMC_SYMB_KEY_7
    T9KEYAMBIG8, // MMI_IMC_SYMB_KEY_8
    T9KEYAMBIG9, // MMI_IMC_SYMB_KEY_9
    T9KEYNONE, // MMI_IMC_SYMB_KEY_STAR
    T9KEYNONE, // MMI_IMC_SYMB_KEY_POUND
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

static const T9MINOR  g_t9_keys_chinese[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] =
{
#ifdef __MMI_T9_DEFAULT_KEY_DEFINITION__
    T9KEYAMBIGB, // IME_SYMB_KEY_0
#else /* __MMI_T9_DEFAULT_KEY_DEFINITION__ */
    T9KEYAMBIGA, // IME_SYMB_KEY_0
#endif /* __MMI_T9_DEFAULT_KEY_DEFINITION__ */
    
    T9KEYAMBIG1, // MMI_IMC_SYMB_KEY_1
    T9KEYAMBIG2, // MMI_IMC_SYMB_KEY_2
    T9KEYAMBIG3, // MMI_IMC_SYMB_KEY_3
    T9KEYAMBIG4, // MMI_IMC_SYMB_KEY_4
    T9KEYAMBIG5, // MMI_IMC_SYMB_KEY_5
    T9KEYAMBIG6, // MMI_IMC_SYMB_KEY_6
    T9KEYAMBIG7, // MMI_IMC_SYMB_KEY_7
    T9KEYAMBIG8, // MMI_IMC_SYMB_KEY_8
    T9KEYAMBIG9, // MMI_IMC_SYMB_KEY_9

#ifdef __MMI_T9_DEFAULT_KEY_DEFINITION__
    T9KEYAMBIGA, // MMI_IMC_SYMB_KEY_STAR
    T9KEYAMBIGC, // MMI_IMC_SYMB_KEY_POUND
#else /* __MMI_T9_DEFAULT_KEY_DEFINITION__ */
    T9KEYNONE, // MMI_IMC_SYMB_KEY_STAR
    T9KEYNONE, // MMI_IMC_SYMB_KEY_POUND
#endif /* __MMI_T9_DEFAULT_KEY_DEFINITION__ */
};

static const mmi_imc_symb_stroke_enum g_t9_keys_stroke[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] =
{
    MMI_IMC_SYMB_STROKE_ZEROTH,                                /* MMI_IMC_SYMB_KEY_0 */
    MMI_IMC_SYMB_STROKE_OVER,         /* MMI_IMC_SYMB_KEY_1 */
    MMI_IMC_SYMB_STROKE_DOWN,         /* MMI_IMC_SYMB_KEY_2 */
    MMI_IMC_SYMB_STROKE_LEFT,         /* MMI_IMC_SYMB_KEY_3 */
    MMI_IMC_SYMB_STROKE_DOT,          /* MMI_IMC_SYMB_KEY_4 */
    MMI_IMC_SYMB_STROKE_OVER_DOWN,    /* MMI_IMC_SYMB_KEY_5 */
    MMI_IMC_SYMB_STROKE_WILDCARD,     /* MMI_IMC_SYMB_KEY_6 */
    MMI_IMC_SYMB_STROKE_ZEROTH,                                /* MMI_IMC_SYMB_KEY_7 */
    MMI_IMC_SYMB_STROKE_ZEROTH,                                /* MMI_IMC_SYMB_KEY_8 */
    MMI_IMC_SYMB_STROKE_ZEROTH,                                /* MMI_IMC_SYMB_KEY_9 */
    MMI_IMC_SYMB_STROKE_ZEROTH,                                /* MMI_IMC_SYMB_KEY_STAR */
    MMI_IMC_SYMB_STROKE_ZEROTH                                 /* MMI_IMC_SYMB_KEY_POUND */
};

#endif /* __T9_CHINESE */


/* Symbol code mapping, for query */
static const T9MINOR  g_t9_codes_tone[MMI_IMC_SYMB_TONE_MAX - MMI_IMC_SYMB_TONE_BASE] =
{
    0,           /* MMI_IMC_SYMB_TONE_NONE */
    T9KEYAMBIG1, /* MMI_IMC_SYMB_TONE_1 */
    T9KEYAMBIG2, /* MMI_IMC_SYMB_TONE_2 */
    T9KEYAMBIG3, /* MMI_IMC_SYMB_TONE_3 */
    T9KEYAMBIG4, /* MMI_IMC_SYMB_TONE_4 */
    T9KEYAMBIG5  /* MMI_IMC_SYMB_TONE_5 */
};

#ifdef __T9_CHINESE

static const T9MINOR  g_t9_codes_stroke[MMI_IMC_SYMB_STROKE_MAX - MMI_IMC_SYMB_STROKE_BASE] =
{
    T9KEYAMBIG6,        /* MMI_IMC_SYMB_STROKE_WILDCARD, */
    T9KEYAMBIG2,        /* MMI_IMC_SYMB_STROKE_DOWN, */
    T9KEYAMBIG4,        /* MMI_IMC_SYMB_STROKE_DOT, */
    0,                  /* MMI_IMC_SYMB_STROKE_CURVED_HOOK, */
    T9KEYAMBIG1,        /* MMI_IMC_SYMB_STROKE_OVER, */
    T9KEYAMBIG5,        /* MMI_IMC_SYMB_STROKE_OVER_DOWN, */
    0,                  /* MMI_IMC_SYMB_STROKE_DOWN_OVER, */
    T9KEYAMBIG3,        /* MMI_IMC_SYMB_STROKE_LEFT, */
    0,                  /* MMI_IMC_SYMB_STROKE_OVER_DOWN_OVER, */
    0,                  /* MMI_IMC_SYMB_STROKE_MORE, */
    0,                  /* MMI_IMC_SYMB_STROKE_TURN, */
    0,                  /* MMI_IMC_SYMB_STROKE_DOT_OR_LEFT, */
};

static const UI_character_type  g_t9_unicodes_stroke[MMI_IMC_SYMB_STROKE_MAX - MMI_IMC_SYMB_STROKE_BASE] =
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


#endif /* #ifdef __T9_CHINESE */

#ifdef __MMI_T9_SM_CHINESE__

/* T9 use pinyin unicode (a-z) to query, not internal symbol code */
static const T9U8  g_t9_codes_pinyin[MMI_IMC_SYMB_PY_MAX - MMI_IMC_SYMB_PY_BASE] = 
{
    'a',  /* MMI_IMC_SYMB_PY_A */
    'b',  /* MMI_IMC_SYMB_PY_B */
    'c',  /* MMI_IMC_SYMB_PY_C */

    'd',  /* MMI_IMC_SYMB_PY_D */
    'e',  /* MMI_IMC_SYMB_PY_E */
    'f',  /* MMI_IMC_SYMB_PY_F */

    'g',  /* MMI_IMC_SYMB_PY_G */
    'h',  /* MMI_IMC_SYMB_PY_H */
    'i',  /* MMI_IMC_SYMB_PY_I */

    'j',  /* MMI_IMC_SYMB_PY_J */
    'k',  /* MMI_IMC_SYMB_PY_K */
    'l',  /* MMI_IMC_SYMB_PY_L */

    'm',  /* MMI_IMC_SYMB_PY_M */
    'n',  /* MMI_IMC_SYMB_PY_N */
    'o',  /* MMI_IMC_SYMB_PY_O */

    'p',  /* MMI_IMC_SYMB_PY_P */
    'q',  /* MMI_IMC_SYMB_PY_Q */
    'r',  /* MMI_IMC_SYMB_PY_R */
    's',  /* MMI_IMC_SYMB_PY_S */

    't',  /* MMI_IMC_SYMB_PY_T */
    'u',  /* MMI_IMC_SYMB_PY_U */
    'v',  /* MMI_IMC_SYMB_PY_V */

    'w',  /* MMI_IMC_SYMB_PY_W */
    'x',  /* MMI_IMC_SYMB_PY_X */
    'y',  /* MMI_IMC_SYMB_PY_Y */
    'z'   /* MMI_IMC_SYMB_PY_Z */
};
#endif /* #ifdef __MMI_T9_SM_CHINESE__ */

#ifdef __MMI_T9_TR_CHINESE__

static const UI_character_type  g_t9_unicodes_zhuyin[MMI_IMC_SYMB_ZY_MAX - MMI_IMC_SYMB_ZY_B] =
{
    0x3105, /*MMI_IMC_SYMB_ZY_B*/
    0x3106, /*MMI_IMC_SYMB_ZY_P*/
    0x3107, /*MMI_IMC_SYMB_ZY_M*/
    0x3108, /*MMI_IMC_SYMB_ZY_F*/
    0x3109, /*MMI_IMC_SYMB_ZY_D*/
    0x310A, /*MMI_IMC_SYMB_ZY_T*/
    0x310B, /*MMI_IMC_SYMB_ZY_N*/
    0x310C, /*MMI_IMC_SYMB_ZY_L*/
    0x310D, /*MMI_IMC_SYMB_ZY_G*/
    0x310E, /*MMI_IMC_SYMB_ZY_K*/
    0x310F, /*MMI_IMC_SYMB_ZY_H*/
    0x3110, /*MMI_IMC_SYMB_ZY_J*/
    0x3111, /*MMI_IMC_SYMB_ZY_Q*/
    0x3112, /*MMI_IMC_SYMB_ZY_X*/
    0x3113, /*MMI_IMC_SYMB_ZY_ZH*/
    0x3114, /*MMI_IMC_SYMB_ZY_CH*/
    0x3115, /*MMI_IMC_SYMB_ZY_SH*/
    0x3116, /*MMI_IMC_SYMB_ZY_R*/
    0x3117, /*MMI_IMC_SYMB_ZY_Z*/
    0x3118, /*MMI_IMC_SYMB_ZY_C*/
    0x3119, /*MMI_IMC_SYMB_ZY_S*/
    0x311A, /*MMI_IMC_SYMB_ZY_A*/
    0x311B, /*MMI_IMC_SYMB_ZY_O*/
    0x311C, /*MMI_IMC_SYMB_ZY_E*/
    0x311D, /*MMI_IMC_SYMB_ZY_EH*/
    0x311E, /*MMI_IMC_SYMB_ZY_AI*/
    0x311F, /*MMI_IMC_SYMB_ZY_EI*/
    0x3120, /*MMI_IMC_SYMB_ZY_AU*/
    0x3121, /*MMI_IMC_SYMB_ZY_OU*/
    0x3122, /*MMI_IMC_SYMB_ZY_AN*/
    0x3123, /*MMI_IMC_SYMB_ZY_EN*/
    0x3124, /*MMI_IMC_SYMB_ZY_ANG*/
    0x3125, /*MMI_IMC_SYMB_ZY_ENG*/
    0x3126, /*MMI_IMC_SYMB_ZY_ER*/
    0x3127, /*MMI_IMC_SYMB_ZY_I*/
    0x3128, /*MMI_IMC_SYMB_ZY_U*/
    0x3129  /*MMI_IMC_SYMB_ZY_IU*/
};

static const T9U8 g_t9_codes_zhuyin[MMI_IMC_SYMB_ZY_MAX - MMI_IMC_SYMB_ZY_B] = 
{
    'b', /*MMI_IMC_SYMB_ZY_B*/
    'p', /*MMI_IMC_SYMB_ZY_P*/
    'm', /*MMI_IMC_SYMB_ZY_M*/
    'f', /*MMI_IMC_SYMB_ZY_F*/
    'd', /*MMI_IMC_SYMB_ZY_D*/
    't', /*MMI_IMC_SYMB_ZY_T*/
    'n', /*MMI_IMC_SYMB_ZY_N*/
    'l', /*MMI_IMC_SYMB_ZY_L*/
    'g', /*MMI_IMC_SYMB_ZY_G*/
    'k', /*MMI_IMC_SYMB_ZY_K*/
    'h', /*MMI_IMC_SYMB_ZY_H*/
    'j', /*MMI_IMC_SYMB_ZY_J*/
    'q', /*MMI_IMC_SYMB_ZY_Q*/
    'x', /*MMI_IMC_SYMB_ZY_X*/
    0xdf,/*MMI_IMC_SYMB_ZY_ZH*/
    0xe7,/*MMI_IMC_SYMB_ZY_CH*/
    0x9a,/*MMI_IMC_SYMB_ZY_SH*/
    'r', /*MMI_IMC_SYMB_ZY_R*/
    'z', /*MMI_IMC_SYMB_ZY_Z*/
    'c', /*MMI_IMC_SYMB_ZY_C*/
    's', /*MMI_IMC_SYMB_ZY_S*/
    'a', /*MMI_IMC_SYMB_ZY_A*/
    'o', /*MMI_IMC_SYMB_ZY_O*/
    'e', /*MMI_IMC_SYMB_ZY_E*/
    0xe9,/*MMI_IMC_SYMB_ZY_EH*/
    0xe4,/*MMI_IMC_SYMB_ZY_AI*/
    0xf6,/*MMI_IMC_SYMB_ZY_EI*/
    0xe5,/*MMI_IMC_SYMB_ZY_AU*/
    0xfd,/*MMI_IMC_SYMB_ZY_OU*/
    0xe3,/*MMI_IMC_SYMB_ZY_AN*/
    0xf5,/*MMI_IMC_SYMB_ZY_EN*/
    0xe2,/*MMI_IMC_SYMB_ZY_ANG*/
    0xf4,/*MMI_IMC_SYMB_ZY_ENG*/
    0xf8,/*MMI_IMC_SYMB_ZY_ER*/
    'i', /*MMI_IMC_SYMB_ZY_I*/
    'u', /*MMI_IMC_SYMB_ZY_U*/
    0xfc /*MMI_IMC_SYMB_ZY_IU*/
};
#endif /* #ifdef __MMI_T9_TR_CHINESE__ */



static const mmi_ime_t9_mode_info_struct  g_mode_infos[] = 
{
#if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
    {   
        IMM_INPUT_MODE_TR_MULTITAP_BOPOMO,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        T9PIDChinese | T9SIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS,
    #if defined(__MMI_T9_DEFAULT_KEY_DEFINITION__)
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_0),
    #else
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
    #endif
        mmi_ime_t9_get_spellings_zhuyin_multitap,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_zhuyin
    },
    {   
        IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        T9PIDChinese | T9SIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS,
#if defined(__MMI_T9_DEFAULT_KEY_DEFINITION__)
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_0),
#else
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
#endif
        mmi_ime_t9_get_spellings_zhuyin_multitap,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_zhuyin
    },
#endif /* #if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */
    
#if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
    {
        IMM_INPUT_MODE_SM_MULTITAP_PINYIN,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        T9PIDChinese | T9SIDChineseSimplified,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_1),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_1) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_pinyin_multitap,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_pinyin
    },
    {
        IMM_INPUT_MODE_QUICK_SEARCH_PINYIN,
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
    
#if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__)
    {   
        IMM_INPUT_MODE_TR_BOPOMO,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        T9PIDChinese | T9SIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS,
#if defined(__MMI_T9_DEFAULT_KEY_DEFINITION__)
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_0),
#else
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
#endif
        mmi_ime_t9_get_spellings_zhuyin_smart,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_zhuyin
    },
#endif /* #if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__) */    
    
#if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)
    {
        IMM_INPUT_MODE_SM_PINYIN,
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
    
#if defined(__MMI_T9_TR_CHINESE__)
    {
        IMM_INPUT_MODE_TR_STROKE, 
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_STROKE,
        T9PIDChinese | T9SIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_stroke,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_stroke
    },
    {
        IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE,
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
    
#if defined (__MMI_T9_HK_CHINESE__)
    {
        IMM_INPUT_MODE_HK_STROKE, 
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_STROKE,
        T9PIDChinese | T9SIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_stroke,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_stroke
    },
    {
        IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE,
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
    
#if defined(__MMI_T9_SM_CHINESE__)
    {
        IMM_INPUT_MODE_SM_STROKE,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_STROKE,
        T9PIDChinese | T9SIDChineseSimplified,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_stroke,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_stroke
    },
    {
        IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE,
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



	/* Languages with two writing cases */
#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_AFRIKAANS__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAfrikaans,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAfrikaans,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_AFRIKAANS__)*/

#if defined(__MMI_T9_AFRIKAANS__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAfrikaans,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAfrikaans,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_AFRIKAANS__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ALBANIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ALBANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAlbanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ALBANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAlbanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ALBANIAN__)*/

#if defined(__MMI_T9_ALBANIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_ALBANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAlbanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_ALBANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAlbanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_ALBANIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_AZERBAIJANI__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_AZERBAIJANI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAzerbaijani,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_AZERBAIJANI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAzerbaijani,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_AZERBAIJANI__)*/

#if defined(__MMI_T9_AZERBAIJANI__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_AZERBAIJANI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAzerbaijani,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_AZERBAIJANI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAzerbaijani,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_AZERBAIJANI__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_BASQUE__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_BASQUE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDBasque,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDBasque,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_BASQUE__)*/

#if defined(__MMI_T9_BASQUE__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_BASQUE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDBasque,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_BASQUE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDBasque,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_BASQUE__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_BULGARIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDBulgarian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDBulgarian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_BULGARIAN__)*/

#if defined(__MMI_T9_BULGARIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDBulgarian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDBulgarian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_BULGARIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_CATALAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_CATALAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCatalan,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_CATALAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCatalan,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_CATALAN__)*/

#if defined(__MMI_T9_CATALAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_CATALAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCatalan,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_CATALAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCatalan,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_CATALAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_CROATIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCroatian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCroatian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_CROATIAN__)*/

#if defined(__MMI_T9_CROATIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_CROATIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCroatian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_CROATIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCroatian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_CROATIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_CZECH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCzech,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCzech,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_CZECH__)*/

#if defined(__MMI_T9_CZECH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_CZECH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCzech,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_CZECH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDCzech,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_CZECH__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_DANISH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDDanish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDDanish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_DANISH__)*/

#if defined(__MMI_T9_DANISH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_DANISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDDanish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_DANISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDDanish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_DANISH__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_DUTCH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDDutch,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDDutch,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_DUTCH__)*/

#if defined(__MMI_T9_DUTCH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_DUTCH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDDutch,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_DUTCH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDDutch,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_DUTCH__) */


#if defined(__MMI_T9_MULTITAP__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
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
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ENGLISH__)*/

#if defined(__MMI_T9_ENGLISH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_ABC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_ENGLISH__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ESTONIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ESTONIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEstonian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEstonian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ESTONIAN__)*/

#if defined(__MMI_T9_ESTONIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_ESTONIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEstonian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEstonian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_ESTONIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_FINNISH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDFinnish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDFinnish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_FINNISH__)*/

#if defined(__MMI_T9_FINNISH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_FINNISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDFinnish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_FINNISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDFinnish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_FINNISH__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_FRENCH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDFrench,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDFrench,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_FRENCH__)*/

#if defined(__MMI_T9_FRENCH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDFrench,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDFrench,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_FRENCH__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_GALICIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_GALICIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGalician,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGalician,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_GALICIAN__)*/

#if defined(__MMI_T9_GALICIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_GALICIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGalician,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_GALICIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGalician,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_GALICIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_GERMAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGerman,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGerman,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_GERMAN__)*/

#if defined(__MMI_T9_GERMAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_GERMAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGerman,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_GERMAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGerman,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_GERMAN__) */

#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_PERSIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_PERSIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDFarsi,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_PERSIAN__)*/

#if defined(__MMI_T9_PERSIAN__)
    {   
        IMM_INPUT_MODE_SMART_PERSIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDFarsi,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_PERSIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_GREEK__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGreek,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGreek,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_GREEK__)*/

#if defined(__MMI_T9_GREEK__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_GREEK,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGreek,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_GREEK,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGreek,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_GREEK__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_HAUSA__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_HAUSA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHausa,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_HAUSA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHausa,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_HAUSA__)*/

#if defined(__MMI_T9_HAUSA__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_HAUSA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHausa,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_HAUSA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHausa,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_HAUSA__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_HUNGARIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHungarian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHungarian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_HUNGARIAN__)*/

#if defined(__MMI_T9_HUNGARIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHungarian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHungarian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_HUNGARIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ICELANDIC__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ICELANDIC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIcelandic,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ICELANDIC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIcelandic,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ICELANDIC__)*/

#if defined(__MMI_T9_ICELANDIC__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_ICELANDIC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIcelandic,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_ICELANDIC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIcelandic,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_ICELANDIC__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_IGBO__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_IGBO,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIgbo,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIgbo,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_IGBO__)*/

#if defined(__MMI_T9_IGBO__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_IGBO,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIgbo,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_IGBO,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIgbo,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_IGBO__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_INDONESIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIndonesian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIndonesian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_INDONESIAN__)*/

#if defined(__MMI_T9_INDONESIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIndonesian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIndonesian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_INDONESIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_IRISH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_IRISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIrish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIrish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_IRISH__)*/

#if defined(__MMI_T9_IRISH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_IRISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIrish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_IRISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIrish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_IRISH__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ITALIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDItalian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDItalian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ITALIAN__)*/

#if defined(__MMI_T9_ITALIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_ITALIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDItalian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDItalian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_ITALIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_KAZAKH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_KAZAKH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDKazakh,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_KAZAKH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDKazakh,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_KAZAKH__)*/

#if defined(__MMI_T9_KAZAKH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_KAZAKH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDKazakh,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_KAZAKH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDKazakh,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_KAZAKH__) */

#if defined(__MMI_MULTITAP_KOREAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_KOREAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_KOREAN,
        T9PIDKorean,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_korean
    },
    
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_KOREAN__)*/


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_LATVIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_LATVIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDLatvian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDLatvian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_LATVIAN__)*/

#if defined(__MMI_T9_LATVIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_LATVIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDLatvian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_LATVIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDLatvian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_LATVIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_LITHUANIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDLithuanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDLithuanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_LITHUANIAN__)*/

#if defined(__MMI_T9_LITHUANIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDLithuanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDLithuanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_LITHUANIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_MACEDONIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_MACEDONIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMacedonian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_MACEDONIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMacedonian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_MACEDONIAN__)*/

#if defined(__MMI_T9_MACEDONIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_MACEDONIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMacedonian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_MACEDONIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMacedonian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_MACEDONIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_MALAY__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMalay,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMalay,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_MALAY__)*/

#if defined(__MMI_T9_MALAY__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_MALAY,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMalay,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_MALAY,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMalay,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_MALAY__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_NORWEGIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDNorwegian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDNorwegian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_NORWEGIAN__)*/

#if defined(__MMI_T9_NORWEGIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDNorwegian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDNorwegian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_NORWEGIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_POLISH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPolish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPolish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_POLISH__)*/

#if defined(__MMI_T9_POLISH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_POLISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPolish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_POLISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPolish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_POLISH__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_PORTUGUESE__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPortuguese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPortuguese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_PORTUGUESE__)*/

#if defined(__MMI_T9_PORTUGUESE__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPortuguese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPortuguese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_PORTUGUESE__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ROMANIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRomanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRomanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ROMANIAN__)*/

#if defined(__MMI_T9_ROMANIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRomanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRomanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_ROMANIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_RUSSIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRussian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRussian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_RUSSIAN__)*/

#if defined(__MMI_T9_RUSSIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRussian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRussian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_RUSSIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SERBIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_SERBIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSerbian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_SERBIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSerbian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SERBIAN__)*/

#if defined(__MMI_T9_SERBIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_SERBIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSerbian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_SERBIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSerbian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_SERBIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SESOTHO__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_SESOTHO,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSesotho,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_SESOTHO,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSesotho,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SESOTHO__)*/

#if defined(__MMI_T9_SESOTHO__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_SESOTHO,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSesotho,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_SESOTHO,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSesotho,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_SESOTHO__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SLOVAK__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSlovak,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSlovak,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SLOVAK__)*/

#if defined(__MMI_T9_SLOVAK__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_SLOVAK,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSlovak,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_SLOVAK,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSlovak,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_SLOVAK__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SLOVENIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSlovenian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSlovenian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SLOVENIAN__)*/

#if defined(__MMI_T9_SLOVENIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSlovenian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSlovenian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_SLOVENIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SPANISH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSpanish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSpanish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SPANISH__)*/

#if defined(__MMI_T9_SPANISH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSpanish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSpanish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_SPANISH__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SWAHILI__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSwahili,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSwahili,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SWAHILI__)*/

#if defined(__MMI_T9_SWAHILI__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_SWAHILI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSwahili,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_SWAHILI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSwahili,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_SWAHILI__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SWEDISH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSwedish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSwedish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_SWEDISH__)*/

#if defined(__MMI_T9_SWEDISH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_SWEDISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSwedish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_SWEDISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSwedish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_SWEDISH__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_TAGALOG__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_TAGALOG,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTagalog,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_TAGALOG,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTagalog,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_TAGALOG__)*/

#if defined(__MMI_T9_TAGALOG__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_TAGALOG,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTagalog,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_TAGALOG,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTagalog,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_TAGALOG__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_TURKISH__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTurkish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTurkish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_TURKISH__)*/

#if defined(__MMI_T9_TURKISH__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_TURKISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTurkish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTurkish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_TURKISH__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_UKRAINIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDUkrainian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDUkrainian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_UKRAINIAN__)*/

#if defined(__MMI_T9_UKRAINIAN__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDUkrainian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDUkrainian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_UKRAINIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_VIETNAMESE__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDVietnamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDVietnamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_VIETNAMESE__)*/

#if defined(__MMI_T9_VIETNAMESE__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDVietnamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDVietnamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_VIETNAMESE__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_XHOSA__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_XHOSA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDXhosa,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDXhosa,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_XHOSA__)*/

#if defined(__MMI_T9_XHOSA__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_XHOSA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDXhosa,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_XHOSA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDXhosa,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_XHOSA__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_YORUBA__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_YORUBA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDYoruba,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_YORUBA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDYoruba,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_YORUBA__)*/

#if defined(__MMI_T9_YORUBA__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_YORUBA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDYoruba,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_YORUBA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDYoruba,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_YORUBA__) */

#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ZULU__)
    {   
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ZULU,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDZulu,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDZulu,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_YORUBA__)*/

#if defined(__MMI_T9_ZULU__)
    {   
        IMM_INPUT_MODE_SMART_UPPERCASE_ZULU,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDZulu,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        IMM_INPUT_MODE_SMART_LOWERCASE_ZULU,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDZulu,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_YORUBA__) */
/* Languages with single wrtiting case */
#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ARABIC__)
    {   
        IMM_INPUT_MODE_MULTITAP_ARABIC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDArabic,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ARABIC__)*/

#if defined(__MMI_T9_ARABIC__)
    {   
        IMM_INPUT_MODE_SMART_ARABIC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDArabic,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_ARABIC__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ASSAMESE__)
    {   
        IMM_INPUT_MODE_MULTITAP_ASSAMESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAssamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ASSAMESE__)*/

#if defined(__MMI_T9_ASSAMESE__)
    {   
        IMM_INPUT_MODE_SMART_ASSAMESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDAssamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS ,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_ASSAMESE__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_BENGALI__)
    {   
        IMM_INPUT_MODE_MULTITAP_BENGALI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDBengali,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_BENGALI__)*/

#if defined(__MMI_T9_BENGALI__)
    {   
        IMM_INPUT_MODE_SMART_BENGALI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDBengali,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS ,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_BENGALI__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_GEORGIAN__)
    {   
        IMM_INPUT_MODE_MULTITAP_GEORGIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGeorgian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_GEORGIAN__)*/

#if defined(__MMI_T9_GEORGIAN__)
    {   
        IMM_INPUT_MODE_SMART_GEORGIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGeorgian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_GEORGIAN__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_GUJARATI__)
    {   
        IMM_INPUT_MODE_MULTITAP_GUJARATI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGujarati,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_GUJARATI__)*/

#if defined(__MMI_T9_GUJARATI__)
    {   
        IMM_INPUT_MODE_SMART_GUJARATI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDGujarati,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS ,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_GUJARATI__) */

#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_KHMER__)
    {   
        IMM_INPUT_MODE_MULTITAP_KHMER,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDKhmer,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_KHMER__)*/

#if defined(__MMI_T9_KHMER__)
    {   
        IMM_INPUT_MODE_SMART_KHMER,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDKhmer,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS ,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_KHMER__) */

#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_HEBREW__)
    {   
        IMM_INPUT_MODE_MULTITAP_HEBREW,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHebrew,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_HEBREW__)*/

#if defined(__MMI_T9_HEBREW__)
    {   
        IMM_INPUT_MODE_SMART_HEBREW,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHebrew,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_HEBREW__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_HINDI__)
    {   
        IMM_INPUT_MODE_MULTITAP_HINDI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHindi,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_HINDI__)*/

#if defined(__MMI_T9_HINDI__)
    {   
        IMM_INPUT_MODE_SMART_HINDI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHindi,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS ,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_HINDI__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_KANNADA__)
    {   
        IMM_INPUT_MODE_MULTITAP_KANNADA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDKannada,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_KANNADA__)*/

#if defined(__MMI_T9_KANNADA__)
    {   
        IMM_INPUT_MODE_SMART_KANNADA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDKannada,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_KANNADA__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_MALAYALAM__)
    {   
        IMM_INPUT_MODE_MULTITAP_MALAYALAM,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMalayalam,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_MALAYALAM__)*/

#if defined(__MMI_T9_MALAYALAM__)
    {   
        IMM_INPUT_MODE_SMART_MALAYALAM,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMalayalam,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS ,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_MALAYALAM__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_MARATHI__)
    {   
        IMM_INPUT_MODE_MULTITAP_MARATHI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMarathi,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_MARATHI__)*/

#if defined(__MMI_T9_MARATHI__)
    {   
        IMM_INPUT_MODE_SMART_MARATHI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMarathi,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_MARATHI__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ORIYA__)
    {   
        IMM_INPUT_MODE_MULTITAP_ORIYA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDOriya,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_ORIYA__)*/

#if defined(__MMI_T9_ORIYA__)
    {   
        IMM_INPUT_MODE_SMART_ORIYA,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDOriya,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS ,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_ORIYA__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_PUNJABI__)
    {   
        IMM_INPUT_MODE_MULTITAP_PUNJABI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPunjabi,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_PUNJABI__)*/

#if defined(__MMI_T9_PUNJABI__)
    {   
        IMM_INPUT_MODE_SMART_PUNJABI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPunjabi,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS ,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_PUNJABI__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_TAMIL__)
    {   
        IMM_INPUT_MODE_MULTITAP_TAMIL,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTamil,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_TAMIL__)*/

#if defined(__MMI_T9_TAMIL__)
    {   
        IMM_INPUT_MODE_SMART_TAMIL,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTamil,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_TAMIL__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_TELUGU__)
    {   
        IMM_INPUT_MODE_MULTITAP_TELUGU,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTelugu,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_TELUGU__)*/

#if defined(__MMI_T9_TELUGU__)
    {   
        IMM_INPUT_MODE_SMART_TELUGU,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDTelugu,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS ,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_TELUGU__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_THAI__)
    {   
        IMM_INPUT_MODE_MULTITAP_THAI,
        g_t9_keys_thai,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDThai,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_THAI__)*/

#if defined(__MMI_T9_THAI__)
    {   
        IMM_INPUT_MODE_SMART_THAI,
        g_t9_keys_thai,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDThai,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_KEYS,
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_THAI__) */


#if defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_URDU__)
    {   
        IMM_INPUT_MODE_MULTITAP_URDU,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDUrdu,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /*defined(__MMI_T9_MULTITAP__) && defined(__MMI_MULTITAP_URDU__)*/

#if defined(__MMI_T9_URDU__)
    {   
        IMM_INPUT_MODE_SMART_URDU,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDUrdu,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_t9_get_associates_alphabetic,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_URDU__) */

    {
        IMM_INPUT_MODE_MAX_NUM,
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

#if defined(__MMI_MIXED_LANG_SUPPORT__)
mmi_ime_t9_writing_lang_ldb_map_struct  writing_lang_ldb_map[]=
{
#if defined(__MMI_T9_AFRIKAANS__)
    {IME_WRITING_LANG_AF,T9PIDAfrikaans},
#endif
#if defined(__MMI_T9_ALBANIAN__)
    {IME_WRITING_LANG_SQ,T9PIDAlbanian},
#endif
#if defined(__MMI_T9_AZERBAIJANI__)
    {IME_WRITING_LANG_AZ,T9PIDAzerbaijani},
#endif
#if defined(__MMI_T9_BASQUE__)
    {IME_WRITING_LANG_EU,T9PIDBasque},
#endif
#if defined(__MMI_T9_BULGARIAN__)
    {IME_WRITING_LANG_BG,T9PIDBulgarian},
#endif
#if defined(__MMI_T9_CATALAN__)
    {IME_WRITING_LANG_CA,T9PIDCatalan},
#endif
#if defined(__MMI_T9_CROATIAN__)
    {IME_WRITING_LANG_SH,T9PIDCroatian},
#endif
#if defined(__MMI_T9_CZECH__)
    {IME_WRITING_LANG_CS,T9PIDCzech},
#endif
#if defined(__MMI_T9_DANISH__)
    {IME_WRITING_LANG_DA,T9PIDDanish},
#endif
#if defined(__MMI_T9_DUTCH__)
    {IME_WRITING_LANG_NL,T9PIDDutch},
#endif
#if defined(__MMI_T9_ENGLISH__)
    {IME_WRITING_LANG_ABC,T9PIDEnglish},
#endif
#if defined(__MMI_T9_ESTONIAN__)
    {IME_WRITING_LANG_ES,T9PIDEstonian},
#endif
#if defined(__MMI_T9_FINNISH__)
    {IME_WRITING_LANG_FI,T9PIDFinnish},
#endif
#if defined(__MMI_T9_FRENCH__)
    {IME_WRITING_LANG_FR,T9PIDFrench},
#endif
#if defined(__MMI_T9_GALICIAN__)
    {IME_WRITING_LANG_GA,T9PIDGalician},
#endif
#if defined(__MMI_T9_GERMAN__)
    {IME_WRITING_LANG_DE,T9PIDGerman},
#endif
#if defined(__MMI_T9_PERSIAN__)
    {IME_WRITING_LANG_PS,T9PIDFarsi},
#endif
#if defined(__MMI_T9_KOREAN__)
    {IME_WRITING_LANG_KR,T9PIDKorean},
#endif
#if defined(__MMI_T9_GREEK__)
    {IME_WRITING_LANG_EL,T9PIDGreek},
#endif
#if defined(__MMI_T9_HAUSA__)
    {IME_WRITING_LANG_HA,T9PIDHausa},
#endif
#if defined(__MMI_T9_HUNGARIAN__)
    {IME_WRITING_LANG_HU,T9PIDHungarian},
#endif
#if defined(__MMI_T9_ICELANDIC__)
    {IME_WRITING_LANG_IS,T9PIDIcelandic},
#endif
#if defined(__MMI_T9_IGBO__)
    {IME_WRITING_LANG_IG,T9PIDIgbo},
#endif
#if defined(__MMI_T9_INDONESIAN__)
    {IME_WRITING_LANG_ID,T9PIDIndonesian},
#endif
#if defined(__MMI_T9_IRISH__)
    {IME_WRITING_LANG_GL,T9PIDIrish},
#endif
#if defined(__MMI_T9_ITALIAN__)
    {IME_WRITING_LANG_IT,T9PIDItalian},
#endif
#if defined(__MMI_T9_KAZAKH__)
    {IME_WRITING_LANG_KK,T9PIDKazakh},
#endif
#if defined(__MMI_T9_LATVIAN__)
    {IME_WRITING_LANG_LV,T9PIDLatvian},
#endif
#if defined(__MMI_T9_LITHUANIAN__)
    {IME_WRITING_LANG_LT,T9PIDLithuanian},
#endif
#if defined(__MMI_T9_MACEDONIAN__)
    {IME_WRITING_LANG_MK,T9PIDMacedonian},
#endif
#if defined(__MMI_T9_MALAY__)
    {IME_WRITING_LANG_MS,T9PIDMalay},
#endif
#if defined(__MMI_T9_NORWEGIAN__)
    {IME_WRITING_LANG_NO,T9PIDNorwegian},
#endif
#if defined(__MMI_T9_POLISH__)
    {IME_WRITING_LANG_PL,T9PIDPolish},
#endif
#if defined(__MMI_T9_PORTUGUESE__)
    {IME_WRITING_LANG_PT,T9PIDPortuguese},
#endif
#if defined(__MMI_T9_ROMANIAN__)
    {IME_WRITING_LANG_RO,T9PIDRomanian},
#endif
#if defined(__MMI_T9_RUSSIAN__)
    {IME_WRITING_LANG_RU,T9PIDRussian},
#endif
#if defined(__MMI_T9_SERBIAN__)
    {IME_WRITING_LANG_SR,T9PIDSerbian},
#endif
#if defined(__MMI_T9_SESOTHO__)
    {IME_WRITING_LANG_ST,T9PIDSesotho},
#endif
#if defined(__MMI_T9_SLOVAK__)
    {IME_WRITING_LANG_SK,T9PIDSlovak},
#endif
#if defined(__MMI_T9_SLOVENIAN__)
    {IME_WRITING_LANG_SL,T9PIDSlovenian},
#endif
#if defined(__MMI_T9_SPANISH__)
    {IME_WRITING_LANG_ES,T9PIDSpanish},
#endif
#if defined(__MMI_T9_SWAHILI__)
    {IME_WRITING_LANG_SW,T9PIDSwahili},
#endif
#if defined(__MMI_T9_SWEDISH__)
    {IME_WRITING_LANG_SV,T9PIDSwedish},
#endif
#if defined(__MMI_T9_TAGALOG__)
    {IME_WRITING_LANG_TL,T9PIDTagalog},
#endif
#if defined(__MMI_T9_TURKISH__)
    {IME_WRITING_LANG_TR,T9PIDTurkish},
#endif
#if defined(__MMI_T9_UKRAINIAN__)
    {IME_WRITING_LANG_UK,T9PIDUkrainian},
#endif
#if defined(__MMI_T9_VIETNAMESE__)
    {IME_WRITING_LANG_VI,T9PIDVietnamese},
#endif
#if defined(__MMI_T9_XHOSA__)
    {IME_WRITING_LANG_XH,T9PIDXhosa},
#endif
#if defined(__MMI_T9_YORUBA__)
    {IME_WRITING_LANG_YO,T9PIDYoruba},
#endif
#if defined(__MMI_T9_ZULU__)
    {IME_WRITING_LANG_ZU,T9PIDZulu},
#endif
#if defined(__MMI_T9_ARABIC__)
    {IME_WRITING_LANG_AR,T9PIDArabic},
#endif
#if defined(__MMI_T9_ASSAMESE__)
    {IME_WRITING_LANG_AS,T9PIDAssamese},
#endif
#if defined(__MMI_T9_BENGALI__)
    {IME_WRITING_LANG_BE,T9PIDBengali},
#endif
#if defined(__MMI_T9_GEORGIAN__)
    {IME_WRITING_LANG_KA,T9PIDGeorgian},
#endif
#if defined(__MMI_T9_GUJARATI__)
    {IME_WRITING_LANG_GU,T9PIDGujarati},
#endif
#if defined(__MMI_T9_HEBREW__)
    {IME_WRITING_LANG_HE,T9PIDHebrew},
#endif
#if defined(__MMI_T9_HINDI__)
    {IME_WRITING_LANG_HI,T9PIDHindi},
#endif
#if defined(__MMI_T9_KANNADA__)
    {IME_WRITING_LANG_KN,T9PIDKannada},
#endif
#if defined(__MMI_T9_KHMER__)
    {IME_WRITING_LANG_KM,T9PIDKhmer},
#endif
#if defined(__MMI_T9_MALAYALAM__)
    {IME_WRITING_LANG_ML,T9PIDMalayalam},
#endif
#if defined(__MMI_T9_MARATHI__)
    {IME_WRITING_LANG_MR,T9PIDMarathi},
#endif
#if defined(__MMI_T9_ORIYA__)
    {IME_WRITING_LANG_OR,T9PIDOriya},
#endif
#if defined(__MMI_T9_PUNJABI__)
    {IME_WRITING_LANG_PA,T9PIDPunjabi},
#endif
#if defined(__MMI_T9_TAMIL__)
    {IME_WRITING_LANG_TA,T9PIDTamil},
#endif
#if defined(__MMI_T9_TELUGU__)
    {IME_WRITING_LANG_TE,T9PIDTelugu},
#endif
#if defined(__MMI_T9_THAI__)
    {IME_WRITING_LANG_TH,T9PIDThai},
#endif
#if defined(__MMI_T9_URDU__)
    {IME_WRITING_LANG_UR,T9PIDUrdu},
#endif

	{IME_WRITING_LANG_NONE, NULL}
};
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */
/*****************************************************************************
 * Local variables
 *****************************************************************************/

static mmi_ime_t9_word_engine_struct    g_engine; 

/*****************************************************************************
 * FUNCTION
 *  ime_init_engine
 * DESCRIPTION
 * Initializes input engine
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
    
    if ( g_engine.is_inited )
        return MMI_TRUE;

    memset( &g_engine, 0x0, sizeof(mmi_ime_t9_word_engine_struct) );    
    
    g_engine.is_inited = MMI_TRUE;
    g_engine.input_mode = IMM_INPUT_MODE_MAX_NUM;
    

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

    memset( &g_engine, 0x0, sizeof(mmi_ime_t9_word_engine_struct) );
    g_engine.input_mode = IMM_INPUT_MODE_MAX_NUM;
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
    g_engine.t9_mode_info = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_change_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_change_mode(const sIMEModeDetails * mode_details_ptr, U32 reserved )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    MMI_BOOL                ret_val = MMI_FALSE;
    mmi_ime_t9_mode_info_struct_p   mode_info_ptr;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if ( g_engine.is_inited == MMI_FALSE )
        return MMI_FALSE;

    if ( mode_details_ptr->imm_mode_id >= IMM_INPUT_MODE_MAX_NUM )
        return MMI_FALSE;
    
    mode_info_ptr = mmi_ime_t9_get_mode_info( mode_details_ptr->imm_mode_id );
    
    g_engine.t9_mode_info = NULL;
    
    if ( NULL == mode_info_ptr )
        return MMI_FALSE;

    g_engine.t9_mode_info = mode_info_ptr;
    
    switch ( mode_info_ptr->init_type )
    { 
    case MMI_IME_T9_INIT_TYPE_ALPHABETIC:
        ret_val = mmi_ime_t9_init_alphabetic(mode_info_ptr, (sIMEModeDetails *)mode_details_ptr);
        break;
#ifdef __T9_CHINESE        
    case MMI_IME_T9_INIT_TYPE_PHONETIC:
        ret_val = mmi_ime_t9_init_phonetic_chn(mode_info_ptr, (sIMEModeDetails *)mode_details_ptr);
        break;
        
    case MMI_IME_T9_INIT_TYPE_STROKE:
        ret_val = mmi_ime_t9_init_stroke_chn(mode_info_ptr, (sIMEModeDetails *)mode_details_ptr);
        break;
#endif        
    case MMI_IME_T9_INIT_TYPE_DIRECT:
        ret_val = mmi_ime_t9_init_number(mode_info_ptr, (sIMEModeDetails *)mode_details_ptr);
        break;
   #if defined __T9_KOREAN
    case     MMI_IME_T9_INIT_TYPE_KOREAN:
        ret_val = mmi_ime_t9_init_korean(mode_info_ptr, (sIMEModeDetails *)mode_details_ptr);
        break;
    #endif
    default:
        ret_val = MMI_FALSE;
        break;
    }


    if ( (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE) )
    {
        g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_UPPER;
    }
    else if ( mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE )
    {
        g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_LOWER;
    }
    else if ( mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE )
    {
        g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
    }
    else
    {
        g_engine.case_type = MMI_IME_WORD_CAPITAL_STATE_NONE;
    }

    
    if ( ret_val == MMI_FALSE )
    {
        return MMI_FALSE;
    }

    g_engine.key_map_ptr   = mode_info_ptr->key_map_ptr;
    g_engine.input_mode     = mode_details_ptr->imm_mode_id;
    
    return MMI_TRUE;
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

    if (g_engine.t9_mode_info)
    {
        if ( NULL != g_engine.t9_mode_info->get_spell_funcptr )
        {
            g_engine.t9_mode_info->get_spell_funcptr( param_ptr, result_ptr );
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

    if (g_engine.t9_mode_info)
    {
        if ( NULL != g_engine.t9_mode_info->get_assoc_funcptr )
        {
            g_engine.t9_mode_info->get_assoc_funcptr( param_ptr, result_ptr );
        }
    }
    
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

    if (g_engine.t9_mode_info)
    {
        if ( NULL != g_engine.t9_mode_info->get_cand_funcptr )
        {
            g_engine.t9_mode_info->get_cand_funcptr( param_ptr, result_ptr );
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
		switch(symbol)
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
        /* Klocwork */
        MMI_ASSERT(symbol <  MMI_IMC_SYMB_STROKE_MAX );
        return g_t9_unicodes_stroke[symbol  - MMI_IMC_SYMB_STROKE_BASE];
    }
#endif /* defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */
#if defined(__MMI_T9_SM_CHINESE__)
    else if (MMI_IMC_IS_SYMB_PY(symbol))
    {
         MMI_ASSERT(symbol <  MMI_IMC_SYMB_PY_MAX );
        return g_t9_codes_pinyin[symbol  - MMI_IMC_SYMB_PY_BASE];
    }
#endif /* #if defined(__MMI_T9_SM_CHINESE__) */
#if defined(__MMI_T9_TR_CHINESE__)
    else if (MMI_IMC_IS_SYMB_ZY(symbol))
    {
        MMI_ASSERT(symbol <  MMI_IMC_SYMB_ZY_MAX );
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
        if ( code >= 0x3105 && code <= 0x3129)
        {
            return code - 0x3105 + MMI_IMC_SYMB_ZY_B ;
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
 *  mmi_ime_word_set_context
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void  mmi_ime_word_set_context( U8 context )
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_valid_key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL  mmi_ime_word_is_valid_key( mmi_imm_input_mode_enum input_mode, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_t9_mode_info_struct_p  mode_info_p;
    U32 required_key;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_info_p = mmi_ime_t9_get_mode_info(input_mode);

    if (mode_info_p == NULL)
        return MMI_FALSE;

    required_key = mode_info_p->required_keys;
    
    switch(key_code)
    {
    case KEY_LSK:
    case KEY_RSK:
    case KEY_CSK:
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
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_symbol_key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL  mmi_ime_word_is_symbol_key( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
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
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_engine_get_char_info
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_engine_get_char_info(UI_character_type code, UI_string_type info_buffer, S32 buffer_size, mmi_imm_input_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_t9_mode_info_struct_p   mode_info_ptr;
    sIMEModeDetails * mode_details_ptr;
    MMI_BOOL ret_val = MMI_FALSE;
    UI_character_type temp_string[2];
    T9STATUS    sStatus;
    S32 i=0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_details_ptr = (sIMEModeDetails *)mmi_imm_get_input_mode_array_item(mode);

    if (mode_details_ptr == NULL)
        return  MMI_FALSE; /* the mode passed is not enabled */

    switch(mode)
    {
    case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:
    case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:
    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:
    case IMM_INPUT_MODE_TR_BOPOMO:
    case IMM_INPUT_MODE_SM_PINYIN:
    case IMM_INPUT_MODE_SM_STROKE:
    case IMM_INPUT_MODE_TR_STROKE:
    case IMM_INPUT_MODE_HK_STROKE:
        mode_info_ptr = mmi_ime_t9_get_mode_info(mode);
        break;

    default:
        return MMI_FALSE;
        
    }

    MMI_ASSERT(mode_info_ptr != NULL);
    
    switch ( mode_info_ptr->init_type )
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

    temp_string[0] = code;
    temp_string[1] = 0;
        
    switch(mode)
    {
#ifdef __T9_CHINESE
    case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:
    case IMM_INPUT_MODE_TR_BOPOMO:
    case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:
    case IMM_INPUT_MODE_SM_PINYIN:

        sStatus = T9CCGetCharSpell(&g_engine.data.field_info.CCFieldInfo, temp_string, 0);

		if (sStatus == T9STATNONE)
		{
			while (i < buffer_size - 1)
			{
				info_buffer[i] = mmi_ime_t9_t9code_to_code(g_engine.data.field_info.CCFieldInfo.pbSpellBuf[i], mode);
				i++;
			}
			
			info_buffer[i] = 0;
		}
        break;
        
    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:
    case IMM_INPUT_MODE_SM_STROKE:
    case IMM_INPUT_MODE_TR_STROKE:
    case IMM_INPUT_MODE_HK_STROKE:

        
        sStatus = T9CCGetCharStrokes(&g_engine.data.field_info.CCFieldInfo, temp_string, 0);

		if (sStatus == T9STATNONE)
		{
			while (i < buffer_size - 1)
			{
				info_buffer[i] = mmi_ime_t9_t9code_to_code(g_engine.data.field_info.CCFieldInfo.pbKeyBuf[i], mode);
				i++;
			}
			
			info_buffer[i] = 0;
		}
		
        break;
#endif
    default:
        return MMI_FALSE;
        
    }

	mode_details_ptr = (sIMEModeDetails *)mmi_imm_get_input_mode_array_item(g_engine.input_mode);

	if (mode_details_ptr)
    {
        /* Resume current input mode */
        mmi_ime_word_change_mode(mode_details_ptr, 0); 
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
 *  mmi_ime_word_change_word_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void   mmi_ime_word_change_word_case(mmi_ime_word_capital_state_enum capital_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_engine.case_type = capital_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_map_char_to_symbol
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_imc_symbol_key_enum mmi_ime_word_map_char_to_symbol(mmi_imm_input_mode_enum input_mode, UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails      *mode_info_ptr = NULL;
    mmi_ime_t9_mode_info_struct_p   t9_mode_info_ptr = NULL;
    T9STATUS sStatus;
    T9AuxType t9_sym_key;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_info_ptr = mmi_imm_get_input_mode_array_item(input_mode);

    if ( NULL == mode_info_ptr )
        return MMI_IMC_SYMB_KEY_INVALID;

    t9_mode_info_ptr = mmi_ime_t9_get_mode_info( mode_info_ptr->imm_mode_id );

    if ( NULL == t9_mode_info_ptr )
        return MMI_IMC_SYMB_KEY_INVALID;

    if ( t9_mode_info_ptr->init_type != MMI_IME_T9_INIT_TYPE_ALPHABETIC )
        return MMI_IMC_SYMB_KEY_INVALID;

    if (t9_mode_info_ptr->nLdbNum != g_engine.t9_mode_info->nLdbNum)
    {
        sStatus = T9AWSetLanguage( &(g_engine.data.field_info.AWFieldInfo), t9_mode_info_ptr->nLdbNum, &(g_engine.data.field_info.AWFieldInfo.G), NULL );

        if (sStatus != T9STATNONE)
        {
            return MMI_IMC_SYMB_KEY_INVALID;
        }
    }

    sStatus = T9GetKeyForSym(&(g_engine.data.field_info.AWFieldInfo.G), (T9SYMB)char_code, &t9_sym_key);

    if (t9_mode_info_ptr->nLdbNum != g_engine.t9_mode_info->nLdbNum)
    {
        sStatus = T9AWSetLanguage( &(g_engine.data.field_info.AWFieldInfo), g_engine.t9_mode_info->nLdbNum, &(g_engine.data.field_info.AWFieldInfo.G), NULL );

        if (sStatus != T9STATNONE)
        {
            return MMI_IMC_SYMB_KEY_INVALID;
        }
    }

    if ((sStatus != T9STATNONE ) && (sStatus != T9STATNOWRD))
    {
        return MMI_IMC_SYMB_KEY_INVALID;
    }
    if (t9_sym_key >= T9KEYAMBIG1 && t9_sym_key <= T9KEYAMBIG9)
    {
        
		return (mmi_imc_symbol_key_enum)(t9_sym_key - T9KEYAMBIG1 + MMI_IMC_SYMB_KEY_1);
    }
    else if (t9_sym_key == T9KEYAMBIGA)
    {
        return MMI_IMC_SYMB_KEY_0;
    }
	else if (t9_sym_key == T9KEYAMBIGB)
    {
        return MMI_IMC_SYMB_KEY_STAR;
    }
	else if (t9_sym_key == T9KEYAMBIGC)
    {
        return MMI_IMC_SYMB_KEY_POUND;
    }
    else
    {
        return MMI_IMC_SYMB_KEY_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_t9code_to_code
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static UI_character_type mmi_ime_t9_t9code_to_code(T9U8 t9code, mmi_imm_input_mode_enum mode)
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
    case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
    case IMM_INPUT_MODE_SM_PINYIN:
    case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:
        return (UI_character_type)t9code;
        

#ifdef __MMI_T9_TR_CHINESE__

    case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
    case IMM_INPUT_MODE_TR_BOPOMO:
	case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:
        
        while(i < MMI_IMC_SYMB_ZY_MAX - MMI_IMC_SYMB_ZY_BASE)
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
        
#endif /* __MMI_T9_TR_CHINESE__ */

#ifdef __T9_CHINESE
    case IMM_INPUT_MODE_TR_STROKE:
    case IMM_INPUT_MODE_HK_STROKE:
    case IMM_INPUT_MODE_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:

        while(i < MMI_IMC_SYMB_STROKE_MAX - MMI_IMC_SYMB_STROKE_BASE)
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
 * RETURNS
 *****************************************************************************/
static mmi_ime_t9_mode_info_struct_p   mmi_ime_t9_get_mode_info(mmi_imm_input_mode_enum input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U8  i;
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
    const sIMEModeDetails * mode_details_ptr;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( input_mode >= IMM_INPUT_MODE_MAX_NUM )
        return NULL;

#if defined(__MMI_SMART_FIRST_UPPERCASE__)

    mode_details_ptr = mmi_imm_get_input_mode_array_item(input_mode);
    
    if (!mode_details_ptr)
    {
        return NULL;
    }

    if ((mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
        && (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART))
    {
        mode_details_ptr = mmi_imm_get_corresponding_smart_lower_case_mode(input_mode);

        if (mode_details_ptr)
        {
            input_mode = mode_details_ptr->imm_mode_id;
        }
        else
        {
            return NULL;
        }
    }

#endif /* defined(__MMI_SMART_FIRST_UPPERCASE__) */

    for ( i = 0; g_mode_infos[i].input_mode != IMM_INPUT_MODE_MAX_NUM; ++i )
    {
        if ( g_mode_infos[i].input_mode == input_mode )
            return (mmi_ime_t9_mode_info_struct_p)&g_mode_infos[i];
    }

    return NULL;
}





/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_init_number
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_number( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr)
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
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_stroke_chn( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    T9STATUS    sStatus;

    T9CCFieldInfo   *pCCFieldInfo;
    mmi_ime_t9_data_struct_p pDataBuff;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sStatus = T9STATNONE;


    pDataBuff = &g_engine.data;
    pCCFieldInfo = &g_engine.data.field_info.CCFieldInfo;

    memset(pCCFieldInfo, 0, sizeof(T9CCFieldInfo));
    sStatus = T9CCInitialize( pCCFieldInfo, pDataBuff->text_buff, pDataBuff->aux_buff, MMI_IME_T9_MAX_TEXT_BUFFSIZE, 0,
                (T9HandleRequest_f)T9_handle_request, T9CCSELECTPAGEMAXSIZE, (T9CCLoadLdb_f)T9CCLoadLdb );
    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetLanguage( pCCFieldInfo, t9_mode_info->nLdbNum, NULL, NULL );
    }

    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetDynCtxtFence( pCCFieldInfo, MMI_IME_T9_DYNAMIC_CONTEXT_FENCE );
    }
    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetDynCtxtSearchDepth( pCCFieldInfo, MMI_IME_T9_DYNAMIC_CONTEXT_SEARCH_DEPTH );
    }
    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetStrokeMode( pCCFieldInfo );
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
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_phonetic_chn( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    T9STATUS sStatus;
    
    T9CCFieldInfo   *pCCFieldInfo;
    mmi_ime_t9_data_struct_p pDataBuff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sStatus = T9STATNONE;

    pDataBuff = &g_engine.data;
    pCCFieldInfo = &g_engine.data.field_info.CCFieldInfo;
    
    memset(pCCFieldInfo, 0, sizeof(T9CCFieldInfo));
    sStatus = T9CCInitialize( pCCFieldInfo, pDataBuff->text_buff, pDataBuff->aux_buff, MMI_IME_T9_MAX_TEXT_BUFFSIZE, 0,
                    (T9HandleRequest_f)T9_handle_request, T9CCSELECTPAGEMAXSIZE, (T9CCLoadLdb_f)T9CCLoadLdb );
    if ( sStatus == T9STATNONE )
    {
        sStatus = T9CCSetLanguage( pCCFieldInfo, t9_mode_info->nLdbNum, NULL, NULL );
    }

    if ( sStatus == T9STATNONE )
    {
        sStatus = T9CCSetDynCtxtFence( pCCFieldInfo, MMI_IME_T9_DYNAMIC_CONTEXT_FENCE);
    }
    if ( sStatus == T9STATNONE )
    {
        sStatus = T9CCSetDynCtxtSearchDepth( pCCFieldInfo, MMI_IME_T9_DYNAMIC_CONTEXT_SEARCH_DEPTH );
    }
    if ( sStatus == T9STATNONE )
    {
        if ( mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP ) // multitap pinyin or smart bopomofo
        {
            if ( sStatus == T9STATNONE )
            {
                sStatus = T9CCSetMultitapSpellMode( pCCFieldInfo );
            }
            if ( sStatus == T9STATNONE )
            {
                sStatus = T9CCSetMultitapSelListUpdate( pCCFieldInfo );
            }
        }
        else if ( mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART ) // smart pinyin or smart bopomofo
        {
            if ( sStatus == T9STATNONE )
            {
                sStatus = T9CCSetAmbigSpellMode( pCCFieldInfo );
            }
            if ( sStatus == T9STATNONE )
            {
                sStatus = T9CCClrAutoSpell( pCCFieldInfo );
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
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_alphabetic( mmi_ime_t9_mode_info_struct_p t9_mode_info, sIMEModeDetails *mode_detail_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    T9STATUS    sStatus = T9STATNONE;

    T9AWFieldInfo   *pAWFieldInfo;
    mmi_ime_t9_data_struct_p pDataBuff;

#if defined(__MMI_MIXED_LANG_SUPPORT__)
    mmi_imm_input_mode_enum             sub_lang = IME_WRITING_LANG_NONE;
    T9UINT    t9_sub_lang_ldb_num ;
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    pDataBuff = &g_engine.data;
    pAWFieldInfo = &g_engine.data.field_info.AWFieldInfo;
    
    memset(pAWFieldInfo, 0, sizeof(T9AWFieldInfo));
    
    sStatus = T9AWInitialize( pAWFieldInfo, pDataBuff->text_buff, pDataBuff->aux_buff, MMI_IME_T9_MAX_TEXT_BUFFSIZE, 0,
                                (T9HandleRequest_f)T9_handle_request, (T9ReadLdbData_f)T9ReadLdbData );
    
    if ( sStatus == T9STATNONE )
    {
        sStatus = T9AWSetLanguage( pAWFieldInfo, t9_mode_info->nLdbNum, &pAWFieldInfo->G, NULL );
    }

#if defined(__MMI_MIXED_LANG_SUPPORT__)
    sub_lang = mmi_imm_get_sub_lang();

/* to initialize sub language ,In case no sub language , ldb for sub language is set to 0*/
   if (sub_lang != NULL)
    {
        t9_sub_lang_ldb_num = mmi_ime_t9_get_lang_ldb(sub_lang);
/* To make sure that for the languages for which we are not supporting mixed lang..sub language is cleared */
        if ( t9_sub_lang_ldb_num != NULL && (mode_detail_ptr->Lang_Special_Attrib & IME_LANG_ATTR_MIXED_LANG_SUPPORT))
        {
             sStatus = T9AWAddLanguage (pAWFieldInfo,t9_sub_lang_ldb_num,0);
        }
        else
        {
             sStatus = T9AWRemoveLanguage(pAWFieldInfo,0);
        }
    }
#endif
    if ( sStatus == T9STATNONE )
    {
        if ( mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP ) // multitap input method
        {
            sStatus = T9AWSetMultitapMode( pAWFieldInfo);
        }
        else if ( mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART ) // smart input method
        {
            sStatus = T9AWClrMultitapMode( pAWFieldInfo);
        }
    }
    if ( sStatus == T9STATNONE )
    {
	#if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_SMART_FIRST_UPPERCASE__)

		sStatus = T9AWClrCapState( pAWFieldInfo );

    #else
        if ( mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE ) // upper case
        {
            sStatus = T9AWSetCapState( pAWFieldInfo );
        }
        else if ( mode_detail_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE ) // lower case
        {
            sStatus = T9AWClrCapState( pAWFieldInfo );
        }
    #endif /* #if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_SMART_FIRST_UPPERCASE__) */
        
    }

    if (mmi_imm_is_auto_completion_enabled())
    {
        T9AWSetLdbCompletion(pAWFieldInfo);
    }
    else
    {
        T9AWClrLdbCompletion(pAWFieldInfo);
    }

#if defined(__MMI_IME_USER_DATABASE__)

    sStatus = T9AWUdbActivate(&g_engine.data.field_info.AWFieldInfo, 
                             (T9AWUdbInfo T9FARUDBPOINTER *)&g_engine.data.udb_data[0],
                             MMI_IME_T9_UDB_SIZE,
                             T9AWDEFAULTUDBFENCE,
                             T9SCUnicode);

    if (sStatus != T9STATNONE)
    {
        return (MMI_BOOL)sStatus;
    }

    sStatus = T9AWCdbActivate(&g_engine.data.field_info.AWFieldInfo, 
                             (T9AWCdbInfo T9FARUDBPOINTER *)&g_engine.data.cdb_data[0],
                             MMI_IME_T9_CDB_SIZE,
                             T9SCUnicode);

    if (sStatus != T9STATNONE)
    {
        return (MMI_BOOL)sStatus;
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
 * RETURNS
 *****************************************************************************/
static void  mmi_ime_t9_get_candidates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
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
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    
    if ( 0 == param_ptr->elembuf_cnt )
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
            sStatus = T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, (T9KEY)t9_key);

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
    
    #if defined(__MMI_INDIC_ALG__) 
        if (t9_key == T9KEYAMBIGA  && g_engine.input_mode != IMM_INPUT_MODE_SMART_THAI )
         {
            result_ptr->result_buffer[0] = 0x20;
            result_ptr->result_buffer[1] = 0;

            temp_ptr = result_ptr->result_buffer;
            temp_ptr = temp_ptr + 2;
            cnt++;
          }
    #endif

    while (j < param_ptr->desired_cnt && j < cnt - i)
    {
		can_len = g_engine.data.field_info.AWFieldInfo.G.nWordLen + g_engine.data.field_info.AWFieldInfo.G.nComplLen;

		if (param_ptr->elembuf_cnt > can_len)
		{
			can_len = param_ptr->elembuf_cnt;
		}

		/*the below check is to skip the adding of candidates if the buffer gets full*/
		if ((((param_ptr->elembuf_cnt * sizeof(UI_character_type))+2)*j ) > MMI_IMC_MAX_CANDIDATE_BUFFSIZE)
		break;

        memcpy(temp_ptr, g_engine.data.field_info.AWFieldInfo.G.psTxtBuf, can_len * sizeof(UI_character_type));

        temp_ptr += can_len; 

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

#if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_SMART_FIRST_UPPERCASE__)
    if ( result_ptr->result_cnt > 0 )
    {
        mmi_ime_t9_change_candidates_case(result_ptr);
    }
#endif 

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

#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_associates_alphabetic
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_associates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS sStatus = T9STATERROR;
    T9UINT cnt = 0;
    S32 i, str_len;
    T9SYMB *temp_ptr, *start_ptr;
    UI_string_type temp_result;
    T9FieldInfo *field_info = &g_engine.data.field_info.AWFieldInfo.G;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    if (param_ptr->first_index == 0)
    {
        str_len = mmi_ucs2strlen((const S8 *)param_ptr->pre_string);
 
    	if (mmi_ucs2nicmp((const S8 *)(field_info->psTxtBuf + field_info->nCursor - str_len - 1), (const S8 *)param_ptr->pre_string, str_len))
        {
            mmi_imc_symbol_key_enum symbol_key;
            T9MINOR t9_key;
            T9UINT cnt = 0;
            UI_string_type str_ptr = param_ptr->pre_string;

            if (!str_len)
            {
                return;
            }

            i = 0;

            do
            {
                symbol_key = mmi_ime_word_map_char_to_symbol(g_engine.t9_mode_info->input_mode, str_ptr[i]);

                if (symbol_key != MMI_IMC_SYMB_KEY_INVALID)
                {
                    t9_key = mmi_ime_t9_from_symb_to_t9key(symbol_key);

                    if (t9_key)
                    {
                        sStatus = T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, (T9KEY)t9_key);
                    }
                    else
                    {
                        return;
                    }
                }
                else
                {
                    return;
                }    

                i++;

            }while (i < str_len && sStatus == T9STATNONE);

            if (sStatus != T9STATNONE)
            {
                return;
            }

            sStatus = T9AWGetSLCount(&g_engine.data.field_info.AWFieldInfo, &cnt);
            
            if (sStatus != T9STATNONE)
            {
                return;
            }

            for (i = 0; i < cnt; i++)
            {
                /* Inform T9 we have confirmed this candidate by inject T9KEYSPACE */
                if (g_engine.data.field_info.AWFieldInfo.G.nWordLen != 0
                    && !mmi_ucs2nicmp((const S8 *) g_engine.data.field_info.AWFieldInfo.G.psTxtBuf, (const S8 *) str_ptr, str_len) 
                    && g_engine.data.field_info.AWFieldInfo.G.nWordLen + g_engine.data.field_info.AWFieldInfo.G.nComplLen == str_len)
                {
                    sStatus = T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, T9KEYSPACE);
                    
                    if (sStatus != T9STATNONE)
                    {
                        return;
                    }
                    else  
                    {
                        break;
                    }
                }
                else if (g_engine.data.field_info.AWFieldInfo.G.nWordLen == 0 
                    && !mmi_ucs2nicmp((const S8 *) (g_engine.data.field_info.AWFieldInfo.G.psTxtBuf + g_engine.data.field_info.AWFieldInfo.G.nCursor),  
                    (const S8 *) str_ptr, str_len) 
                    && g_engine.data.field_info.AWFieldInfo.G.nComplLen == str_len) /* For next word prediction mode */
                {
                    sStatus = T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, T9KEYSPACE);
                    
                    if (sStatus != T9STATNONE)
                    {
                        return;
                    }
                    else  
                    {
                        break;
                    }
                }
                else
                {
                    sStatus = T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, T9KEYNEXT);
                    
                    if (sStatus != T9STATNONE)
                    {
                        return;
                    }
                }
            }

            if (mmi_ucs2nicmp((const S8 *)(field_info->psTxtBuf + field_info->nCursor - str_len - 1), (const S8 *)param_ptr->pre_string, str_len))
            {
    		    return;
    	    }
    	}

        sStatus = T9AWGetSLCount(&g_engine.data.field_info.AWFieldInfo, &cnt);

        if (sStatus != T9STATNONE)
        {
            return;
        }

        g_engine.data.ass_alpha_count = cnt;

    	if ( *(field_info->psTxtBuf + field_info->nCursor - 1) == 0x20)
        {
            start_ptr = field_info->psTxtBuf + field_info->nCursor;
        }
        else
        {
            result_ptr->result_cnt = 0;
            result_ptr->next_page = MMI_FALSE;
            return;
        }	

        i = 0;
        
        while (i < cnt)
        {
            temp_ptr = start_ptr;
            
            memcpy(&g_engine.data.ass_alpha_cand[i][0], temp_ptr, field_info->nComplLen * sizeof(UI_character_type));

            g_engine.data.ass_alpha_cand[i][field_info->nComplLen] = 0;

            sStatus = T9HandleKey(field_info, T9KEYNEXT);
            
            i++;
        }

        if (cnt > param_ptr->desired_cnt)
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
    else if (param_ptr->first_index < g_engine.data.ass_alpha_count)
    {
        if (g_engine.data.ass_alpha_count - param_ptr->first_index > param_ptr->desired_cnt)
        {
            result_ptr->next_page = MMI_TRUE;
            result_ptr->result_cnt = param_ptr->desired_cnt;
        }
        else
        {
            result_ptr->next_page = MMI_FALSE;
            result_ptr->result_cnt = g_engine.data.ass_alpha_count - param_ptr->first_index;
        }
    }
    else
    {
        return;
    }
    
    temp_result = result_ptr->result_buffer;

    i = param_ptr->first_index;

    while(i - param_ptr->first_index < result_ptr->result_cnt)
    {
        str_len = mmi_ucs2strlen((const S8 *)&g_engine.data.ass_alpha_cand[i][0]);

        if (str_len > 0)
        {
            memcpy(temp_result, &g_engine.data.ass_alpha_cand[i][0], (str_len + 1) * sizeof(UI_character_type));
            temp_result += (str_len + 1);
        }

        i++;
    }

#if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_SMART_FIRST_UPPERCASE__)
    if ( result_ptr->result_cnt > 0 )
    {
        mmi_ime_t9_change_candidates_case(result_ptr);
    }
#endif
}
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_associates_alphabetic
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_associates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}
#endif /* #if defined(__MMI_IME_USER_DATABASE__) */


#if defined __T9_CHINESE
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_associates
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_associates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        T9STATUS sStatus = T9STATERROR;
        
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
        
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
    
        sStatus = T9AddExplicitChar(&g_engine.data.field_info.CCFieldInfo.G, param_ptr->pre_string[0]);

        if (sStatus != T9STATERROR)
        {
            mmi_ime_t9_get_candidates(param_ptr, result_ptr);
        }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_candidates
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_candidates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9UINT first_index, first_part_size;
    T9STATUS sStatus = T9STATERROR;
    UI_character_type candidate_buffer[T9CCSELECTPAGEMAXSIZE + 2];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    first_index = (T9UINT)param_ptr->first_index;

    result_ptr->next_page = MMI_FALSE;

    while (first_index >= g_engine.data.field_info.CCFieldInfo.nSelectPageLen)
    {
        first_index = first_index - g_engine.data.field_info.CCFieldInfo.nSelectPageLen;

        sStatus = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, T9KEYNEXT);
        
        if (T9STATNONE != sStatus )
	{
	    return;		
        }
    }

    first_part_size = g_engine.data.field_info.CCFieldInfo.nSelectPageLen - first_index;
    
    if (first_part_size > 0)
    {
        memcpy(candidate_buffer, &g_engine.data.field_info.CCFieldInfo.pwSelectPage[first_index], first_part_size * sizeof(UI_character_type)); // Single char candidate
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
	            memcpy(&candidate_buffer[first_part_size], g_engine.data.field_info.CCFieldInfo.pwSelectPage, 
	                   (g_engine.data.field_info.CCFieldInfo.nSelectPageMax - first_part_size) * sizeof(UI_character_type)); // Single char candidate
				
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
	            memcpy(&candidate_buffer[first_part_size], g_engine.data.field_info.CCFieldInfo.pwSelectPage, 
	                   g_engine.data.field_info.CCFieldInfo.nSelectPageLen * sizeof(UI_character_type)); // Single char candidate

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

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_stroke
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  i;
    U8  symb;
    UI_string_type temp_str;
    T9STATUS sStatus = T9STATERROR;
    T9MINOR  t9_key;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    
    if ( 0 == param_ptr->elembuf_cnt )
        return;
    
    temp_str = result_ptr->result_buffer;
    
    T9ResetTextBuf(&g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);
    
    for ( i = 0; i < param_ptr->elembuf_cnt; ++i )
    {
        symb = param_ptr->elembuf_ptr[i];
        t9_key = mmi_ime_t9_from_symb_to_t9key(symb);
        
        if ( MMI_FALSE != MMI_IMC_IS_SYMB_KEY(symb) )
        {
            if (t9_key)
            {
            	sStatus = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, (T9KEY)t9_key);
                
            	if (T9STATNONE != sStatus)
            	{
            	    return;
                }
                
                *temp_str = mmi_ime_word_symbol_to_code((U8)g_t9_keys_stroke[symb - MMI_IMC_SYMB_KEY_BASE]);
                temp_str++;
            }
            else /* Invalid key */
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
 *  mmi_ime_t9_get_spellings_stroke
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS sStatus = T9STATERROR;
    U8 i;
    U8  symb;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    
    T9ResetTextBuf( &g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);

    for ( i = 0; i < param_ptr->elembuf_cnt; ++i )
    {
        symb = param_ptr->elembuf_ptr[i];

        if (MMI_FALSE != MMI_IMC_IS_SYMB_STROKE(symb))
        {
            sStatus = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, (T9KEY)g_t9_codes_stroke[(mmi_imc_symb_stroke_enum)symb  - MMI_IMC_SYMB_STROKE_BASE]);
                        
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

    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
}

#endif /* #if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */


#if defined(__MMI_T9_SM_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_pinyin_multitap
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_pinyin_multitap( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
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

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

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

#endif /* #if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_T9_SMART_PHONETIC_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_pinyin_smart
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_pinyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U16          ret_val;
    U8          i;
    U16          j;
    U8          k;
    T9STATUS    status;
    T9MINOR     key_val;
    T9U8        *buff_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    
    result_ptr->result_cnt = 0;

    if ( MMI_FALSE == g_engine.is_inited )
        return ;
    
    status = T9ResetTextBuf( &g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);
    
    if ( T9STATNONE != status )
    {
        /* add error */
        return ;
    }

    for ( i = 0; i < param_ptr->elembuf_cnt; i++ )
    {
        key_val = mmi_ime_t9_from_symb_to_t9key(param_ptr->elembuf_ptr[i]);
        
        status = T9HandleKey( &g_engine.data.field_info.CCFieldInfo.G, (T9KEY) key_val );
        if ( T9STATNONE != status )
        {
            /* add error */
            return;
        }
    }

    status = T9CCGetSpell( &g_engine.data.field_info.CCFieldInfo);
    
    if ( status != T9STATNONE )
        return;

    ret_val = g_engine.data.field_info.CCFieldInfo.bSpellMatchFromLdb; /* Revise by UDB */
    
    if ( 0 == ret_val || param_ptr->first_index >= ret_val )
        return;

    /* calculate remaining candidates count */
    ret_val = ret_val - param_ptr->first_index;
    
    if ( ret_val > param_ptr->desired_cnt )
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
        for (j = 0; buff_ptr[i] != '\0' && k < result_ptr->result_cnt; )
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
#endif /* #if defined(__MMI_T9_SMART_PHONETIC_INPUT__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_candidates_pinyin
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_pinyin( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS    status;
    S32 i;
    U8 tone_value=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

	status = T9ResetTextBuf(&g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);

    if ( T9STATNONE != status )
    {
        /* add error */
        return ;
    }

    for (i =0; i < param_ptr->elembuf_cnt; i++)
    {
        if (MMI_IMC_IS_SYMB_PY(param_ptr->elembuf_ptr[i]))
        {
            status = T9CCAddExplicitSpellSym(&g_engine.data.field_info.CCFieldInfo, g_t9_codes_pinyin[param_ptr->elembuf_ptr[i] - MMI_IMC_SYMB_PY_BASE]);
        }
		else if (MMI_IMC_IS_SYMB_TONE(param_ptr->elembuf_ptr[i]) && i == param_ptr->elembuf_cnt - 1)
		{
		}
        else
        {
            return;
        }
        
        if ( T9STATNONE != status )
        {
            /* add error */
            return ;
        }
    }

	if (MMI_IMC_IS_SYMB_TONE(param_ptr->elembuf_ptr[param_ptr->elembuf_cnt - 1]))
	{
        tone_value = param_ptr->elembuf_ptr[param_ptr->elembuf_cnt - 1];
	}

	if (MMI_IMC_IS_SYMB_TONE(param_ptr->tone_value))
    {
        tone_value = param_ptr->tone_value;
	}
	else if (MMI_IMC_IS_SYMB_TONE(tone_value))
    {
        status = T9CCSetTone(&g_engine.data.field_info.CCFieldInfo, (T9KEY)g_t9_codes_tone[tone_value - MMI_IMC_SYMB_TONE_BASE]);
    }

    if ( T9STATNONE != status )
    {
        /* add error */
        return ;
    }

    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
}

#endif /* #if defined(__MMI_T9_SM_CHINESE__) */

#if defined(__MMI_T9_TR_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_zhuyin_multitap
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_zhuyin_multitap( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
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

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    if ( 0 == param_ptr->elembuf_cnt )
        return;

    temp_str = result_ptr->result_buffer;
    
    for ( i = 0; i < param_ptr->elembuf_cnt; i++ )
    {
        symb = param_ptr->elembuf_ptr[i];
        if ( MMI_FALSE != MMI_IMC_IS_SYMB_ZY( symb ) )
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
#endif /* #if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_zhuyin_smart
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_zhuyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16          ret_val;
    U8          i;
    U16         j;
    U8          k;
    T9STATUS    status;
    T9MINOR     key_val;
    T9U8        *buff_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );
    
    result_ptr->result_cnt = 0;

    if ( MMI_FALSE == g_engine.is_inited )
        return ;
    
    status = T9ResetTextBuf( &g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);
    
    if ( T9STATNONE != status )
    {
        /* add error */
        return ;
    }

    for ( i = 0; i < param_ptr->elembuf_cnt; i++ )
    {
        key_val = mmi_ime_t9_from_symb_to_t9key(param_ptr->elembuf_ptr[i]);
        
        status = T9HandleKey( &g_engine.data.field_info.CCFieldInfo.G, key_val );
        if ( T9STATNONE != status )
        {
            /* add error */
            return;
        }
    }

    status = T9CCGetSpell( &g_engine.data.field_info.CCFieldInfo);
    
    if ( status != T9STATNONE )
        return;

    ret_val = g_engine.data.field_info.CCFieldInfo.bSpellMatchFromLdb; /* Revise by UDB */
    
    if ( 0 == ret_val || param_ptr->first_index >= ret_val )
        return;

    /* calculate remaining candidates count */
    ret_val = ret_val - param_ptr->first_index;
    
    if ( ret_val > param_ptr->desired_cnt )
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
        for (j = 0; buff_ptr[i] != '\0' && k < result_ptr->result_cnt; )
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
#endif /* #if defined(__MMI_T9_SMART_PHONETIC_INPUT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_candidates_zhuyin
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_zhuyin( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS    status;
    S32 i;
    U8 tone_value=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT( param_ptr != NULL || result_ptr != NULL );

    status = T9ResetTextBuf(&g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);

    if ( T9STATNONE != status )
    {
        /* add error */
        return ;
    }

    for (i =0; i < param_ptr->elembuf_cnt; i++)
    {
        if (MMI_IMC_IS_SYMB_ZY(param_ptr->elembuf_ptr[i]))
        {
            status = T9CCAddExplicitSpellSym(&g_engine.data.field_info.CCFieldInfo, g_t9_codes_zhuyin[param_ptr->elembuf_ptr[i] - MMI_IMC_SYMB_ZY_BASE]);
        }
        else if (MMI_IMC_IS_SYMB_TONE(param_ptr->elembuf_ptr[i]) && i == param_ptr->elembuf_cnt - 1)
		{
		}
        else
        {
            return;
        }
        
        if ( T9STATNONE != status )
        {
            /* add error */
            return ;
        }
    }

	if (MMI_IMC_IS_SYMB_TONE(param_ptr->elembuf_ptr[param_ptr->elembuf_cnt - 1]))
	{
        tone_value = param_ptr->elembuf_ptr[param_ptr->elembuf_cnt - 1];
	}
	else if (MMI_IMC_IS_SYMB_TONE(param_ptr->tone_value))
	{
        tone_value = param_ptr->tone_value;
	}

	if (MMI_IMC_IS_SYMB_TONE(tone_value))
    {
        status = T9CCSetTone(&g_engine.data.field_info.CCFieldInfo, (T9KEY)g_t9_codes_tone[tone_value - MMI_IMC_SYMB_TONE_BASE]);
    }

    if ( T9STATNONE != status )
    {
        /* add error */
        return ;
    }

    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
}
#endif /* #if defined(__MMI_T9_TR_CHINESE__) */

/*****************************************************************************
 * FUNCTION
 *  T9_Handle_Request
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
T9STATUS T9_handle_request( T9FieldInfo *field_info_ptr, T9Request *request_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    T9STATUS status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch ( request_ptr->eType )
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
 * RETURNS
 *****************************************************************************/
static T9MINOR  mmi_ime_t9_from_symb_to_t9key( U16 symb_key )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( NULL == g_engine.key_map_ptr )
        return T9KEYNONE;

    if ( symb_key >= MMI_IMC_SYMB_KEY_0 && symb_key <= MMI_IMC_SYMB_KEY_POUND )
    {
        return g_engine.key_map_ptr[symb_key - MMI_IMC_SYMB_KEY_BASE];
    }

    return T9KEYNONE;
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
    return mmi_ime_word_is_symbol_key(g_engine.input_mode,(mmi_imc_key_custom_value) sym);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ime_multitap_vendor_get_string
 * DESCRIPTION
 * Function which returns multitap string for given key
 * PARAMETERS
 * S32 key pressed
 * RETURNS
 * UI_string_type multitap string mapped on input key
 *****************************************************************************/
 UI_string_type mmi_ime_multitap_vendor_get_string_ext(S32 index , S32 input_mode )
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
    
    status = T9GetMultitapTable( &g_engine.data.field_info.AWFieldInfo.G,(T9KEY) t9key, 1, MMI_MULTITAP_T9_PAGE_BUFFSIZE, page_ptr, &ret_val );

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
    
    status = T9GetMultitapTable( &g_engine.data.field_info.AWFieldInfo.G,(T9KEY) t9key, 1, MMI_MULTITAP_T9_PAGE_BUFFSIZE, page_ptr, &ret_val );

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
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_change_candidates_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void  mmi_ime_t9_change_candidates_case(mmi_ime_query_result_struct_p result_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
    {
        while (j < result_str->result_cnt)
        {
            result_str->result_buffer[i] = (UI_character_type)mmi_towupper((kal_wchar)result_str->result_buffer[i]);

            i++;

            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = (UI_character_type)mmi_towlower((kal_wchar)result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }
    else if (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_UPPER)
    {
        while (j < result_str->result_cnt)
        {
            result_str->result_buffer[i] = (UI_character_type)mmi_towupper((kal_wchar)result_str->result_buffer[i]);
            i++;
            
            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = (UI_character_type)mmi_towupper((kal_wchar)result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }
    else if (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_LOWER)
    {
        while (j < result_str->result_cnt)
        {
            result_str->result_buffer[i] = (UI_character_type)mmi_towlower((kal_wchar)result_str->result_buffer[i]);
            i++;
            
            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = (UI_character_type)mmi_towlower((kal_wchar)result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }
}
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

		/*THE BELOW IF CONDITION IS TO SKIP THE UPDATING FREQ PART IN CASDE OF SENTENCE MODE
		 AS IT AUTOMATICALLY GETS  UPDATEDD IN GET_ASSOCIATES api*/
#if defined (__MMI_IME_AUTO_CAPITALIZATION__)
	if(g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
		return MMI_TRUE;
#endif

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

#endif /* #ifdef  __MMI_T9__ */

#endif /* XT9 */
