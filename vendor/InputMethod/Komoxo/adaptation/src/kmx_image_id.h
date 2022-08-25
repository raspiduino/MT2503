#ifndef KMX_IMAGE_ID_H
#define KMX_IMAGE_ID_H

#include "kmx_reduced_image_id.h"
#include "kmx_qwerty_image_id.h"


static const unsigned short g_kmx_image_range_table[] = 
{
#ifdef __MMI_KMX_NORMAL_TOUCH_INPUT__
    KMX_IMAGE_COMMON_N, KMX_IMAGE_COMMON_HW,
    
    #ifdef __MMI_LANG_ARABIC__
    KMX_IMAGE_ARABIC_N1, KMX_IMAGE_ARABIC_ABC_MT,
    #endif /* #ifdef __MMI_LANG_ARABIC__ */
    
    #ifdef __MMI_LANG_BENGALI__
    KMX_IMAGE_BENGALI_N1, KMX_IMAGE_BENGALI_ABC_MT,
    #endif /* #ifdef __MMI_LANG_BENGALI__ */
    
    #ifdef __MMI_LANG_TR_CHINESE__
    KMX_IMAGE_BOPOMOFO_1, KMX_IMAGE_BOPOMOFO_0,
    #endif /* #ifdef __MMI_LANG_TR_CHINESE__ */
    
    #ifdef __MMI_LANG_BULGARIAN__
    KMX_IMAGE_BULGARIAN_NL1, KMX_IMAGE_BULGARIAN_ABC_MT,
    #endif /* #ifdef __MMI_LANG_BULGARIAN__ */
    
    #ifdef __MMI_LANG_ENGLISH__
    KMX_IMAGE_ENGLISH_NL1, KMX_IMAGE_ENGLISH_NU0,
    #endif /* #ifdef __MMI_LANG_ENGLISH__ */
    
    #ifdef __MMI_LANG_GREEK__
    KMX_IMAGE_GREEK_NL1, KMX_IMAGE_GREEK_ABC_MT,
    #endif /* #ifdef __MMI_LANG_GREEK__ */
    
    #ifdef __MMI_LANG_HEBREW__
    KMX_IMAGE_HEBREW_N1, KMX_IMAGE_HEBREW_ABC_MT,
    #endif /* #ifdef __MMI_LANG_HEBREW__ */
    
    #ifdef __MMI_LANG_HINDI__
    KMX_IMAGE_HINDI_N1, KMX_IMAGE_HINDI_ABC_MT,
    #endif /* #ifdef __MMI_LANG_HINDI__ */
    
    #ifdef __MMI_LANG_PERSIAN__
    KMX_IMAGE_PERSIAN_N1, KMX_IMAGE_PERSIAN_ABC_MT,
    #endif /* #ifdef __MMI_LANG_PERSIAN__ */
    
    #ifdef __MMI_LANG_RUSSIAN__
    KMX_IMAGE_RUSSIAN_NL1, KMX_IMAGE_RUSSIAN_ABC_MT,
    #endif /* #ifdef __MMI_LANG_RUSSIAN__ */
    
    #if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)
    KMX_IMAGE_STROKE_1, KMX_IMAGE_STROKE_9,
    #endif /* #if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) */
    
    #ifdef __MMI_LANG_THAI__
    KMX_IMAGE_THAI_N1, KMX_IMAGE_THAI_ABC_MT,
    #endif /* #ifdef __MMI_LANG_THAI__ */
    
    #ifdef __MMI_LANG_UKRAINIAN__
    KMX_IMAGE_UKRAINIAN_NL1, KMX_IMAGE_UKRAINIAN_ABC_MT,
    #endif /* #ifdef __MMI_LANG_UKRAINIAN__ */
    
    #ifdef __MMI_LANG_ARABIC__
    KMX_IMAGE_ARABIC_DIGIT_0, KMX_IMAGE_ARABIC_DIGIT_9,
    #endif /* #ifdef __MMI_LANG_ARABIC__ */
    
    #ifdef __MMI_LANG_URDU__
    KMX_IMAGE_URDU_N1, KMX_IMAGE_URDU_ABC_MT,
    #endif /* #ifdef __MMI_LANG_URDU__ */
    
    #ifdef __MMI_LANG_BENGALI__
    KMX_IMAGE_BENGALI_DIGIT_0, KMX_IMAGE_BENGALI_DIGIT_9,
    #endif /* #ifdef __MMI_LANG_BENGALI__ */
    
    #ifdef __MMI_LANG_HINDI__
    KMX_IMAGE_HINDI_DIGIT_0, KMX_IMAGE_HINDI_DIGIT_9,
    #endif /* #ifdef __MMI_LANG_HINDI__ */
    
    #ifdef __MMI_LANG_PERSIAN__
    KMX_IMAGE_PERSIAN_DIGIT_0, KMX_IMAGE_PERSIAN_DIGIT_9,
    #endif /* #ifdef __MMI_LANG_PERSIAN__ */
    
    #ifdef __MMI_LANG_THAI__
    KMX_IMAGE_THAI_DIGIT_0, KMX_IMAGE_THAI_DIGIT_9,
    #endif /* #ifdef __MMI_LANG_THAI__ */
    
    #ifdef __MMI_LANG_VIETNAMESE__
    KMX_IMAGE_VIETNAMESE_MARK, KMX_IMAGE_VIETNAMESE_323,
    #endif /* #ifdef __MMI_LANG_VIETNAMESE__ */
    
    #ifdef __MMI_KMX_PURE_DIGIT__
    KMX_IMAGE_DIGIT_N1, KMX_IMAGE_DIGIT_N9,
    #endif /* #ifdef __MMI_KMX_PURE_DIGIT__ */
    
#endif /* #ifdef __MMI_KMX_NORMAL_TOUCH_INPUT__ */

#ifdef __MMI_KMX_QWERTY_TOUCH_INPUT__
    KMX_IMAGE_QWERTY_123, KMX_IMAGE_QWERTY_MT_Z,
    
    KMX_IMAGE_QWERTY_MT_100, KMX_IMAGE_QWERTY_MT_DF,
    
    #ifdef __MMI_LANG_HINDI__
    KMX_IMAGE_QWERTY_COMMON2_93D, KMX_IMAGE_QWERTY_MT_95F,
    #endif /* #ifdef __MMI_LANG_HINDI__ */
    
    #if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)
    KMX_IMAGE_QWERTY_COMMON2_3001, KMX_IMAGE_QWERTY_STROKE_WILDCHAR,
    #endif /* #if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) */
    
    #if defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_UKRAINIAN__) || defined(__MMI_LANG_BULGARIAN__)
    KMX_IMAGE_QWERTY_BULGARIAN_ABC, KMX_IMAGE_QWERTY_UKRAINIAN_ABC_MT,
    #endif /* #if defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_UKRAINIAN__) || defined(__MMI_LANG_BULGARIAN__) */
    
    #ifdef __MMI_LANG_VIETNAMESE__
    KMX_IMAGE_QWERTY_COMMON3_102, KMX_IMAGE_QWERTY_MT3_Y,
    #endif /* #ifdef __MMI_LANG_VIETNAMESE__ */
    
    #ifdef __MMI_LANG_GREEK__
    KMX_IMAGE_QWERTY_COMMON_391, KMX_IMAGE_QWERTY_MT_3AB,
    #endif /* #ifdef __MMI_LANG_GREEK__ */
    
    #ifdef __MMI_LANG_HEBREW__
    KMX_IMAGE_QWERTY_COMMON_5D0, KMX_IMAGE_QWERTY_MT_5F2,
    #endif /* #ifdef __MMI_LANG_HEBREW__ */
    
    #if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    KMX_IMAGE_QWERTY_ARABIC_ABC, KMX_IMAGE_QWERTY_URDU_ABC_MT,
    #endif /* #if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */
    
    #ifdef __MMI_LANG_TR_CHINESE__
    KMX_IMAGE_QWERTY_COMMON_2C7, KMX_IMAGE_QWERTY_COMMON_3129,
    #endif /* #ifdef __MMI_LANG_TR_CHINESE__ */
    
    #ifdef __MMI_LANG_THAI__
    KMX_IMAGE_QWERTY_COMMON3_E01, KMX_IMAGE_QWERTY_THAI_ABC_MT,
    #endif /* #ifdef __MMI_LANG_THAI__ */
    
    #ifdef __MMI_LANG_BENGALI__
    KMX_IMAGE_QWERTY_BENGALI_ABC, KMX_IMAGE_QWERTY_COMMON_9EF,
    #endif /* #ifdef __MMI_LANG_BENGALI__ */
    
#endif /* #ifdef __MMI_KMX_QWERTY_TOUCH_INPUT__ */
};


