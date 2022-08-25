
#include "MMI_features.h"
#include "kmx_input_config.h"

#ifdef __MMI_KMX_TOUCH_INPUT__

#include "kmxsip_config.h"
#include "kmximmapi.h"
#include "Kmxsip_imm.h"
#include "kmxsip_user_data.h"
#include "kmxldbapi.h"
#include "ImeGprot.h"
#include "kmxime_api.h"

#include "kmx_input_prot.h"

/* User Data Size Definition  */
#define    KMX_USER_DATA_BLOCK_SIZE          1024

#define    KMX_PINYIN_USER_DATA_SIZE         8  
#define    KMX_BOPOMOFO_USER_DATA_SIZE       8  
#define    KMX_STROKE_USER_DATA_SIZE         1  
#define    KMX_ALPHABETIC_USER_DATA_SIZE     4  

/* komoxo multilingual */
#ifdef KMX_CFG_USER_DATA_08
    #define    KMX_LOAD_UDB(x) x
#else
    #define    KMX_LOAD_UDB(x) 0
#endif

/* User Data Size Enum */

typedef enum
{
#if defined(KMX_CFG_LANG_ARABIC)
    KMX_ARABIC_USER_DATA_START,
    KMX_ARABIC_USER_DATA_LAST = KMX_ARABIC_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_ARABIC) */

#if defined(KMX_CFG_LANG_BENGALI)
    KMX_BENGALI_USER_DATA_START,
    KMX_BENGALI_USER_DATA_LAST = KMX_BENGALI_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_BENGALI) */

#if defined(KMX_CFG_LANG_BULGARIAN)
    KMX_BULGARIAN_USER_DATA_START,
    KMX_BULGARIAN_USER_DATA_LAST = KMX_BULGARIAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_BULGARIAN) */

#if defined(KMX_CFG_LANG_CZECH)
    KMX_CZECH_USER_DATA_START,
    KMX_CZECH_USER_DATA_LAST = KMX_CZECH_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_CZECH) */

#if defined(KMX_CFG_LANG_DANISH)
    KMX_DANISH_USER_DATA_START,
    KMX_DANISH_USER_DATA_LAST = KMX_DANISH_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_DANISH) */

#if defined(KMX_CFG_LANG_DUTCH)
    KMX_DUTCH_USER_DATA_START,
    KMX_DUTCH_USER_DATA_LAST = KMX_DUTCH_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_DUTCH) */

#if defined(KMX_CFG_LANG_ENGLISH)
    KMX_ENGLISH_USER_DATA_START,
    KMX_ENGLISH_USER_DATA_LAST = KMX_ENGLISH_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_ENGLISH) */

#if defined(KMX_CFG_LANG_ENGLISH_INTL)
    KMX_ENGLISH_INTL_USER_DATA_START,
    KMX_ENGLISH_INTL_USER_DATA_LAST = KMX_ENGLISH_INTL_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_ENGLISH_INTL) */

#if defined(KMX_CFG_LANG_FINNISH)
    KMX_FINNISH_USER_DATA_START,
    KMX_FINNISH_USER_DATA_LAST = KMX_FINNISH_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_FINNISH) */

#if defined(KMX_CFG_LANG_FRENCH)
    KMX_FRENCH_USER_DATA_START,
    KMX_FRENCH_USER_DATA_LAST = KMX_FRENCH_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_FRENCH) */

#if defined(KMX_CFG_LANG_GERMAN)
    KMX_GERMAN_USER_DATA_START,
    KMX_GERMAN_USER_DATA_LAST = KMX_GERMAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_GERMAN) */

#if defined(KMX_CFG_LANG_GREEK)
    KMX_GREEK_USER_DATA_START,
    KMX_GREEK_USER_DATA_LAST = KMX_GREEK_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_GREEK) */

#if defined(KMX_CFG_LANG_HEBREW)
    KMX_HEBREW_USER_DATA_START,
    KMX_HEBREW_USER_DATA_LAST = KMX_HEBREW_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_HEBREW) */

#if defined(KMX_CFG_LANG_HINDI)
    KMX_HINDI_USER_DATA_START,
    KMX_HINDI_USER_DATA_LAST = KMX_HINDI_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_HINDI) */

#if defined(KMX_CFG_LANG_HINGLISH)
    KMX_HINGLISH_USER_DATA_START,
    KMX_HINGLISH_USER_DATA_LAST = KMX_HINGLISH_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_HINGLISH) */

#if defined(KMX_CFG_LANG_HUNGARIAN)
    KMX_HUNGARIAN_USER_DATA_START,
    KMX_HUNGARIAN_USER_DATA_LAST = KMX_HUNGARIAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_HUNGARIAN) */

#if defined(KMX_CFG_LANG_INDONESIAN)
    KMX_INDONESIAN_USER_DATA_START,
    KMX_INDONESIAN_USER_DATA_LAST = KMX_INDONESIAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_INDONESIAN) */

#if defined(KMX_CFG_LANG_ITALIAN)
    KMX_ITALIAN_USER_DATA_START,
    KMX_ITALIAN_USER_DATA_LAST = KMX_ITALIAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_ITALIAN) */

#if defined(KMX_CFG_LANG_MALAY)
    KMX_MALAY_USER_DATA_START,
    KMX_MALAY_USER_DATA_LAST = KMX_MALAY_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_MALAY) */

#if defined(KMX_CFG_LANG_NORWEGIAN)
    KMX_NORWEGIAN_USER_DATA_START,
    KMX_NORWEGIAN_USER_DATA_LAST = KMX_NORWEGIAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_NORWEGIAN) */

#if defined(KMX_CFG_LANG_PERSIAN)
    KMX_PERSIAN_USER_DATA_START,
    KMX_PERSIAN_USER_DATA_LAST = KMX_PERSIAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_PERSIAN) */

#if defined(KMX_CFG_LANG_POLISH)
    KMX_POLISH_USER_DATA_START,
    KMX_POLISH_USER_DATA_LAST = KMX_POLISH_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_POLISH) */

#if defined(KMX_CFG_LANG_PORTUGUESE)
    KMX_PORTUGUESE_USER_DATA_START,
    KMX_PORTUGUESE_USER_DATA_LAST = KMX_PORTUGUESE_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_PORTUGUESE) */

#if defined(KMX_CFG_LANG_ROMANIAN)
    KMX_ROMANIAN_USER_DATA_START,
    KMX_ROMANIAN_USER_DATA_LAST = KMX_ROMANIAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_ROMANIAN) */

#if defined(KMX_CFG_LANG_RUSSIAN)
    KMX_RUSSIAN_USER_DATA_START,
    KMX_RUSSIAN_USER_DATA_LAST = KMX_RUSSIAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_RUSSIAN) */

#if defined(KMX_CFG_LANG_SLOVAK)
    KMX_SLOVAK_USER_DATA_START,
    KMX_SLOVAK_USER_DATA_LAST = KMX_SLOVAK_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_SLOVAK) */

#if defined(KMX_CFG_LANG_SLOVENIAN)
    KMX_SLOVENIAN_USER_DATA_START,
    KMX_SLOVENIAN_USER_DATA_LAST = KMX_SLOVENIAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_SLOVENIAN) */


