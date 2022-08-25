
#ifndef KMXSIP_IMM_H
#define KMXSIP_IMM_H


#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    KMX_IME_TYPE_NUMBER, 

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)        
    KMX_IME_TYPE_NUM_123,
#endif

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)        
    KMX_IME_TYPE_NUM_SIGNED_123,
#endif

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)        
    KMX_IME_TYPE_NUM_FLOAT_123,
#endif

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)        
    KMX_IME_TYPE_NUM_PHONE_NUMBER,
#endif

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)        
    KMX_IME_TYPE_NUM_PHONE_NUMBER_WILDCHAR,
#endif

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
    KMX_IME_TYPE_NUM_SIGNED_FLOAT_123,
#endif

#if defined(KMX_CFG_LANG_ARABIC)
    KMX_IME_TYPE_SMART_ARABIC,
#endif /* #if defined(KMX_CFG_LANG_ARABIC) */
#if defined(KMX_CFG_LANG_ARABIC) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ARABIC,
#endif /* #if defined(KMX_CFG_LANG_ARABIC) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_BENGALI)
    KMX_IME_TYPE_SMART_BENGALI,
#endif /* #if defined(KMX_CFG_LANG_BENGALI) */
#if defined(KMX_CFG_LANG_BENGALI) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_BENGALI,
#endif /* #if defined(KMX_CFG_LANG_BENGALI) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_BULGARIAN)
    KMX_IME_TYPE_SMART_BULGARIAN,
#endif /* #if defined(KMX_CFG_LANG_BULGARIAN) */
#if defined(KMX_CFG_LANG_BULGARIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_BULGARIAN,
#endif /* #if defined(KMX_CFG_LANG_BULGARIAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_CZECH)
    KMX_IME_TYPE_SMART_CZECH,
#endif /* #if defined(KMX_CFG_LANG_CZECH) */
#if defined(KMX_CFG_LANG_CZECH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_CZECH,
#endif /* #if defined(KMX_CFG_LANG_CZECH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_DANISH)
    KMX_IME_TYPE_SMART_DANISH,
#endif /* #if defined(KMX_CFG_LANG_DANISH) */
#if defined(KMX_CFG_LANG_DANISH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_DANISH,
#endif /* #if defined(KMX_CFG_LANG_DANISH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_DUTCH)
    KMX_IME_TYPE_SMART_DUTCH,
#endif /* #if defined(KMX_CFG_LANG_DUTCH) */
#if defined(KMX_CFG_LANG_DUTCH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_DUTCH,
#endif /* #if defined(KMX_CFG_LANG_DUTCH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_ENGLISH)
    KMX_IME_TYPE_SMART_ENGLISH,
#endif /* #if defined(KMX_CFG_LANG_ENGLISH) */
#if defined(KMX_CFG_LANG_ENGLISH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ENGLISH,
#endif /* #if defined(KMX_CFG_LANG_ENGLISH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_ENGLISH_INTL)
    KMX_IME_TYPE_SMART_ENGLISH_INTL,
#endif /* #if defined(KMX_CFG_LANG_ENGLISH_INTL) */
#if defined(KMX_CFG_LANG_ENGLISH_INTL) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ENGLISH_INTL,
#endif /* #if defined(KMX_CFG_LANG_ENGLISH_INTL) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_FINNISH)
    KMX_IME_TYPE_SMART_FINNISH,
#endif /* #if defined(KMX_CFG_LANG_FINNISH) */
#if defined(KMX_CFG_LANG_FINNISH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_FINNISH,
#endif /* #if defined(KMX_CFG_LANG_FINNISH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_FRENCH)
    KMX_IME_TYPE_SMART_FRENCH,
#endif /* #if defined(KMX_CFG_LANG_FRENCH) */
#if defined(KMX_CFG_LANG_FRENCH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_FRENCH,
#endif /* #if defined(KMX_CFG_LANG_FRENCH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_GERMAN)
    KMX_IME_TYPE_SMART_GERMAN,
#endif /* #if defined(KMX_CFG_LANG_GERMAN) */
#if defined(KMX_CFG_LANG_GERMAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GERMAN,
#endif /* #if defined(KMX_CFG_LANG_GERMAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_GREEK)
    KMX_IME_TYPE_SMART_GREEK,
#endif /* #if defined(KMX_CFG_LANG_GREEK) */
#if defined(KMX_CFG_LANG_GREEK) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GREEK,
#endif /* #if defined(KMX_CFG_LANG_GREEK) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_HEBREW)
    KMX_IME_TYPE_SMART_HEBREW,