static const unsigned short g_kmx_image_map_table[] = 
{
#ifdef __MMI_KMX_NORMAL_TOUCH_INPUT__
    IMG_KOMOXO_COMMON_N,
    
    #ifdef __MMI_LANG_ARABIC__
    IMG_KOMOXO_ARABIC_N1,
    #endif /* #ifdef __MMI_LANG_ARABIC__ */
    
    #ifdef __MMI_LANG_BENGALI__
    IMG_KOMOXO_BENGALI_N1,
    #endif /* #ifdef __MMI_LANG_BENGALI__ */
    
    #ifdef __MMI_LANG_TR_CHINESE__
    IMG_KOMOXO_BOPOMOFO_1,
    #endif /* #ifdef __MMI_LANG_TR_CHINESE__ */
    
    #ifdef __MMI_LANG_BULGARIAN__
    IMG_KOMOXO_BULGARIAN_NL1,
    #endif /* #ifdef __MMI_LANG_BULGARIAN__ */
    
    #ifdef __MMI_LANG_ENGLISH__
    IMG_KOMOXO_ENGLISH_NL1,
    #endif /* #ifdef __MMI_LANG_ENGLISH__ */
    
    #ifdef __MMI_LANG_GREEK__
    IMG_KOMOXO_GREEK_NL1,
    #endif /* #ifdef __MMI_LANG_GREEK__ */
    
    #ifdef __MMI_LANG_HEBREW__
    IMG_KOMOXO_HEBREW_N1,
    #endif /* #ifdef __MMI_LANG_HEBREW__ */
    
    #ifdef __MMI_LANG_HINDI__
    IMG_KOMOXO_HINDI_N1,
    #endif /* #ifdef __MMI_LANG_HINDI__ */
    
    #ifdef __MMI_LANG_PERSIAN__
    IMG_KOMOXO_PERSIAN_N1,
    #endif /* #ifdef __MMI_LANG_PERSIAN__ */
    
    #ifdef __MMI_LANG_RUSSIAN__
    IMG_KOMOXO_RUSSIAN_NL1,
    #endif /* #ifdef __MMI_LANG_RUSSIAN__ */
    
    #if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)
    IMG_KOMOXO_STROKE_1,
    #endif /* #if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) */
    
    #ifdef __MMI_LANG_THAI__
    IMG_KOMOXO_THAI_N1,
    #endif /* #ifdef __MMI_LANG_THAI__ */
    
    #ifdef __MMI_LANG_UKRAINIAN__
    IMG_KOMOXO_UKRAINIAN_NL1,
    #endif /* #ifdef __MMI_LANG_UKRAINIAN__ */
    
    #ifdef __MMI_LANG_ARABIC__
    IMG_KOMOXO_ARABIC_DIGIT_0,
    #endif /* #ifdef __MMI_LANG_ARABIC__ */
    
    #ifdef __MMI_LANG_URDU__
    IMG_KOMOXO_URDU_N1,
    #endif /* #ifdef __MMI_LANG_URDU__ */
    
    #ifdef __MMI_LANG_BENGALI__
    IMG_KOMOXO_BENGALI_DIGIT_0,
    #endif /* #ifdef __MMI_LANG_BENGALI__ */
    
    #ifdef __MMI_LANG_HINDI__
    IMG_KOMOXO_HINDI_DIGIT_0,
    #endif /* #ifdef __MMI_LANG_HINDI__ */
    
    #ifdef __MMI_LANG_PERSIAN__
    IMG_KOMOXO_PERSIAN_DIGIT_0,
    #endif /* #ifdef __MMI_LANG_PERSIAN__ */
    
    #ifdef __MMI_LANG_THAI__
    IMG_KOMOXO_THAI_DIGIT_0,
    #endif /* #ifdef __MMI_LANG_THAI__ */
    
    #ifdef __MMI_LANG_VIETNAMESE__
    IMG_KOMOXO_VIETNAMESE_MARK,
    #endif /* #ifdef __MMI_LANG_VIETNAMESE__ */
    
    #ifdef __MMI_KMX_PURE_DIGIT__
    IMG_KOMOXO_DIGIT_N1,
    #endif /* #ifdef __MMI_KMX_PURE_DIGIT__ */
    
#endif /* #ifdef __MMI_KMX_NORMAL_TOUCH_INPUT__ */

#ifdef __MMI_KMX_QWERTY_TOUCH_INPUT__
    IMG_KOMOXO_QWERTY_123,
    
    IMG_KOMOXO_QWERTY_MT_100,
    
    #ifdef __MMI_LANG_HINDI__
    IMG_KOMOXO_QWERTY_COMMON2_93D,
    #endif /* #ifdef __MMI_LANG_HINDI__ */
    
    #if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)
    IMG_KOMOXO_QWERTY_COMMON2_3001,
    #endif /* #if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) */
    
    #if defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_UKRAINIAN__) || defined(__MMI_LANG_BULGARIAN__)
    IMG_KOMOXO_QWERTY_BULGARIAN_ABC,
    #endif /* #if defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_UKRAINIAN__) || defined(__MMI_LANG_BULGARIAN__) */
    
    #ifdef __MMI_LANG_VIETNAMESE__
    IMG_KOMOXO_QWERTY_COMMON3_102,
    #endif /* #ifdef __MMI_LANG_VIETNAMESE__ */
    
    #ifdef __MMI_LANG_GREEK__
    IMG_KOMOXO_QWERTY_COMMON_391,
    #endif /* #ifdef __MMI_LANG_GREEK__ */
    
    #ifdef __MMI_LANG_HEBREW__
    IMG_KOMOXO_QWERTY_COMMON_5D0,
    #endif /* #ifdef __MMI_LANG_HEBREW__ */
    
    #if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    IMG_KOMOXO_QWERTY_ARABIC_ABC,
    #endif /* #if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */
    
    #ifdef __MMI_LANG_TR_CHINESE__
    IMG_KOMOXO_QWERTY_COMMON_2C7,
    #endif /* #ifdef __MMI_LANG_TR_CHINESE__ */
    
    #ifdef __MMI_LANG_THAI__
    IMG_KOMOXO_QWERTY_COMMON3_E01,
    #endif /* #ifdef __MMI_LANG_THAI__ */
    
    #ifdef __MMI_LANG_BENGALI__
    IMG_KOMOXO_QWERTY_BENGALI_ABC,
    #endif /* #ifdef __MMI_LANG_BENGALI__ */
    
#endif /* #ifdef __MMI_KMX_QWERTY_TOUCH_INPUT__ */
};

#endif /* KMX_IMAGE_ID_H */
