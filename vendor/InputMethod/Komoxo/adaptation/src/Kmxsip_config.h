#ifndef KMXSIP_CONFIG_H
#define KMXSIP_CONFIG_H

/* Disable Microsoft Visial C++ warning */

#ifdef _MSC_VER
    /* unreferenced formal parameter                                */
    #pragma warning(disable: 4100)
    /* named type definition in parentheses                         */
    #pragma warning(disable: 4115)
    /* nonstandard extension used: nameless struct/union            */
    #pragma warning(disable: 4201)
    /* nonstandard extension used: bit field types other than int   */
    #pragma warning(disable: 4214)
    /* The file contains a character that cannot be represented in the current code page */
    #pragma warning(disable: 4819)
#endif

#ifndef KMXSIP_RESOURCE_H
    #include "kmxsip_resource.h"
#endif

#include "mmi_features.h"

#include "kmx_input_config.h"

#define KMX_USER_DATA_PATH_NAME         L"Z:\\@ime"
#define KMX_USER_DATA_FILE_NAME         L"kmx_ime_ud.dat"

#define MMI_KMX_IME_SETTING_PATH        L"Z:\\@ime"
#define MMI_KMX_IME_SETTING_FILE        L"ime_profile.dat"
    
#define ARRAY_SIZE(a)   ( sizeof(a) / sizeof((a)[0]) )
#define DEFAULT_BK_COLOR KMX_COLOR_MAKE_RGB(0x84, 0x88, 0x91)

#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_BULGARIAN__) || \
    defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_DUTCH__) || \
    defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_GERMAN__) || \
    defined(__MMI_LANG_GREEK__) || defined(__MMI_LANG_HEBREW__) || defined(__MMI_LANG_HINDI__) || \
    defined(__MMI_LANG_HUNGARIAN__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_ITALIAN__) || \
    defined(__MMI_LANG_LITHUANIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_NORWEGIAN__) || \
    defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_PORTUGUESE__) || \
    defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_SLOVAK__) || \
    defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_SWAHILI__) || \
    defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_THAI__) || defined(__MMI_LANG_TURKISH__) || \
    defined(__MMI_LANG_UKRAINIAN__) || defined(__MMI_LANG_URDU__)
    #ifndef KMX_CFG_MULTILINGUAL_SUPPORT
    #define KMX_CFG_MULTILINGUAL_SUPPORT
    #endif
#endif

#ifndef KMX_CFG_MULTI_NUM_LAYOUT
    #define KMX_CFG_MULTI_NUM_LAYOUT
#endif

#ifndef KMX_CFG_IME_SYM
    #define KMX_CFG_IME_SYM
#endif

#ifndef KMX_CFG_MULTITAP_INPUT
    #define KMX_CFG_MULTITAP_INPUT
#endif


#ifndef KMX_CFG_IME_NUM
    #define KMX_CFG_IME_NUM
#endif

#ifndef KMX_CFG_IME_LATIN_SMART
    #define KMX_CFG_IME_LATIN_SMART
#endif

#ifndef KMX_CFG_LANG_ENGLISH
    #define KMX_CFG_LANG_ENGLISH
#endif

/* Feature Config */
#ifndef KMX_CFG_DISABLE_ECHO
    #define KMX_CFG_DISABLE_ECHO
#endif


/* Language && Ime config */

#if defined(__MMI_LANG_SM_CHINESE__)
    #ifndef KMX_CFG_LANG_CHINESE_SIMPLIFIED
    #define KMX_CFG_LANG_CHINESE_SIMPLIFIED
    #endif
#endif

#if defined(__MMI_LANG_SM_CHINESE__)
    #ifndef KMX_CFG_IME_PINYIN
    #define KMX_CFG_IME_PINYIN
    #endif
#endif

#if defined(__MMI_LANG_TR_CHINESE__)
    #ifndef KMX_CFG_LANG_CHINESE_TRADITIONAL
    #define KMX_CFG_LANG_CHINESE_TRADITIONAL
    #endif
#endif

#if defined(__MMI_LANG_TR_CHINESE__)
    #ifndef KMX_CFG_IME_BOPOMOFO
    #define KMX_CFG_IME_BOPOMOFO
    #endif
#endif 

#if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)
    #ifndef KMX_CFG_IME_STROKE
    #define KMX_CFG_IME_STROKE
    #endif
#endif

/* Multilingual config */
#if defined(__MMI_LANG_BULGARIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_BULGARIAN
    #define KMX_CFG_LANG_BULGARIAN
    #endif
#endif


#if defined(__MMI_LANG_CZECH__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_CZECH
    #define KMX_CFG_LANG_CZECH
    #endif
#endif


#if defined(__MMI_LANG_DANISH__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_DANISH
    #define KMX_CFG_LANG_DANISH
    #endif
#endif


