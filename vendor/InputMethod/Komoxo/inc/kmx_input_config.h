
#ifndef KMX_INPUT_CONFIG_H
#define KMX_INPUT_CONFIG_H

#ifdef __MMI_KOMOXO__
/* Or inject this to the end of MMI_Features.h */
#include "MMI_features.h"

#ifdef _MSC_VER
    #pragma warning(disable : 4996)
    #pragma warning(disable : 4005)
    #pragma warning(disable : 4024)
#endif  

#define CFG_MMI_KMX_TOUCH_INPUT (__OFF__)

#if (defined(__MMI_KOMOXO__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_IME_FTE_ENHANCE__)) && \
    (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
#ifndef __MMI_KMX_TOUCH_INPUT__
#define __MMI_KMX_TOUCH_INPUT__
#endif
#endif

#if defined(CFG_MMI_KMX_TOUCH_INPUT) && (CFG_MMI_KMX_TOUCH_INPUT == __OFF__)
    #ifdef __MMI_KMX_TOUCH_INPUT__
    #undef __MMI_KMX_TOUCH_INPUT__
    #endif
#endif

#if defined(__MMI_KMX_TOUCH_INPUT__) \
    && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) \
    || defined(__MMI_MAINLCD_320X480__) \
    )
#ifndef __MMI_KMX_NORMAL_TOUCH_INPUT__
#define __MMI_KMX_NORMAL_TOUCH_INPUT__
#endif
#endif

#if defined(__MMI_KMX_TOUCH_INPUT__) \
    && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) \
    || defined(__MMI_MAINLCD_320X480__) \
    )
#ifndef __MMI_KMX_QWERTY_TOUCH_INPUT__
#define __MMI_KMX_QWERTY_TOUCH_INPUT__
#endif
#endif

#if defined(__MMI_KMX_TOUCH_INPUT__) && !defined(__MMI_KMX_NORMAL_TOUCH_INPUT__) && !defined(__MMI_KMX_QWERTY_TOUCH_INPUT__)
#error __MMI_KMX_NORMAL_TOUCH_INPUT__ and __MMI_KMX_QWERTY_TOUCH_INPUT__ both are disabled while __MMI_KMX_TOUCH_INPUT__ is enabled.
#endif

#if defined(__MMI_REDUCED_KEYPAD__)
    #ifndef __MMI_KMX_NO_KEYPAD__
    #define __MMI_KMX_NO_KEYPAD__
    #endif
#endif

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    #ifndef __MMI_KMX_QWERTY_ASSO__
    #define __MMI_KMX_QWERTY_ASSO__
    #endif
#endif

#if defined(__COSMOS_MMI_PACKAGE__)
    #ifndef __MMI_KMX_VUI_SUPPORT__
    #define __MMI_KMX_VUI_SUPPORT__
    #endif
#endif

#endif /* __MMI_KOMOXO__ */
#endif /* KMX_INPUT_CONFIG_H */