#if defined(KMX_CFG_LANG_UKRAINIAN)
    KMX_UKRAINIAN_USER_DATA_START,
    KMX_UKRAINIAN_USER_DATA_LAST = KMX_UKRAINIAN_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_UKRAINIAN) */

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
    KMX_CHS_PINYIN_USER_DATA_START,
    KMX_CHS_PINYIN_USER_DATA_LAST = KMX_CHS_PINYIN_USER_DATA_START + KMX_PINYIN_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED) */

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
    KMX_CHT_BOPOMOFO_USER_DATA_START,
    KMX_CHT_BOPOMOFO_USER_DATA_LAST = KMX_CHT_BOPOMOFO_USER_DATA_START + KMX_BOPOMOFO_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL) */

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
    KMX_CHS_STROKE_USER_DATA_START,
    KMX_CHS_STROKE_USER_DATA_LAST = KMX_CHS_STROKE_USER_DATA_START + KMX_STROKE_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED) */

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
    KMX_CHT_STROKE_USER_DATA_START,
    KMX_CHT_STROKE_USER_DATA_LAST = KMX_CHT_STROKE_USER_DATA_START + KMX_STROKE_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL) */

#if defined(KMX_CFG_LANG_URDU)
    KMX_URDU_USER_DATA_START,
    KMX_URDU_USER_DATA_LAST = KMX_URDU_USER_DATA_START + KMX_ALPHABETIC_USER_DATA_SIZE - 1,
#endif /* #if defined(KMX_CFG_LANG_UKRAINIAN) */

    KMX_TOTAL_USER_DATA_SIZE
}kmx_user_data_size_enum;

/* Input Method User Data  */
#ifdef KMX_CFG_USER_DATA_08
    static int g_kmx_user_data[ KMX_TOTAL_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE / 4];
#endif

/* Input Method Configuration Start */

static const KMX_IME_CONFIG g_ime_configs[] = 
{
   {
        KMX_IME_NUM,
        KMX_LANG_ENGLISH,
        KMX_LANG_ENGLISH,
        0,
        0,
        0,
        0
    },
    
#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
   {
        KMX_IME_NUM,
        KMX_LANG_NUM_123,
        KMX_LANG_ENGLISH,
        0,
        0,
        0,
        0
   },
#endif

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
   {
        KMX_IME_NUM,
        KMX_LANG_NUM_SIGNED_123,
        KMX_LANG_ENGLISH,
        0,
        0,
        0,
        0
   },
#endif

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
   {
        KMX_IME_NUM,
        KMX_LANG_NUM_FLOAT_123,
        KMX_LANG_ENGLISH,
        0,
        0,
        0,
        0
   },
#endif

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
   {
        KMX_IME_NUM,
        KMX_LANG_NUM_PHONE_NUMBER,
        KMX_LANG_ENGLISH,
        0,
        0,
        0,
        0
   },
#endif

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
   {
        KMX_IME_NUM,
        KMX_LANG_NUM_PHONE_NUMBER_WILDCHAR,
        KMX_LANG_ENGLISH,
        0,
        0,
        0,
        0
   },
#endif

#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
   {
        KMX_IME_NUM,
        KMX_LANG_NUM_SIGNED_FLOAT_123,
        KMX_LANG_ENGLISH,
        0,
        0,
        0,
        0
   },
#endif
   
#if defined(KMX_CFG_LANG_ARABIC)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_ARABIC,
        KMX_LANG_ARABIC,
        &kmx_ldb_arabic,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_ARABIC_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),    
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_ARABIC) */

#if defined(KMX_CFG_LANG_ARABIC) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_ARABIC,
        KMX_LANG_ARABIC,
        &kmx_ldb_arabic,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_ARABIC) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_BENGALI)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_BENGALI,
        KMX_LANG_BENGALI,
        &kmx_ldb_bengali,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_BENGALI_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_BENGALI) */

#if defined(KMX_CFG_LANG_BENGALI) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_BENGALI,
        KMX_LANG_BENGALI,
        &kmx_ldb_bengali,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_BENGALI) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_BULGARIAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_BULGARIAN,
        KMX_LANG_BULGARIAN,
        &kmx_ldb_bulgarian,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_BULGARIAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_BULGARIAN) */

#if defined(KMX_CFG_LANG_BULGARIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_BULGARIAN,
        KMX_LANG_BULGARIAN,
        &kmx_ldb_bulgarian,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_BULGARIAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_CZECH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_CZECH,
        KMX_LANG_CZECH,
        &kmx_ldb_czech,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_CZECH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_CZECH) */

#if defined(KMX_CFG_LANG_CZECH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_CZECH,
        KMX_LANG_CZECH,
        &kmx_ldb_czech,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_CZECH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_DANISH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_DANISH,
        KMX_LANG_DANISH,
        &kmx_ldb_danish,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_DANISH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_DANISH) */

#if defined(KMX_CFG_LANG_DANISH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_DANISH,
        KMX_LANG_DANISH,
        &kmx_ldb_danish,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_DANISH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_DUTCH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_DUTCH,
        KMX_LANG_DUTCH,
        &kmx_ldb_dutch,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_DUTCH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_DUTCH) */

#if defined(KMX_CFG_LANG_DUTCH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_DUTCH,
        KMX_LANG_DUTCH,
        &kmx_ldb_dutch,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_DUTCH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_ENGLISH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_ENGLISH,
        KMX_LANG_ENGLISH,
        &kmx_ldb_english,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_ENGLISH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),    
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_ENGLISH) */

#if defined(KMX_CFG_LANG_ENGLISH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_ENGLISH,
        KMX_LANG_ENGLISH,
        &kmx_ldb_english,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_ENGLISH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_ENGLISH_INTL)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_ENGLISH_INTL,
        KMX_LANG_ENGLISH_INTL,
        &kmx_ldb_english_intl,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_ENGLISH_INTL_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_ENGLISH_INTL) */

#if defined(KMX_CFG_LANG_ENGLISH_INTL) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_ENGLISH_INTL,
        KMX_LANG_ENGLISH_INTL,
        &kmx_ldb_english,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_ENGLISH_INTL) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_FINNISH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_FINNISH,
        KMX_LANG_FINNISH,
        &kmx_ldb_finnish,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_FINNISH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_FINNISH) */

#if defined(KMX_CFG_LANG_FINNISH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_FINNISH,
        KMX_LANG_FINNISH,
        &kmx_ldb_finnish,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_FINNISH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_FRENCH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_FRENCH,
        KMX_LANG_FRENCH,
        &kmx_ldb_french,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_FRENCH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),        
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_FRENCH) */

#if defined(KMX_CFG_LANG_FRENCH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_FRENCH,
        KMX_LANG_FRENCH,
        &kmx_ldb_french,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_FRENCH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_GERMAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_GERMAN,
        KMX_LANG_GERMAN,
        &kmx_ldb_german,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_GERMAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_GERMAN) */

#if defined(KMX_CFG_LANG_GERMAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_GERMAN,
        KMX_LANG_GERMAN,
        &kmx_ldb_german,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_GERMAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_GREEK)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_GREEK,
        KMX_LANG_GREEK,
        &kmx_ldb_greek,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_GREEK_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_GREEK) */

#if defined(KMX_CFG_LANG_GREEK) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_GREEK,
        KMX_LANG_GREEK,
        &kmx_ldb_greek,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_GREEK) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_HEBREW)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_HEBREW,
        KMX_LANG_HEBREW,
        &kmx_ldb_hebrew,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_HEBREW_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_HEBREW) */

#if defined(KMX_CFG_LANG_HEBREW) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_HEBREW,
        KMX_LANG_HEBREW,
        &kmx_ldb_hebrew,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_HEBREW) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_HINDI)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_HINDI,
        KMX_LANG_HINDI,
        &kmx_ldb_hindi,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_HINDI_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_HINDI) */

#if defined(KMX_CFG_LANG_HINDI) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_HINDI,
        KMX_LANG_HINDI,
        &kmx_ldb_hindi,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_HINDI) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_HINGLISH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_HINGLISH,
        KMX_LANG_HINGLISH,
        &kmx_ldb_hinglish,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_HINGLISH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_HINGLISH) */