#endif /* #if defined(KMX_CFG_LANG_HEBREW) */
#if defined(KMX_CFG_LANG_HEBREW) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_HEBREW,
#endif /* #if defined(KMX_CFG_LANG_HEBREW) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_HINDI)
    KMX_IME_TYPE_SMART_HINDI,
#endif /* #if defined(KMX_CFG_LANG_HINDI) */
#if defined(KMX_CFG_LANG_HINDI) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_HINDI,
#endif /* #if defined(KMX_CFG_LANG_HINDI) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_HINGLISH)
    KMX_IME_TYPE_SMART_HINGLISH,
#endif /* #if defined(KMX_CFG_LANG_HINGLISH) */
#if defined(KMX_CFG_LANG_HINGLISH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_HINGLISH,
#endif /* #if defined(KMX_CFG_LANG_HINGLISH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_HUNGARIAN)
    KMX_IME_TYPE_SMART_HUNGARIAN,
#endif /* #if defined(KMX_CFG_LANG_HUNGARIAN) */
#if defined(KMX_CFG_LANG_HUNGARIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_HUNGARIAN,
#endif /* #if defined(KMX_CFG_LANG_HUNGARIAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_INDONESIAN)
    KMX_IME_TYPE_SMART_INDONESIAN,
#endif /* #if defined(KMX_CFG_LANG_INDONESIAN) */
#if defined(KMX_CFG_LANG_INDONESIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_INDONESIAN,
#endif /* #if defined(KMX_CFG_LANG_INDONESIAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_ITALIAN)
    KMX_IME_TYPE_SMART_ITALIAN,
#endif /* #if defined(KMX_CFG_LANG_ITALIAN) */
#if defined(KMX_CFG_LANG_ITALIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ITALIAN,
#endif /* #if defined(KMX_CFG_LANG_ITALIAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_MALAY)
    KMX_IME_TYPE_SMART_MALAY,
#endif /* #if defined(KMX_CFG_LANG_MALAY) */
#if defined(KMX_CFG_LANG_MALAY) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_MALAY,
#endif /* #if defined(KMX_CFG_LANG_MALAY) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_NORWEGIAN)
    KMX_IME_TYPE_SMART_NORWEGIAN,
#endif /* #if defined(KMX_CFG_LANG_NORWEGIAN) */
#if defined(KMX_CFG_LANG_NORWEGIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_NORWEGIAN,
#endif /* #if defined(KMX_CFG_LANG_NORWEGIAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_PERSIAN)
    KMX_IME_TYPE_SMART_PERSIAN,
#endif /* #if defined(KMX_CFG_LANG_PERSIAN) */
#if defined(KMX_CFG_LANG_PERSIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_PERSIAN,
#endif /* #if defined(KMX_CFG_LANG_PERSIAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_POLISH)
    KMX_IME_TYPE_SMART_POLISH,
#endif /* #if defined(KMX_CFG_LANG_POLISH) */
#if defined(KMX_CFG_LANG_POLISH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_POLISH,
#endif /* #if defined(KMX_CFG_LANG_POLISH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_PORTUGUESE)
    KMX_IME_TYPE_SMART_PORTUGUESE,
#endif /* #if defined(KMX_CFG_LANG_PORTUGUESE) */
#if defined(KMX_CFG_LANG_PORTUGUESE) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_PORTUGUESE,
#endif /* #if defined(KMX_CFG_LANG_PORTUGUESE) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_ROMANIAN)
    KMX_IME_TYPE_SMART_ROMANIAN,
#endif /* #if defined(KMX_CFG_LANG_ROMANIAN) */
#if defined(KMX_CFG_LANG_ROMANIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ROMANIAN,
#endif /* #if defined(KMX_CFG_LANG_ROMANIAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_RUSSIAN)
    KMX_IME_TYPE_SMART_RUSSIAN,
#endif /* #if defined(KMX_CFG_LANG_RUSSIAN) */
#if defined(KMX_CFG_LANG_RUSSIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_RUSSIAN,
#endif /* #if defined(KMX_CFG_LANG_RUSSIAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_SLOVAK)
    KMX_IME_TYPE_SMART_SLOVAK,
#endif /* #if defined(KMX_CFG_LANG_SLOVAK) */
#if defined(KMX_CFG_LANG_SLOVAK) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SLOVAK,
#endif /* #if defined(KMX_CFG_LANG_SLOVAK) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_SLOVENIAN)
    KMX_IME_TYPE_SMART_SLOVENIAN,
