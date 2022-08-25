/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   IMERes.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is header file for IME structure for Multiple Bin.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IME_Res_H_
#define _IME_Res_H_

#include "MMI_features.h"
#include "IMERes.h"
#include "ImeGprot.h"
#include "SettingResDef.h"
#include "gui_virtual_keyboard_language_type.h"
#include "kal_non_specific_general_types.h"
#include "MMIDataType.h"

#define MAX_LDB_NUMBER 20
//#include "CommonScreensenum.h"
#include "SettingDefs.h"
#include "gui_data_types.h"
#include "ImeGprot.h"
#include "gui_virtual_keyboard.h"


typedef U32 HW_ATTR; 

typedef enum {
    IME_LANG_ATTR_NONE          = 0x0,
    IME_LANG_ATTR_ENGLISH_ONLY  = 0x1,
    IME_LANG_ATTR_MIXED_LANG_SUPPORT = 0x02,
    IME_LANG_ATTR_ALPHABETIC    = 0x10,
    IME_LANG_ATTR_PHONETIC      = 0x20,
    IME_LANG_ATTR_STROKE        = 0x40,
    IME_LANG_ATTR_SYMBOLIC      = 0x80,
    IME_LANG_ATTR_NUMBERIC      = 0x100
}   ime_lang_attr_enum;

typedef enum {
    IME_MODE_ATTR_NONE          = 0x0,
    IME_MODE_ATTR_UPPERCASE     = 0x1,
    IME_MODE_ATTR_LOWERCASE     = 0x2,
    IME_MODE_ATTR_TITLECASE     = 0x4,
    IME_MODE_ATTR_SMART         = 0x10,
    IME_MODE_ATTR_MULTITAP      = 0x20,
    IME_MODE_ATTR_DIRECT        = 0x40,
    IME_MODE_ATTR_EXTSPELL      = 0x1000,  /* (for T9) request multitap symbol from external integration layer */
    IME_MODE_ATTR_SPSPELL       = 0x2000   /* allow ShuangPin? */
}   ime_mode_attr_enum;

#define IME_IS_ENGLISH_ONLY(lang_attr)  (lang_attr & IME_LANG_ATTR_ENGLISH_ONLY > 0 ? 1 : 0)
#define IME_IS_MIXED_LANG_SUPPORT(lang_attr)    (((lang_attr) & (IME_LANG_ATTR_MIXED_LANG_SUPPORT)) > 0 ? 1 : 0 )
#define IME_IS_SMART_INPUT_METHOD(input_attr)   ((input_attr & (IME_MODE_ATTR_SMART)) > 0 ? 1 : 0) 
#define IME_IS_CHINESE_WRITING_LANG(wlang) (((wlang ==IME_WRITING_LANG_ZHTW) || (wlang == IME_WRITING_LANG_ZHCN) )) 
#define IME_MODE_CASE_MASK ((U16)(IME_MODE_ATTR_UPPERCASE | IME_MODE_ATTR_LOWERCASE | IME_MODE_ATTR_TITLECASE))

#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_IME_V3__)
    #define MAX_WRITING_LANG 20
#endif

#if defined (__MMI_IME_FUZZY_PINYIN__)
    #define MAX_FUZZY_PINYIN  (IME_FUZZY_PINYIN_MAX + 1)
#endif


#if defined(__MMI_T9__)
#if defined(__MMI_XT9__)
#include "et9api.h"
typedef struct T9LdbMemData_s
{
    ET9U16 wLdbNum;          /* Language ID */
    ET9U32 nNumFullBlk;      /* Number of the blocks whose */
    /* data size is BLOCKSIZE. */
    /* BLOCKSIZE is the size of each */
    /* block with assumption that all */
    /* data blocks but the last one */
    /* are in the same size. */
    ET9U32 dwLastBlkSize;    /* Size of the last data block if */
    /* its size is smaller than */
    /* BLOCKSIZE. Set to 0 if the */
    /* size equals BLOCKSIZE. And */
    /* this block should be added */
    /* into nNumFullBlk. */
    //taking 13 as Malayalam uses 14 blocks
#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)|| defined(__MMI_T9_HK_CHINESE__)
    const ET9U8 ET9FARDATA *dwLdbDataBlk[69];
#else
    const ET9U8 ET9FARDATA *dwLdbDataBlk[13];
#endif    
/* Pointers to each data block. */
} T9LdbMemData;


#else



#include "t9api.h"