#if defined(KMX_CFG_LANG_HINGLISH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_HINGLISH,
        KMX_LANG_HINGLISH,
        &kmx_ldb_hinglish,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_HINGLISH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_HUNGARIAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_HUNGARIAN,
        KMX_LANG_HUNGARIAN,
        &kmx_ldb_hungarian,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_HUNGARIAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_HUNGARIAN) */

#if defined(KMX_CFG_LANG_HUNGARIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_HUNGARIAN,
        KMX_LANG_HUNGARIAN,
        &kmx_ldb_hungarian,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_HUNGARIAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_INDONESIAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_INDONESIAN,
        KMX_LANG_INDONESIAN,
        &kmx_ldb_indonesian,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_INDONESIAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_INDONESIAN) */

#if defined(KMX_CFG_LANG_INDONESIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_INDONESIAN,
        KMX_LANG_INDONESIAN,
        &kmx_ldb_indonesian,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_INDONESIAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_ITALIAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_ITALIAN,
        KMX_LANG_ITALIAN,
        &kmx_ldb_italian,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_ITALIAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_ITALIAN) */

#if defined(KMX_CFG_LANG_ITALIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_ITALIAN,
        KMX_LANG_ITALIAN,
        &kmx_ldb_italian,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_ITALIAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_MALAY)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_MALAY,
        KMX_LANG_MALAY,
        &kmx_ldb_malay,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_MALAY_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_MALAY) */

#if defined(KMX_CFG_LANG_MALAY) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_MALAY,
        KMX_LANG_MALAY,
        &kmx_ldb_malay,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_MALAY) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_NORWEGIAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_NORWEGIAN,
        KMX_LANG_NORWEGIAN,
        &kmx_ldb_norwegian,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_NORWEGIAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_NORWEGIAN) */

#if defined(KMX_CFG_LANG_NORWEGIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_NORWEGIAN,
        KMX_LANG_NORWEGIAN,
        &kmx_ldb_norwegian,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_NORWEGIAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_PERSIAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_PERSIAN,
        KMX_LANG_PERSIAN,
        &kmx_ldb_persian,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_PERSIAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_PERSIAN) */

#if defined(KMX_CFG_LANG_PERSIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_PERSIAN,
        KMX_LANG_PERSIAN,
        &kmx_ldb_persian,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_PERSIAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_POLISH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_POLISH,
        KMX_LANG_POLISH,
        &kmx_ldb_polish,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_POLISH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_POLISH) */

#if defined(KMX_CFG_LANG_POLISH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_POLISH,
        KMX_LANG_POLISH,
        &kmx_ldb_polish,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_POLISH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_PORTUGUESE)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_PORTUGUESE,
        KMX_LANG_PORTUGUESE,
        &kmx_ldb_portuguese,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_PORTUGUESE_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_PORTUGUESE) */

#if defined(KMX_CFG_LANG_PORTUGUESE) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_PORTUGUESE,
        KMX_LANG_PORTUGUESE,
        &kmx_ldb_portuguese,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_PORTUGUESE) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_ROMANIAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_ROMANIAN,
        KMX_LANG_ROMANIAN,
        &kmx_ldb_romanian,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_ROMANIAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_ROMANIAN) */

#if defined(KMX_CFG_LANG_ROMANIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_ROMANIAN,
        KMX_LANG_ROMANIAN,
        &kmx_ldb_romanian,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_ROMANIAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_RUSSIAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_RUSSIAN,
        KMX_LANG_RUSSIAN,
        &kmx_ldb_russian,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_RUSSIAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_RUSSIAN) */

#if defined(KMX_CFG_LANG_RUSSIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_RUSSIAN,
        KMX_LANG_RUSSIAN,
        &kmx_ldb_russian,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_RUSSIAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_SLOVAK)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_SLOVAK,
        KMX_LANG_SLOVAK,
        &kmx_ldb_slovak,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_SLOVAK_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_SLOVAK) */

#if defined(KMX_CFG_LANG_SLOVAK) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_SLOVAK,
        KMX_LANG_SLOVAK,
        &kmx_ldb_slovak,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_SLOVAK) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_SLOVENIAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_SLOVENIAN,
        KMX_LANG_SLOVENIAN,
        &kmx_ldb_slovenian,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_SLOVENIAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_SLOVENIAN) */

#if defined(KMX_CFG_LANG_SLOVENIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_SLOVENIAN,
        KMX_LANG_SLOVENIAN,
        &kmx_ldb_slovenian,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_SLOVENIAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_SPANISH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_SPANISH,
        KMX_LANG_SPANISH,
        &kmx_ldb_spanish,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_SPANISH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_SPANISH) */

#if defined(KMX_CFG_LANG_SPANISH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_SPANISH,
        KMX_LANG_SPANISH,
        &kmx_ldb_spanish,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_SPANISH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_SWAHILI)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_SWAHILI,
        KMX_LANG_SWAHILI,
        &kmx_ldb_swahili,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_SWAHILI_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_SWAHILI) */

#if defined(KMX_CFG_LANG_SWAHILI) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_SWAHILI,
        KMX_LANG_SWAHILI,
        &kmx_ldb_swahili,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_SWAHILI) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_SWEDISH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_SWEDISH,
        KMX_LANG_SWEDISH,
        &kmx_ldb_swedish,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_SWEDISH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_SWEDISH) */

#if defined(KMX_CFG_LANG_SWEDISH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_SWEDISH,
        KMX_LANG_SWEDISH,
        &kmx_ldb_swedish,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_SWEDISH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_THAI)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_THAI,
        KMX_LANG_THAI,
        &kmx_ldb_thai,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_THAI_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_THAI) */

#if defined(KMX_CFG_LANG_THAI) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_THAI,
        KMX_LANG_THAI,
        &kmx_ldb_thai,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_THAI) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_TURKISH)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_TURKISH,
        KMX_LANG_TURKISH,
        &kmx_ldb_turkish,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_TURKISH_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_TURKISH) */

#if defined(KMX_CFG_LANG_TURKISH) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_TURKISH,
        KMX_LANG_TURKISH,
        &kmx_ldb_turkish,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_TURKISH) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_UKRAINIAN)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_UKRAINIAN,
        KMX_LANG_UKRAINIAN,
        &kmx_ldb_ukrainian,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_UKRAINIAN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_UKRAINIAN) */

#if defined(KMX_CFG_LANG_UKRAINIAN) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_UKRAINIAN,
        KMX_LANG_UKRAINIAN,
        &kmx_ldb_ukrainian,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_UKRAINIAN) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
    {
        KMX_IME_PINYIN,
        KMX_LANG_CHINESE_SIMPLIFIED,
        KMX_LANG_CHINESE_SIMPLIFIED,
        &kmx_ldb_pinyin_chs,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_CHS_PINYIN_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),    
        KMX_PINYIN_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED) */

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
    {
        KMX_IME_BOPOMOFO,
        KMX_LANG_CHINESE_TRADITIONAL,
        KMX_LANG_CHINESE_TRADITIONAL,
        &kmx_ldb_zhuyin_cht,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_CHT_BOPOMOFO_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),    
        KMX_BOPOMOFO_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL) */

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
    {
        KMX_IME_STROKE,
        KMX_LANG_CHINESE_SIMPLIFIED,
        KMX_LANG_CHINESE_SIMPLIFIED,
        &kmx_ldb_pinyin_chs,
        &kmx_ldb_stroke_chs,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_CHS_STROKE_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),    
        KMX_STROKE_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED) */

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
    {
        KMX_IME_STROKE,
        KMX_LANG_CHINESE_TRADITIONAL,
        KMX_LANG_CHINESE_TRADITIONAL,
        &kmx_ldb_zhuyin_cht,
        &kmx_ldb_stroke_big5,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_CHT_STROKE_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),    
        KMX_STROKE_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL) */

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_QUICK_SEARCH_CHS_PINYIN,
        KMX_LANG_QUICK_SEARCH_CHS_PINYIN,
        0,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED) */

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_QUICK_SEARCH_CHT_BOPOMOFO,
        KMX_LANG_QUICK_SEARCH_CHT_BOPOMOFO,
        0,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL) */

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_QUICK_SEARCH_CHS_STROKE,
        KMX_LANG_QUICK_SEARCH_CHS_STROKE,
        0,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED) */

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_QUICK_SEARCH_CHT_STROKE,
        KMX_LANG_QUICK_SEARCH_CHT_STROKE,
        0,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL) */