#endif /* #if defined(KMX_CFG_LANG_SLOVENIAN) */
#if defined(KMX_CFG_LANG_SLOVENIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SLOVENIAN,
#endif /* #if defined(KMX_CFG_LANG_SLOVENIAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_SPANISH)
    KMX_IME_TYPE_SMART_SPANISH,
#endif /* #if defined(KMX_CFG_LANG_SPANISH) */
#if defined(KMX_CFG_LANG_SPANISH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SPANISH,
#endif /* #if defined(KMX_CFG_LANG_SPANISH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_SWAHILI)
    KMX_IME_TYPE_SMART_SWAHILI,
#endif /* #if defined(KMX_CFG_LANG_SWAHILI) */
#if defined(KMX_CFG_LANG_SWAHILI) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SWAHILI,
#endif /* #if defined(KMX_CFG_LANG_SWAHILI) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_SWEDISH)
    KMX_IME_TYPE_SMART_SWEDISH,
#endif /* #if defined(KMX_CFG_LANG_SWEDISH) */
#if defined(KMX_CFG_LANG_SWEDISH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SWEDISH,
#endif /* #if defined(KMX_CFG_LANG_SWEDISH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_THAI)
    KMX_IME_TYPE_SMART_THAI,
#endif /* #if defined(KMX_CFG_LANG_THAI) */
#if defined(KMX_CFG_LANG_THAI) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_THAI,
#endif /* #if defined(KMX_CFG_LANG_THAI) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_TURKISH)
    KMX_IME_TYPE_SMART_TURKISH,
#endif /* #if defined(KMX_CFG_LANG_TURKISH) */
#if defined(KMX_CFG_LANG_TURKISH) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_TURKISH,
#endif /* #if defined(KMX_CFG_LANG_TURKISH) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_UKRAINIAN)
    KMX_IME_TYPE_SMART_UKRAINIAN,
#endif /* #if defined(KMX_CFG_LANG_UKRAINIAN) */
#if defined(KMX_CFG_LANG_UKRAINIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_UKRAINIAN,
#endif /* #if defined(KMX_CFG_LANG_UKRAINIAN) && defined(KMX_CFG_MULTITAP_INPUT) */


#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
    KMX_IME_TYPE_CHS_PINYIN,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED) */

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
    KMX_IME_TYPE_CHT_BOPOMOFO,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL) */

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
    KMX_IME_TYPE_CHS_STROKE,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED) */

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
    KMX_IME_TYPE_CHT_STROKE,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL) */

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
    KMX_IME_TYPE_QUICK_SEARCH_CHS_PINYIN,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED) */

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
    KMX_IME_TYPE_QUICK_SEARCH_CHT_BOPOMOFO,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL) */

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
    KMX_IME_TYPE_QUICK_SEARCH_CHS_STROKE,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED) */

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
    KMX_IME_TYPE_QUICK_SEARCH_CHT_STROKE,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL) */

#if defined(KMX_CFG_LANG_ARABIC)
    KMX_IME_TYPE_ARABIC_NUMERIC,
#endif /* #if defined(KMX_CFG_LANG_ARABIC) */

#if defined(KMX_CFG_LANG_URDU)
    KMX_IME_TYPE_SMART_URDU,
#endif /* #if defined(KMX_CFG_LANG_URDU) */
#if defined(KMX_CFG_LANG_URDU) && defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_URDU,
#endif /* #if defined(KMX_CFG_LANG_URDU) && defined(KMX_CFG_MULTITAP_INPUT) */

    /* Extra input type */
#if defined(KMX_CFG_LANG_ENGLISH)
    KMX_IME_TYPE_EMAIL,

    KMX_IME_TYPE_URL,
#endif

    KMX_IME_TYPE_MAX_NUM

}kmx_input_method_type_enum;

const KMX_IME_CONFIG * kmx_imm_get_ime_config(int input_mode);

kmx_input_method_type_enum kmx_imm_get_ime_type(int input_mode);

const KMX_IME_CONFIG * kmx_imm_get_ime_config_by_type(kmx_input_method_type_enum ime_type);

unsigned char kmx_imm_get_case_info_by_mode(int input_mode);



void kmx_load_user_data(void);

void kmx_save_user_data(void);

#ifdef __cplusplus
}
#endif

#endif /* KMXSIP_IMM_H */