#if defined(__MMI_LANG_DUTCH__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_DUTCH
    #define KMX_CFG_LANG_DUTCH
    #endif
#endif


#if defined(__MMI_LANG_FINNISH__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_FINNISH
    #define KMX_CFG_LANG_FINNISH
    #endif
#endif


#if defined(__MMI_LANG_FRENCH__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_FRENCH
    #define KMX_CFG_LANG_FRENCH
    #endif
#endif


#if defined(__MMI_LANG_GERMAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_GERMAN
    #define KMX_CFG_LANG_GERMAN
    #endif
#endif


#if defined(__MMI_LANG_GREEK__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_GREEK
    #define KMX_CFG_LANG_GREEK
    #endif
#endif


#if defined(__MMI_CSTAR_HINGLISH__)
    #ifndef KMX_CFG_LANG_HINGLISH
    #define KMX_CFG_LANG_HINGLISH
    #endif
#endif


#if defined(__MMI_LANG_HUNGARIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_HUNGARIAN
    #define KMX_CFG_LANG_HUNGARIAN
    #endif
#endif


#if defined(__MMI_LANG_INDONESIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_INDONESIAN
    #define KMX_CFG_LANG_INDONESIAN
    #endif
#endif


#if defined(__MMI_LANG_ITALIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_ITALIAN
    #define KMX_CFG_LANG_ITALIAN
    #endif
#endif


#if defined(__MMI_LANG_LITHUANIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_LITHUANIAN
    #define KMX_CFG_LANG_LITHUANIAN
    #endif
#endif


#if defined(__MMI_LANG_MALAY__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_MALAY
    #define KMX_CFG_LANG_MALAY
    #endif
#endif


#if defined(__MMI_LANG_NORWEGIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_NORWEGIAN
    #define KMX_CFG_LANG_NORWEGIAN
    #endif
#endif


#if defined(__MMI_LANG_POLISH__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_POLISH
    #define KMX_CFG_LANG_POLISH
    #endif
#endif


#if defined(__MMI_LANG_PORTUGUESE__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_PORTUGUESE
    #define KMX_CFG_LANG_PORTUGUESE
    #endif
#endif


#if defined(__MMI_LANG_ROMANIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_ROMANIAN
    #define KMX_CFG_LANG_ROMANIAN
    #endif
#endif


#if defined(__MMI_LANG_RUSSIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_RUSSIAN
    #define KMX_CFG_LANG_RUSSIAN
    #endif
#endif


#if defined(__MMI_LANG_SLOVAK__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_SLOVAK
    #define KMX_CFG_LANG_SLOVAK
    #endif
#endif


#if defined(__MMI_LANG_SLOVENIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_SLOVENIAN
    #define KMX_CFG_LANG_SLOVENIAN
    #endif
#endif


#if defined(__MMI_LANG_SPANISH__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_SPANISH
    #define KMX_CFG_LANG_SPANISH
    #endif
#endif


#if defined(__MMI_LANG_SWAHILI__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_SWAHILI
    #define KMX_CFG_LANG_SWAHILI
    #endif
#endif


#if defined(__MMI_LANG_SWEDISH__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_SWEDISH
    #define KMX_CFG_LANG_SWEDISH
    #endif
#endif


#if defined(__MMI_LANG_TURKISH__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_TURKISH
    #define KMX_CFG_LANG_TURKISH
    #endif
#endif


#if defined(__MMI_LANG_UKRAINIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_UKRAINIAN
    #define KMX_CFG_LANG_UKRAINIAN
    #endif
#endif

#if defined(__MMI_LANG_ARABIC__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_ARABIC
    #define KMX_CFG_LANG_ARABIC
    #endif
#endif

#if defined(__MMI_LANG_PERSIAN__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_PERSIAN
    #define KMX_CFG_LANG_PERSIAN
    #endif
#endif

#if defined(__MMI_LANG_HEBREW__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_HEBREW
    #define KMX_CFG_LANG_HEBREW
    #endif
#endif

#if defined(__MMI_LANG_HINDI__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_HINDI
    #define KMX_CFG_LANG_HINDI
    #endif
#endif

#if defined(__MMI_LANG_THAI__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_THAI
    #define KMX_CFG_LANG_THAI
    #endif
#endif

#if defined(__MMI_LANG_BENGALI__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_BENGALI
    #define KMX_CFG_LANG_BENGALI
    #endif
#endif


#if defined(__MMI_LANG_URDU__) && defined(KMX_CFG_MULTILINGUAL_SUPPORT)
    #ifndef KMX_CFG_LANG_URDU
    #define KMX_CFG_LANG_URDU
    #endif
#endif


typedef struct  
{
    unsigned char enable_touch_keypad;
    unsigned char softkeyboard_type;
}KMX_USER_PROFILE;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* KMXSIP_CONFIG_H */