#if defined(KMX_CFG_LANG_ARABIC)
    {
        KMX_IME_NUM,
        KMX_LANG_ARABIC,
        KMX_LANG_ARABIC,
        0,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_ARABIC) */

#if defined(KMX_CFG_LANG_URDU)
    {
        KMX_IME_LATIN_SMART,
        KMX_LANG_URDU,
        KMX_LANG_URDU,
        &kmx_ldb_urdu,
        0,
        KMX_LOAD_UDB(g_kmx_user_data + KMX_URDU_USER_DATA_START * KMX_USER_DATA_BLOCK_SIZE / 4),
        KMX_ALPHABETIC_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE
    },
#endif /* #if defined(KMX_CFG_LANG_PERSIAN) */

#if defined(KMX_CFG_LANG_URDU) && defined(KMX_CFG_MULTITAP_INPUT)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_URDU,
        KMX_LANG_URDU,
        &kmx_ldb_urdu,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_URDU) && defined(KMX_CFG_MULTITAP_INPUT) */

#if defined(KMX_CFG_LANG_ENGLISH)
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_EMAIL,
        KMX_LANG_EMAIL,
        &kmx_ldb_english,
        0,
        0,
        0
    },
    {
        KMX_IME_LATIN_MULTITAP,
        KMX_LANG_URL,
        KMX_LANG_URL,
        &kmx_ldb_english,
        0,
        0,
        0
    },
#endif /* #if defined(KMX_CFG_LANG_ENGLISH) */
};

/* Input Method Configuration End */

/* Input Method Platform input mode to Input Method Configuration index */

typedef struct  
{
    int     input_mode;
    short   ime_type;
    short   case_info;    
}KMX_IME_CONFIG_INDEX;