typedef struct T9LdbMemData_s
{
    T9U16 wLdbNum;          /* Language ID */
    T9U32 nNumFullBlk;      /* Number of the blocks whose */
    /* data size is BLOCKSIZE. */
    /* BLOCKSIZE is the size of each */
    /* block with assumption that all */
    /* data blocks but the last one */
    /* are in the same size. */
    T9U32 dwLastBlkSize;    /* Size of the last data block if */
    /* its size is smaller than */
    /* BLOCKSIZE. Set to 0 if the */
    /* size equals BLOCKSIZE. And */
    /* this block should be added */
    /* into nNumFullBlk. */
    //taking 13 as Malayalam uses 14 blocks
    const T9U8 T9FARDATA *dwLdbDataBlk[13];
    /* Pointers to each data block. */
} T9LdbMemData;

#endif
#elif defined(__MMI_ZI__)
#include "zi8api.h"
#define ZI_TR_CHINESE 0
#define ZI_SIM_CHINESE 1
#endif 

typedef struct _IMEModeDetails
{
    mmi_imm_input_mode_enum imm_mode_id; /* input mode id */
    U32 supported_input_type_flag; /* To indicate which input type is supported by the input mode. */
    U16 menuitem_string_id; /* the string id to use in preferred input method or input method selection list */
    U16 Lang_Special_Attrib;
    U16 Mode_Special_Attrib;
    mmi_imm_support_writing_lang_enum lang_id;
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) ||defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
    U8 aLangCountryCode[LCC_SIZE];
#endif    
#if defined(__MMI_TOUCH_SCREEN__)
/*
 *     |<-- 4 bits -->|<------12 bits ------>|<---- 8 bits ---->|<---- 8 bits ---->|
 *       has candidate      caps lock input mode           vk type           handwriting type
 */
    HW_ATTR Handwriting_Attrib;
#endif/*__MMI_TOUCH_SCREEN__*/
} sIMEModeDetails;

#if defined(__MMI_T9__)
typedef T9LdbMemData sIMELDBDetails;
#elif defined(__MMI_ZI__)
#if defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__)
typedef ZI8_LANGUAGE_ENTRY sIMELDBDetails[MAX_LDB_NUMBER];
#else 
typedef ZI8_LANGUAGE_ENTRY sIMELDBDetails;
#endif 
#else 
typedef char sIMELDBDetails;
#endif 

typedef enum
{
    ZiV5,
    ZiV6,
    T9V6,
    T9V7,
    T9V7_4,
    XT9,
    IME_OTHERS
} sIMEModuleDetails;

// for mixed lang support  
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
typedef struct
{
    mmi_imm_support_writing_lang_enum lang_id;
    UI_string_type lang_str_ptr;
    mmi_imm_input_mode_enum default_input_mode;
#if defined(__MMI_MIXED_LANG_SUPPORT__)    
    MMI_BOOL mixed_lang_support;
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */
   MMI_BOOL  enabled;

}ime_writing_lang_struct;
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */

#if defined(__MMI_IME_FUZZY_PINYIN__)
typedef struct
{
    mmi_imm_fuzzy_pinyin_enum fuzzy_id;
    const char* fuzzy_str_ptr;
}ime_fuzzy_pinyin_struct;
#endif


#if defined(__MMI_TOUCH_SCREEN__)
/* mode enum has excedded 256 so 12 bits given to mode instead of 8*/
#define IME_HAND_WRITING_ATTRIB(has_candidate, caps_lock_input_mode, vk_type, hand_writing_type) \
        (U32)(((has_candidate)<<28) | ((caps_lock_input_mode)<<16) | (((U8)vk_type)<<8) | ((U8)hand_writing_type))

#define IME_HAN_WRITING_INVALID_INPUT_MODE IMM_INPUT_MODE_MAX_NUM

#define IME_HAN_WRITING_INVALID_VK_TYPE IMM_INPUT_MODE_MAX_NUM

#define IME_HAND_WRITING_INVALID IME_HAND_WRITING_ATTRIB(0, IME_HAN_WRITING_INVALID_INPUT_MODE, GUI_VIRTUAL_KEYBOARD_NUMBER, 0)

#define IME_HAND_WRITING_GET_CAPS_LOCK_INPUT_MODE(hw_attrib) (((hw_attrib) << 4) >> 20)

#define IME_HAND_WRITING_GET_VK_TYPE(hw_attrib) (((hw_attrib) << 16) >> 24)

#define IME_HAND_WRITING_GET_VK_HAS_CAND(hw_attrib) ((hw_attrib) >> 28)

#define IME_HAND_WRITING_GET_HW_TYPE(hw_attrib) (U8)((hw_attrib))

#endif/*__MMI_TOUCH_SCREEN__*/


extern const sIMEModeDetails * mmi_imm_get_input_mode_array_item(mmi_imm_input_mode_enum input_mode);

extern const sIMEModeDetails * mmi_imm_get_corresponding_multitap_mode(mmi_imm_input_mode_enum input_mode, U16 mode_case);

        
#endif /* _IME_Res_H_ */ /* IME_RES_H */