static const KMX_IME_CONFIG_INDEX g_mode_to_config_index[] = 
{
#if defined(KMX_CFG_LANG_ENGLISH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ENGLISH,    
    #else
    KMX_IME_TYPE_SMART_ENGLISH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ENGLISH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ENGLISH,    
    #else
    KMX_IME_TYPE_SMART_ENGLISH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

{
    IMM_INPUT_MODE_123,
#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
    KMX_IME_TYPE_NUM_123,
#else
    KMX_IME_TYPE_NUMBER,
#endif
    KMX_LANG_NOCASE
},

{
    IMM_INPUT_MODE_SIGNED_123,
#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
    KMX_IME_TYPE_NUM_SIGNED_123,
#else
    KMX_IME_TYPE_NUMBER,
#endif
    KMX_LANG_NOCASE
},

{
    IMM_INPUT_MODE_FLOAT_123,
#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
    KMX_IME_TYPE_NUM_FLOAT_123,
#else
    KMX_IME_TYPE_NUMBER,
#endif
    KMX_LANG_NOCASE
},

{
    IMM_INPUT_MODE_PHONE_NUMBER,
#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
    KMX_IME_TYPE_NUM_PHONE_NUMBER,
#else
    KMX_IME_TYPE_NUMBER,
#endif
    KMX_LANG_NOCASE
},

{
    IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR,
#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
    KMX_IME_TYPE_NUM_PHONE_NUMBER_WILDCHAR,
#else
    KMX_IME_TYPE_NUMBER,
#endif
    KMX_LANG_NOCASE
},

{
    IMM_INPUT_MODE_SIM_NUMERIC,
    KMX_IME_TYPE_NUMBER,
    KMX_LANG_NOCASE
},

{
    IMM_INPUT_MODE_SIGNED_FLOAT_123,
#if defined(KMX_CFG_MULTI_NUM_LAYOUT)
    KMX_IME_TYPE_NUM_SIGNED_FLOAT_123,
#else
    KMX_IME_TYPE_NUMBER,
#endif
    KMX_LANG_NOCASE
},

#if defined(KMX_CFG_LANG_ENGLISH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ENGLISH,    
    #else
    KMX_IME_TYPE_SMART_ENGLISH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ENGLISH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ENGLISH,    
    #else
    KMX_IME_TYPE_SMART_ENGLISH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

{
    IMM_INPUT_MODE_123_SYMBOLS,
    KMX_IME_TYPE_NUMBER,
    KMX_LANG_NOCASE
},

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
{
    IMM_INPUT_MODE_TR_MULTITAP_BOPOMO,
    KMX_IME_TYPE_CHT_BOPOMOFO,    
    KMX_LANG_NOCASE                
},
#endif
#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
{
    IMM_INPUT_MODE_SM_MULTITAP_PINYIN,
    KMX_IME_TYPE_CHS_PINYIN,    
    KMX_LANG_NOCASE                
},
#endif
#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
{
    IMM_INPUT_MODE_TR_BOPOMO,
    KMX_IME_TYPE_CHT_BOPOMOFO,    
    KMX_LANG_NOCASE                
},
#endif
#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
{
    IMM_INPUT_MODE_SM_PINYIN,
    KMX_IME_TYPE_CHS_PINYIN,    
    KMX_LANG_NOCASE                
},
#endif
#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
{
    IMM_INPUT_MODE_TR_STROKE,
    KMX_IME_TYPE_CHT_STROKE,    
    KMX_LANG_NOCASE                
},
#endif
#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
{
    IMM_INPUT_MODE_SM_STROKE,
    KMX_IME_TYPE_CHS_STROKE,    
    KMX_LANG_NOCASE                
},
#endif
#if defined(KMX_CFG_LANG_ENGLISH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
    KMX_IME_TYPE_SMART_ENGLISH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ENGLISH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ABC,
    KMX_IME_TYPE_SMART_ENGLISH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ENGLISH)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC,
    KMX_IME_TYPE_SMART_ENGLISH,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_THAI)
{
    IMM_INPUT_MODE_MULTITAP_THAI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_THAI,    
    #else
    KMX_IME_TYPE_SMART_THAI,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_THAI)
{
    IMM_INPUT_MODE_SMART_THAI,
    KMX_IME_TYPE_SMART_THAI,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_ARABIC)
{
    IMM_INPUT_MODE_MULTITAP_ARABIC,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ARABIC,    
    #else
    KMX_IME_TYPE_SMART_ARABIC,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_ARABIC)
{
    IMM_INPUT_MODE_SMART_ARABIC,
    KMX_IME_TYPE_SMART_ARABIC,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_ARABIC)
{
    IMM_INPUT_MODE_ARABIC_NUMERIC,
    KMX_IME_TYPE_ARABIC_NUMERIC,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_PERSIAN)
{
    IMM_INPUT_MODE_MULTITAP_PERSIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_PERSIAN,    
    #else
    KMX_IME_TYPE_SMART_PERSIAN,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_PERSIAN)
{
    IMM_INPUT_MODE_SMART_PERSIAN,
    KMX_IME_TYPE_SMART_PERSIAN,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_URDU)
{
    IMM_INPUT_MODE_MULTITAP_URDU,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_URDU,    
    #else
    KMX_IME_TYPE_SMART_URDU,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_URDU)
{
    IMM_INPUT_MODE_SMART_URDU,
    KMX_IME_TYPE_SMART_URDU,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_HEBREW)
{
    IMM_INPUT_MODE_MULTITAP_HEBREW,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_HEBREW,    
    #else
    KMX_IME_TYPE_SMART_HEBREW,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_HEBREW)
{
    IMM_INPUT_MODE_SMART_HEBREW,
    KMX_IME_TYPE_SMART_HEBREW,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_SPANISH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SPANISH,    
    #else
    KMX_IME_TYPE_SMART_SPANISH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_SPANISH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SPANISH,    
    #else
    KMX_IME_TYPE_SMART_SPANISH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_SPANISH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH,
    KMX_IME_TYPE_SMART_SPANISH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_SPANISH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH,
    KMX_IME_TYPE_SMART_SPANISH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_SPANISH)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH,
    KMX_IME_TYPE_SMART_SPANISH,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_DANISH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_DANISH,    
    #else
    KMX_IME_TYPE_SMART_DANISH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_DANISH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_DANISH,    
    #else
    KMX_IME_TYPE_SMART_DANISH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_DANISH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_DANISH,
    KMX_IME_TYPE_SMART_DANISH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_DANISH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_DANISH,
    KMX_IME_TYPE_SMART_DANISH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_DANISH)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DANISH,
    KMX_IME_TYPE_SMART_DANISH,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_POLISH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_POLISH,    
    #else
    KMX_IME_TYPE_SMART_POLISH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_POLISH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_POLISH,    
    #else
    KMX_IME_TYPE_SMART_POLISH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_POLISH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_POLISH,
    KMX_IME_TYPE_SMART_POLISH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_POLISH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_POLISH,
    KMX_IME_TYPE_SMART_POLISH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_POLISH)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_POLISH,
    KMX_IME_TYPE_SMART_POLISH,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_FRENCH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_FRENCH,    
    #else
    KMX_IME_TYPE_SMART_FRENCH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_FRENCH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_FRENCH,    
    #else
    KMX_IME_TYPE_SMART_FRENCH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_FRENCH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH,
    KMX_IME_TYPE_SMART_FRENCH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_FRENCH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH,
    KMX_IME_TYPE_SMART_FRENCH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_FRENCH)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FRENCH,
    KMX_IME_TYPE_SMART_FRENCH,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_GERMAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GERMAN,    
    #else
    KMX_IME_TYPE_SMART_GERMAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_GERMAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GERMAN,    
    #else
    KMX_IME_TYPE_SMART_GERMAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_GERMAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_GERMAN,
    KMX_IME_TYPE_SMART_GERMAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_GERMAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_GERMAN,
    KMX_IME_TYPE_SMART_GERMAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_GERMAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GERMAN,
    KMX_IME_TYPE_SMART_GERMAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_ITALIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ITALIAN,    
    #else
    KMX_IME_TYPE_SMART_ITALIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ITALIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ITALIAN,    
    #else
    KMX_IME_TYPE_SMART_ITALIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ITALIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ITALIAN,
    KMX_IME_TYPE_SMART_ITALIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ITALIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN,
    KMX_IME_TYPE_SMART_ITALIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ITALIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ITALIAN,
    KMX_IME_TYPE_SMART_ITALIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_RUSSIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_RUSSIAN,    
    #else
    KMX_IME_TYPE_SMART_RUSSIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_RUSSIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_RUSSIAN,    
    #else
    KMX_IME_TYPE_SMART_RUSSIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_RUSSIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN,
    KMX_IME_TYPE_SMART_RUSSIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_RUSSIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN,
    KMX_IME_TYPE_SMART_RUSSIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_RUSSIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_RUSSIAN,
    KMX_IME_TYPE_SMART_RUSSIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_BULGARIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_BULGARIAN,    
    #else
    KMX_IME_TYPE_SMART_BULGARIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_BULGARIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_BULGARIAN,    
    #else
    KMX_IME_TYPE_SMART_BULGARIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_UKRAINIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_UKRAINIAN,    
    #else
    KMX_IME_TYPE_SMART_UKRAINIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_UKRAINIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_UKRAINIAN,    
    #else
    KMX_IME_TYPE_SMART_UKRAINIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_UKRAINIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN,
    KMX_IME_TYPE_SMART_UKRAINIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_UKRAINIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN,
    KMX_IME_TYPE_SMART_UKRAINIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_UKRAINIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_UKRAINIAN,
    KMX_IME_TYPE_SMART_UKRAINIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_BULGARIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN,
    KMX_IME_TYPE_SMART_BULGARIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_BULGARIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN,
    KMX_IME_TYPE_SMART_BULGARIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_BULGARIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_BULGARIAN,
    KMX_IME_TYPE_SMART_BULGARIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_TURKISH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_TURKISH,    
    #else
    KMX_IME_TYPE_SMART_TURKISH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_TURKISH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_TURKISH,    
    #else
    KMX_IME_TYPE_SMART_TURKISH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_TURKISH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_TURKISH,
    KMX_IME_TYPE_SMART_TURKISH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_TURKISH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH,
    KMX_IME_TYPE_SMART_TURKISH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_TURKISH)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TURKISH,
    KMX_IME_TYPE_SMART_TURKISH,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_PORTUGUESE)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_PORTUGUESE,    
    #else
    KMX_IME_TYPE_SMART_PORTUGUESE,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_PORTUGUESE)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_PORTUGUESE,    
    #else
    KMX_IME_TYPE_SMART_PORTUGUESE,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_PORTUGUESE)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE,
    KMX_IME_TYPE_SMART_PORTUGUESE,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_PORTUGUESE)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,
    KMX_IME_TYPE_SMART_PORTUGUESE,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_PORTUGUESE)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_PORTUGUESE,
    KMX_IME_TYPE_SMART_PORTUGUESE,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_HINDI)
{
    IMM_INPUT_MODE_MULTITAP_HINDI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_HINDI,    
    #else
    KMX_IME_TYPE_SMART_HINDI,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_HINDI)
{
    IMM_INPUT_MODE_SMART_HINDI,
    KMX_IME_TYPE_SMART_HINDI,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_HINGLISH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_HINGLISH,
    KMX_IME_TYPE_SMART_HINGLISH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_HINGLISH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_HINGLISH,
    KMX_IME_TYPE_SMART_HINGLISH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_INDONESIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_INDONESIAN,    
    #else
    KMX_IME_TYPE_SMART_INDONESIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_INDONESIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_INDONESIAN,    
    #else
    KMX_IME_TYPE_SMART_INDONESIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_INDONESIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN,
    KMX_IME_TYPE_SMART_INDONESIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_INDONESIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN,
    KMX_IME_TYPE_SMART_INDONESIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_INDONESIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_INDONESIAN,
    KMX_IME_TYPE_SMART_INDONESIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_CZECH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_CZECH,    
    #else
    KMX_IME_TYPE_SMART_CZECH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_CZECH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_CZECH,    
    #else
    KMX_IME_TYPE_SMART_CZECH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_CZECH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_CZECH,
    KMX_IME_TYPE_SMART_CZECH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_CZECH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_CZECH,
    KMX_IME_TYPE_SMART_CZECH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_CZECH)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CZECH,
    KMX_IME_TYPE_SMART_CZECH,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_MALAY)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_MALAY,    
    #else
    KMX_IME_TYPE_SMART_MALAY,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_MALAY)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_MALAY,    
    #else
    KMX_IME_TYPE_SMART_MALAY,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_MALAY)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_MALAY,
    KMX_IME_TYPE_SMART_MALAY,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_MALAY)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_MALAY,
    KMX_IME_TYPE_SMART_MALAY,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_MALAY)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MALAY,
    KMX_IME_TYPE_SMART_MALAY,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_VIETNAMESE)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE,
    KMX_IME_TYPE_MULTITAP_VIETNAMESE,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_VIETNAMESE)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE,
    KMX_IME_TYPE_MULTITAP_VIETNAMESE,    
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_VIETNAMESE)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE,
    KMX_IME_TYPE_SMART_VIETNAMESE,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_VIETNAMESE)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE,
    KMX_IME_TYPE_SMART_VIETNAMESE,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_VIETNAMESE)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_VIETNAMESE,
    KMX_IME_TYPE_SMART_VIETNAMESE,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_FINNISH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_FINNISH,    
    #else
    KMX_IME_TYPE_SMART_FINNISH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_FINNISH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_FINNISH,    
    #else
    KMX_IME_TYPE_SMART_FINNISH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_FINNISH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_FINNISH,
    KMX_IME_TYPE_SMART_FINNISH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_FINNISH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_FINNISH,
    KMX_IME_TYPE_SMART_FINNISH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_FINNISH)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FINNISH,
    KMX_IME_TYPE_SMART_FINNISH,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_HUNGARIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_HUNGARIAN,    
    #else
    KMX_IME_TYPE_SMART_HUNGARIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_HUNGARIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_HUNGARIAN,    
    #else
    KMX_IME_TYPE_SMART_HUNGARIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_HUNGARIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN,
    KMX_IME_TYPE_SMART_HUNGARIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_HUNGARIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN,
    KMX_IME_TYPE_SMART_HUNGARIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_HUNGARIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HUNGARIAN,
    KMX_IME_TYPE_SMART_HUNGARIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_SLOVAK)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SLOVAK,    
    #else
    KMX_IME_TYPE_SMART_SLOVAK,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_SLOVAK)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SLOVAK,    
    #else
    KMX_IME_TYPE_SMART_SLOVAK,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_SLOVAK)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVAK,
    KMX_IME_TYPE_SMART_SLOVAK,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_SLOVAK)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVAK,
    KMX_IME_TYPE_SMART_SLOVAK,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_SLOVAK)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVAK,
    KMX_IME_TYPE_SMART_SLOVAK,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_DUTCH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_DUTCH,    
    #else
    KMX_IME_TYPE_SMART_DUTCH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_DUTCH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_DUTCH,    
    #else
    KMX_IME_TYPE_SMART_DUTCH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_DUTCH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_DUTCH,
    KMX_IME_TYPE_SMART_DUTCH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_DUTCH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_DUTCH,
    KMX_IME_TYPE_SMART_DUTCH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_DUTCH)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DUTCH,
    KMX_IME_TYPE_SMART_DUTCH,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_NORWEGIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_NORWEGIAN,    
    #else
    KMX_IME_TYPE_SMART_NORWEGIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_NORWEGIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_NORWEGIAN,    
    #else
    KMX_IME_TYPE_SMART_NORWEGIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_NORWEGIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN,
    KMX_IME_TYPE_SMART_NORWEGIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_NORWEGIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN,
    KMX_IME_TYPE_SMART_NORWEGIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_NORWEGIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_NORWEGIAN,
    KMX_IME_TYPE_SMART_NORWEGIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_SWEDISH)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SWEDISH,    
    #else
    KMX_IME_TYPE_SMART_SWEDISH,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_SWEDISH)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SWEDISH,    
    #else
    KMX_IME_TYPE_SMART_SWEDISH,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_SWEDISH)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SWEDISH,
    KMX_IME_TYPE_SMART_SWEDISH,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_SWEDISH)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SWEDISH,
    KMX_IME_TYPE_SMART_SWEDISH,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_SWEDISH)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWEDISH,
    KMX_IME_TYPE_SMART_SWEDISH,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_CROATIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_CROATIAN,    
    #else
    KMX_IME_TYPE_SMART_CROATIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_CROATIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_CROATIAN,    
    #else
    KMX_IME_TYPE_SMART_CROATIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_CROATIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_CROATIAN,
    KMX_IME_TYPE_SMART_CROATIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_CROATIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_CROATIAN,
    KMX_IME_TYPE_SMART_CROATIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_CROATIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CROATIAN,
    KMX_IME_TYPE_SMART_CROATIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_ROMANIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ROMANIAN,    
    #else
    KMX_IME_TYPE_SMART_ROMANIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ROMANIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ROMANIAN,    
    #else
    KMX_IME_TYPE_SMART_ROMANIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ROMANIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN,
    KMX_IME_TYPE_SMART_ROMANIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ROMANIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN,
    KMX_IME_TYPE_SMART_ROMANIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ROMANIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ROMANIAN,
    KMX_IME_TYPE_SMART_ROMANIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_SLOVENIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SLOVENIAN,    
    #else
    KMX_IME_TYPE_SMART_SLOVENIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_SLOVENIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SLOVENIAN,    
    #else
    KMX_IME_TYPE_SMART_SLOVENIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_SLOVENIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN,
    KMX_IME_TYPE_SMART_SLOVENIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_SLOVENIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN,
    KMX_IME_TYPE_SMART_SLOVENIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_SLOVENIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVENIAN,
    KMX_IME_TYPE_SMART_SLOVENIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_GREEK)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GREEK,    
    #else
    KMX_IME_TYPE_SMART_GREEK,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_GREEK)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GREEK,    
    #else
    KMX_IME_TYPE_SMART_GREEK,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_GREEK)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_GREEK,
    KMX_IME_TYPE_SMART_GREEK,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_GREEK)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_GREEK,
    KMX_IME_TYPE_SMART_GREEK,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_GREEK)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GREEK,
    KMX_IME_TYPE_SMART_GREEK,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_XHOSA)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_XHOSA,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_XHOSA,    
    #else
    KMX_IME_TYPE_SMART_XHOSA,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_XHOSA)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_XHOSA,    
    #else
    KMX_IME_TYPE_SMART_XHOSA,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_XHOSA)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_XHOSA,
    KMX_IME_TYPE_SMART_XHOSA,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_XHOSA)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_XHOSA,
    KMX_IME_TYPE_SMART_XHOSA,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_XHOSA)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_XHOSA,
    KMX_IME_TYPE_SMART_XHOSA,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_SWAHILI)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SWAHILI,    
    #else
    KMX_IME_TYPE_SMART_SWAHILI,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_SWAHILI)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SWAHILI,    
    #else
    KMX_IME_TYPE_SMART_SWAHILI,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_SWAHILI)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SWAHILI,
    KMX_IME_TYPE_SMART_SWAHILI,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_SWAHILI)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SWAHILI,
    KMX_IME_TYPE_SMART_SWAHILI,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_SWAHILI)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWAHILI,
    KMX_IME_TYPE_SMART_SWAHILI,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_AFRIKAANS)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_AFRIKAANS,    
    #else
    KMX_IME_TYPE_SMART_AFRIKAANS,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_AFRIKAANS)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_AFRIKAANS,    
    #else
    KMX_IME_TYPE_SMART_AFRIKAANS,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_AFRIKAANS)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS,
    KMX_IME_TYPE_SMART_AFRIKAANS,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_AFRIKAANS)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS,
    KMX_IME_TYPE_SMART_AFRIKAANS,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_AFRIKAANS)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_AFRIKAANS,
    KMX_IME_TYPE_SMART_AFRIKAANS,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_ZULU)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ZULU,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ZULU,    
    #else
    KMX_IME_TYPE_SMART_ZULU,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ZULU)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ZULU,    
    #else
    KMX_IME_TYPE_SMART_ZULU,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ZULU)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ZULU,
    KMX_IME_TYPE_SMART_ZULU,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ZULU)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ZULU,
    KMX_IME_TYPE_SMART_ZULU,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ZULU)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ZULU,
    KMX_IME_TYPE_SMART_ZULU,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_LITHUANIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_LITHUANIAN,    
    #else
    KMX_IME_TYPE_SMART_LITHUANIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_LITHUANIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_LITHUANIAN,    
    #else
    KMX_IME_TYPE_SMART_LITHUANIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_LITHUANIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN,
    KMX_IME_TYPE_SMART_LITHUANIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_LITHUANIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN,
    KMX_IME_TYPE_SMART_LITHUANIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_LITHUANIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LITHUANIAN,
    KMX_IME_TYPE_SMART_LITHUANIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_LATVIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LATVIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_LATVIAN,    
    #else
    KMX_IME_TYPE_SMART_LATVIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_LATVIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_LATVIAN,    
    #else
    KMX_IME_TYPE_SMART_LATVIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_LATVIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_LATVIAN,
    KMX_IME_TYPE_SMART_LATVIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_LATVIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_LATVIAN,
    KMX_IME_TYPE_SMART_LATVIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_LATVIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LATVIAN,
    KMX_IME_TYPE_SMART_LATVIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_ESTONIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ESTONIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ESTONIAN,    
    #else
    KMX_IME_TYPE_SMART_ESTONIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ESTONIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ESTONIAN,    
    #else
    KMX_IME_TYPE_SMART_ESTONIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ESTONIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ESTONIAN,
    KMX_IME_TYPE_SMART_ESTONIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ESTONIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN,
    KMX_IME_TYPE_SMART_ESTONIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ESTONIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ESTONIAN,
    KMX_IME_TYPE_SMART_ESTONIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_ARMENIAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ARMENIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ARMENIAN,    
    #else
    KMX_IME_TYPE_SMART_ARMENIAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ARMENIAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ARMENIAN,    
    #else
    KMX_IME_TYPE_SMART_ARMENIAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ARMENIAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN,
    KMX_IME_TYPE_SMART_ARMENIAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_ARMENIAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ARMENIAN,
    KMX_IME_TYPE_SMART_ARMENIAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_ARMENIAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ARMENIAN,
    KMX_IME_TYPE_SMART_ARMENIAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_GEORGIAN)
{
    IMM_INPUT_MODE_MULTITAP_GEORGIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GEORGIAN,    
    #else
    KMX_IME_TYPE_SMART_GEORGIAN,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_GEORGIAN)
{
    IMM_INPUT_MODE_SMART_GEORGIAN,
    KMX_IME_TYPE_SMART_GEORGIAN,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_MOLDOVAN)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MOLDOVAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_MOLDOVAN,    
    #else
    KMX_IME_TYPE_SMART_MOLDOVAN,
    #endif
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_MOLDOVAN)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MOLDOVAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_MOLDOVAN,    
    #else
    KMX_IME_TYPE_SMART_MOLDOVAN,
    #endif
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_MOLDOVAN)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_MOLDOVAN,
    KMX_IME_TYPE_SMART_MOLDOVAN,
    KMX_LANG_UPPERCASE
},
#endif

#if defined(KMX_CFG_LANG_MOLDOVAN)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_MOLDOVAN,
    KMX_IME_TYPE_SMART_MOLDOVAN,
    KMX_LANG_LOWERCASE
},
#endif

#if defined(KMX_CFG_LANG_MOLDOVAN)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MOLDOVAN,
    KMX_IME_TYPE_SMART_MOLDOVAN,
    KMX_LANG_INITIALCASE
},
#endif

#if defined(KMX_CFG_LANG_MARATHI)
{
    IMM_INPUT_MODE_MULTITAP_MARATHI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_MARATHI,    
    #else
    KMX_IME_TYPE_SMART_MARATHI,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_MARATHI)
{
    IMM_INPUT_MODE_SMART_MARATHI,
    KMX_IME_TYPE_SMART_MARATHI,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_TAMIL)
{
    IMM_INPUT_MODE_MULTITAP_TAMIL,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_TAMIL,    
    #else
    KMX_IME_TYPE_SMART_TAMIL,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_TAMIL)
{
    IMM_INPUT_MODE_SMART_TAMIL,
    KMX_IME_TYPE_SMART_TAMIL,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_BENGALI)
{
    IMM_INPUT_MODE_MULTITAP_BENGALI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_BENGALI,    
    #else
    KMX_IME_TYPE_SMART_BENGALI,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_BENGALI)
{
    IMM_INPUT_MODE_SMART_BENGALI,
    KMX_IME_TYPE_SMART_BENGALI,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_PUNJABI)
{
    IMM_INPUT_MODE_MULTITAP_PUNJABI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_PUNJABI,    
    #else
    KMX_IME_TYPE_SMART_PUNJABI,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_PUNJABI)
{
    IMM_INPUT_MODE_MMI_MULTITAP_PUNJABI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_PUNJABI,    
    #else
    KMX_IME_TYPE_SMART_PUNJABI,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_PUNJABI)
{
    IMM_INPUT_MODE_SMART_PUNJABI,
    KMX_IME_TYPE_SMART_PUNJABI,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_TELUGU)
{
    IMM_INPUT_MODE_MULTITAP_TELUGU,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_TELUGU,    
    #else
    KMX_IME_TYPE_SMART_TELUGU,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_TELUGU)
{
    IMM_INPUT_MODE_SMART_TELUGU,
    KMX_IME_TYPE_SMART_TELUGU,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_KANNADA)
{
    IMM_INPUT_MODE_MULTITAP_KANNADA,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_KANNADA,    
    #else
    KMX_IME_TYPE_SMART_KANNADA,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_KANNADA)
{
    IMM_INPUT_MODE_MMI_MULTITAP_KANNADA,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_KANNADA,    
    #else
    KMX_IME_TYPE_SMART_KANNADA,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_KANNADA)
{
    IMM_INPUT_MODE_SMART_KANNADA,
    KMX_IME_TYPE_SMART_KANNADA,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_GUJARATI)
{
    IMM_INPUT_MODE_MULTITAP_GUJARATI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GUJARATI,    
    #else
    KMX_IME_TYPE_SMART_GUJARATI,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_GUJARATI)
{
    IMM_INPUT_MODE_MMI_MULTITAP_GUJARATI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GUJARATI,    
    #else
    KMX_IME_TYPE_SMART_GUJARATI,
    #endif
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_GUJARATI)
{
    IMM_INPUT_MODE_SMART_GUJARATI,
    KMX_IME_TYPE_SMART_GUJARATI,
    KMX_LANG_NOCASE
},
#endif

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
{
    IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO,
    KMX_IME_TYPE_QUICK_SEARCH_CHT_BOPOMOFO,    
    KMX_LANG_NOCASE                
},
#endif

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
{
    IMM_INPUT_MODE_QUICK_SEARCH_PINYIN,
    KMX_IME_TYPE_QUICK_SEARCH_CHS_PINYIN,    
    KMX_LANG_LOWERCASE                
},
#endif

{
    IMM_INPUT_MODE_KEYPAD_NUMERIC,
    KMX_IME_TYPE_NUMBER,
    KMX_LANG_NOCASE
},

#if defined(KMX_CFG_LANG_CHINESE_SIMPLIFIED)
{
    IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE,
    KMX_IME_TYPE_QUICK_SEARCH_CHS_STROKE,    
    KMX_LANG_NOCASE                
},
#endif

#if defined(KMX_CFG_LANG_CHINESE_TRADITIONAL)
{
    IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE,
    KMX_IME_TYPE_QUICK_SEARCH_CHT_STROKE,    
    KMX_LANG_NOCASE                
},
#endif

{
    IMM_INPUT_MODE_MAGIC_NUMBER,
    KMX_IME_TYPE_NUMBER,
    KMX_LANG_NOCASE
},

#if defined(KMX_CFG_LANG_ENGLISH) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ENGLISH,    
    #else
    KMX_IME_TYPE_SMART_ENGLISH,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_BULGARIAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BULGARIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_BULGARIAN,
    #else
    KMX_IME_TYPE_SMART_BULGARIAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_CZECH) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CZECH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_CZECH,
    #else
    KMX_IME_TYPE_SMART_CZECH,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_DANISH) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DANISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_DANISH,
    #else
    KMX_IME_TYPE_SMART_DANISH,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_DUTCH) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DUTCH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_DUTCH,
    #else
    KMX_IME_TYPE_SMART_DUTCH,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_FINNISH) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FINNISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_FINNISH,
    #else
    KMX_IME_TYPE_SMART_FINNISH,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_FRENCH) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FRENCH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_FRENCH,
    #else
    KMX_IME_TYPE_SMART_FRENCH,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_GERMAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GERMAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GERMAN,
    #else
    KMX_IME_TYPE_SMART_GERMAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_GREEK) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GREEK,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_GREEK,
    #else
    KMX_IME_TYPE_SMART_GREEK,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_HUNGARIAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HUNGARIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_HUNGARIAN,
    #else
    KMX_IME_TYPE_SMART_HUNGARIAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_INDONESIAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_INDONESIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_INDONESIAN,
    #else
    KMX_IME_TYPE_SMART_INDONESIAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_ITALIAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ITALIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ITALIAN,
    #else
    KMX_IME_TYPE_SMART_ITALIAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_LITHUANIAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LITHUANIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_LITHUANIAN,
    #else
    KMX_IME_TYPE_SMART_LITHUANIAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_MALAY) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MALAY,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_MALAY,
    #else
    KMX_IME_TYPE_SMART_MALAY,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_NORWEGIAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_NORWEGIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_NORWEGIAN,
    #else
    KMX_IME_TYPE_SMART_NORWEGIAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_POLISH) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_POLISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_POLISH,
    #else
    KMX_IME_TYPE_SMART_POLISH,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_PORTUGUESE) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_PORTUGUESE,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_PORTUGUESE,
    #else
    KMX_IME_TYPE_SMART_PORTUGUESE,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_ROMANIAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ROMANIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_ROMANIAN,
    #else
    KMX_IME_TYPE_SMART_ROMANIAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_RUSSIAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_RUSSIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_RUSSIAN,
    #else
    KMX_IME_TYPE_SMART_RUSSIAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_SLOVAK) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVAK,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SLOVAK,
    #else
    KMX_IME_TYPE_SMART_SLOVAK,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_SLOVENIAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVENIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SLOVENIAN,
    #else
    KMX_IME_TYPE_SMART_SLOVENIAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_SPANISH) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SPANISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SPANISH,
    #else
    KMX_IME_TYPE_SMART_SPANISH,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_SWAHILI) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWAHILI,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SWAHILI,
    #else
    KMX_IME_TYPE_SMART_SWAHILI,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_SWEDISH) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWEDISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_SWEDISH,
    #else
    KMX_IME_TYPE_SMART_SWEDISH,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_TURKISH) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TURKISH,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_TURKISH,
    #else
    KMX_IME_TYPE_SMART_TURKISH,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
#if defined(KMX_CFG_LANG_UKRAINIAN) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_UKRAINIAN,
    #if defined(KMX_CFG_MULTITAP_INPUT)
    KMX_IME_TYPE_MULTITAP_UKRAINIAN,
    #else
    KMX_IME_TYPE_SMART_UKRAINIAN,
    #endif
    KMX_LANG_INITIALCASE
},
#endif
};

typedef struct  
{
    int     input_mode;
    short   ime_type;
    short   case_info;
    unsigned int input_type;
}KMX_IME_CONFIG_INDEX_EX;

static KMX_IME_CONFIG_INDEX_EX g_mode_to_config_index_ex[] =
{
#if defined(KMX_CFG_LANG_ENGLISH)
    {
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,        
            KMX_IME_TYPE_EMAIL,            
            KMX_LANG_UPPERCASE,
            IMM_INPUT_TYPE_EMAIL
    },
#endif

#if defined(KMX_CFG_LANG_ENGLISH)
    {
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,        
            KMX_IME_TYPE_EMAIL,            
            KMX_LANG_LOWERCASE,
            IMM_INPUT_TYPE_EMAIL
    },
#endif

#if defined(KMX_CFG_LANG_ENGLISH)
    {
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,        
            KMX_IME_TYPE_URL,
            KMX_LANG_UPPERCASE,
            IMM_INPUT_TYPE_URL
    },
#endif

#if defined(KMX_CFG_LANG_ENGLISH)
    {
        IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,        
            KMX_IME_TYPE_URL,            
            KMX_LANG_LOWERCASE,
            IMM_INPUT_TYPE_URL
    },
#endif

};

static const KMX_IME_CONFIG_INDEX * kmx_get_config_index(int input_mode)
{
    int i;
    mmi_imm_input_type_enum curr_input_type;
    
    curr_input_type = mmi_ime_sdk_get_current_input_type();
    
    /* iter ex table first */
    
    for (i = 0; i < sizeof(g_mode_to_config_index_ex) / sizeof(g_mode_to_config_index_ex[0]); i++)
    {
        if (g_mode_to_config_index_ex[i].input_type == curr_input_type 
         && g_mode_to_config_index_ex[i].input_mode == input_mode)
         {
            return (KMX_IME_CONFIG_INDEX*)&g_mode_to_config_index_ex[i];
         }        
    }

    for (i = 0; i < sizeof(g_mode_to_config_index) / sizeof(g_mode_to_config_index[0]); i++)
    {
        if (g_mode_to_config_index[i].input_mode == input_mode)
        {
            return &g_mode_to_config_index[i];
        }
    }
    return NULL;
}

kmx_input_method_type_enum kmx_imm_get_ime_type(int input_mode)
{    
    const KMX_IME_CONFIG_INDEX * index;

    MMI_ASSERT(input_mode >=0 && input_mode <IMM_INPUT_MODE_MAX_NUM);

    index = kmx_get_config_index(input_mode);

    if (index)
    {
        return (kmx_input_method_type_enum)index->ime_type;
    }
    
    return KMX_IME_TYPE_MAX_NUM;

}

const KMX_IME_CONFIG * kmx_imm_get_ime_config_by_type(kmx_input_method_type_enum ime_type)
{   
    if (ime_type >= KMX_IME_TYPE_MAX_NUM)
    {
        /* use default number input. */
        return NULL;
    }
    return &g_ime_configs[ime_type];
}

const KMX_IME_CONFIG * kmx_imm_get_ime_config(int input_mode)
{
    kmx_input_method_type_enum ime_type = kmx_imm_get_ime_type(input_mode);
    return kmx_imm_get_ime_config_by_type(ime_type);
}

unsigned char kmx_imm_get_case_info_by_mode(int input_mode)
{
    const KMX_IME_CONFIG_INDEX * index;

    MMI_ASSERT(input_mode >=0 && input_mode <IMM_INPUT_MODE_MAX_NUM);
    
    index = kmx_get_config_index(input_mode);
    
    if (index)
    {
        return (unsigned char)index->case_info;
    }

    return KMX_LANG_NOCASE;
}

/* Load and Save User Data */

void kmx_load_user_data(void)
{
#ifdef KMX_CFG_USER_DATA_08
    load_user_data(g_kmx_user_data, KMX_TOTAL_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE);
#else
    {
        extern void CS_LoadUserData(void);
        CS_LoadUserData();
    }
#endif
}

void kmx_save_user_data(void)
{
#ifdef KMX_CFG_USER_DATA_08
    save_user_data(g_kmx_user_data, KMX_TOTAL_USER_DATA_SIZE * KMX_USER_DATA_BLOCK_SIZE);
#else
    {
        extern void CS_SaveUserData(void);
        CS_SaveUserData();
    }
#endif
}

#endif /* #ifdef __MMI_KMX_TOUCH_INPUT__ */
