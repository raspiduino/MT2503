#include "StdAfx.h"
#include "FontgenGprot.h"

#define FONT_DATA_FILE_PATH(file_name) "..\\..\\..\\vendor\\font\\FontData\\OfficialFont\\"#file_name  /* "..\\..\\..\\vendor\\font\\MTK\\official\\project\\plutommi\\content\\FontData\\"#file_name */
#define FONT_DATA_OUTPUT_PATH       (".\\FontFile")

#ifdef LOW_COST_SUPPORT
#define __MMI_FONT_RESOURCE_SLIM__
#endif

#if (defined(__MMI_LANG_ENGLISH__) || defined(__MMI_LANG_SWAHILI__) || defined(__MMI_LANG_ZULU__) || defined(__MMI_LANG_XHOSA__))&& \
     !defined(__MMI_LANG_TURKISH__)&&!defined(__MMI_LANG_VIETNAMESE__)&&!defined(__MMI_LANG_POLISH__)&&!defined(__MMI_LANG_CZECH__)&&!defined(__MMI_LANG_NORWEGIAN__)&& \
     !defined(__MMI_LANG_FINNISH__)&&!defined(__MMI_LANG_HUNGARIAN__)&&!defined(__MMI_LANG_SLOVAK__)&&!defined(__MMI_LANG_DUTCH__)&&!defined(__MMI_LANG_SWEDISH__)&& \
     !defined(__MMI_LANG_CROATIAN__)&&!defined(__MMI_LANG_ROMANIAN__)&&!defined(__MMI_LANG_MOLDOVAN__)&&!defined(__MMI_LANG_SLOVENIAN__) && !defined(__MMI_LANG_FRENCH__) && !defined(__MMI_LANG_CA_FRENCH__) && \
     !defined (__MMI_LANG_LITHUANIAN__)&&!defined (__MMI_LANG_LATVIAN__)&&!defined (__MMI_LANG_ESTONIAN__)&&!defined(__MMI_LANG_AFRIKAANS__)&&!defined(__MMI_LANG_AZERBAIJANI__)&& \
     !defined (__MMI_LANG_HAUSA__)&&!defined(__MMI_LANG_ICELANDIC__)&&!defined(__MMI_LANG_SERBIAN__)&& !defined (__MMI_LANG_IGBO__) && !defined(__MMI_LANG_SPANISH__)
#define __MMI_FONT_LATIN_BASIC__

#elif (defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_TURKISH__)|| defined(__MMI_LANG_POLISH__) ||defined(__MMI_LANG_CZECH__)||defined(__MMI_LANG_SWEDISH__)|| \
       defined(__MMI_LANG_CROATIAN__)||defined(__MMI_LANG_SLOVENIAN__)||defined(__MMI_LANG_NORWEGIAN__)||defined(__MMI_LANG_SLOVAK__)|| \
       defined(__MMI_LANG_DUTCH__)||defined(__MMI_LANG_HUNGARIAN__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__) || \
       defined (__MMI_LANG_LITHUANIAN__) || defined (__MMI_LANG_LATVIAN__) || defined (__MMI_LANG_ESTONIAN__) || defined(__MMI_LANG_AFRIKAANS__))&& \
       !defined(__MMI_LANG_ROMANIAN__)&&!defined(__MMI_LANG_MOLDOVAN__)&&!defined(__MMI_LANG_VIETNAMESE__) && !defined(__MMI_LANG_FINNISH__)&&!defined (__MMI_LANG_HAUSA__)&& !defined (__MMI_LANG_IGBO__)
#define __MMI_FONT_LATIN_EXTEND_A__

#else

#define __MMI_FONT_LATIN_ALL__

#endif


int main(int argc, char* argv[])
{
	

    InitialFontEngine(FONT_DATA_OUTPUT_PATH);

#ifndef __MMI_VECTOR_FONT_SUPPORT__

#if defined (__MMI_GUOBI_BDF_FONT__)
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Guobi\\Latin\\Latin_14.bdf),
        MCT_SMALL_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Guobi\\Latin\\Latin_20.bdf),
        MCT_MEDIUM_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Guobi\\Latin\\Latin_20.bdf),
        MCT_LARGE_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Guobi\\Latin\\Latin_12.bdf),
        MCT_SUBLCD_FONT, 0, 0);

    #if defined (__MMI_LANG_AZERBAIJANI__)
    AddFont(
        ("Azer"), ("*#0994#"), ("az-AZ"), 
        FONT_DATA_FILE_PATH(Guobi\\Azeri\\Az_16.bdf),
        MCT_SMALL_FONT, 0, 0);
    AddFont(
        ("Azer"), ("*#0994#"), ("az-AZ"), 
        FONT_DATA_FILE_PATH(Guobi\\Azeri\\Az_20.bdf),
        MCT_MEDIUM_FONT | MCT_LARGE_FONT, 0, 0);
    #endif
#else
#if defined(__MMI_FONT_LATIN_BASIC__)  

#ifdef __MMI_FONT_RESOURCE_SLIM__
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\pluto_medium.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\L_MTK_En_Medium_20.bdf),
        MCT_MEDIUM_FONT | MCT_LARGE_FONT, 0, 0);
#else
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\pluto_medium.bdf),
        MCT_SMALL_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\L_MTK_En_Medium_20.bdf),
        MCT_MEDIUM_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\L_MTK_En_Large_22.bdf),
        MCT_LARGE_FONT, 0, 0);
     AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\pluto_small.bdf),
        MCT_SUBLCD_FONT, 0, 0);
#endif /*__MMI_FONT_RESOURCE_SLIM__*/
    
    /* No sublcd bdf file now, so use small font instead of it temporary. */
   // AddFont(
    //    ("English"), ("*#0044#"), ("en-US"), 
    //    FONT_DATA_FILE_PATH(Latin\\pluto_small.bdf),
    //    MCT_DIALER_FONT,  0, 0);

#elif defined(__MMI_FONT_LATIN_EXTEND_A__)
#ifdef __MMI_FONT_RESOURCE_SLIM__
     AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R13_Turkish_14x14_4_14P.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT, 0, 0);
     AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R08_Turkish_20x20_4_20p.bdf),	
        MCT_MEDIUM_FONT | MCT_LARGE_FONT, 0, 0);
#else
     AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R13_Turkish_14x14_4_14P.bdf),
        MCT_SMALL_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R08_Turkish_20x20_4_20p.bdf),    
        MCT_MEDIUM_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R08_Turkish_22x22_4_22p.bdf),   
        MCT_LARGE_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R08_Turkish_9x9_4_9P.bdf),
        MCT_SUBLCD_FONT, 0, 0);


/*
     AddFont(
         ("English"), ("*#0044#"), ("en-US"), 
         FONT_DATA_FILE_PATH(Latin\\myarial.bdf),
        MCT_SMALL_FONT | MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_SUBLCD_FONT, 0, 0);
        */
#endif /*__MMI_FONT_RESOURCE_SLIM__*/
#else
#ifdef __MMI_FONT_RESOURCE_SLIM__
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R16_Vietnamese_14x14_4.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R16_Vietnamese_20x20_4.bdf),
        MCT_MEDIUM_FONT | MCT_LARGE_FONT, 0, 0);
#else
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R16_Vietnamese_14x14_4.bdf),
        MCT_SMALL_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R16_Vietnamese_20x20_4.bdf),
        MCT_MEDIUM_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R16_Vietnamese_22x22_4.bdf),
        MCT_LARGE_FONT, 0, 0);
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Latin\\R16_Vietnamese_9x9_4.bdf),
        MCT_SUBLCD_FONT, 0, 0);     
#endif /*__MMI_FONT_RESOURCE_SLIM__*/
#endif
#endif
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("English"), ("*#0044#"), ("en-US"), 
        FONT_DATA_FILE_PATH(VK\\vk_latin_14.bdf),
        MCT_VIRTUAL_KEYBOARD_FONT, 0, 0);
#endif



/* No such bdf file now. */
#if defined(__MMI_LANG_HK_CHINESE__)            
    AddFont(
       ("HKChinese"), ("*#0852#"), ("zh-HK"), 
       FONT_DATA_FILE_PATH(HKChinese\\uHBM13X14.bdf),
       MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT, 
       1, 0);
    AddFont(
       ("HKChinese"), ("*#0852#"), ("zh-HK"), 
       FONT_DATA_FILE_PATH(HKChinese\\uHBM15X16.bdf),
       MCT_MEDIUM_FONT | MCT_LARGE_FONT, 
       1, 0);
    AddFont(
        ("HKChinese"), ("*#0852#"), ("zh-HK"),  
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
        0, 0);

#endif /* defined(__MMI_LANG_HK_CHINESE__) */

#if defined(__MMI_LANG_KOREAN__)
    AddFont(
        ("Korean"), ("*#0082#"), ("ko"), 
        FONT_DATA_FILE_PATH(Korean\\R02_uKH13x14A_14.bdf),
        MCT_SMALL_FONT, 
        1, 0);
    AddFont(
        ("Korean"), ("*#0082#"), ("ko"), 
        FONT_DATA_FILE_PATH(Korean\\R02_uKH15x16A_16.bdf),
        MCT_MEDIUM_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT, 
        1, 0);
    AddFont(
        ("Korean"), ("*#0082#"), ("ko"), 
        FONT_DATA_FILE_PATH(Korean\\R02_uKH24x24_24.bdf),
        MCT_LARGE_FONT, 
        1, 0);
    AddFont(
        ("Korean"), ("*#0082#"), ("ko"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
        0, 0);
       
#endif


//#include "L_1_DiallingFont.h"  ???

/* No such bdf file now */
/* Thai language */
#if defined(__MMI_LANG_THAI__)
#if defined (__MMI_GUOBI_BDF_FONT__)
    AddFont(
        ("Thai"), ("*#0066#"), ("th-TH"), 
        FONT_DATA_FILE_PATH(Guobi\\Thai\\Th_20.bdf),
        MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_SUBLCD_FONT |  MCT_DIALER_FONT, 
        0, 0);
    AddFont(
        ("Thai"), ("*#0066#"), ("th-TH"), 
        FONT_DATA_FILE_PATH(Guobi\\Thai\\Th_14.bdf),
        MCT_SMALL_FONT, 
        0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("Thai"), ("*#0066#"), ("th-TH"),       
        FONT_DATA_FILE_PATH(VK\\Thai.bdf),
        MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 0);
#endif

#else
    AddFont(
        ("Thai"), ("*#0066#"), ("th-TH"), 
        FONT_DATA_FILE_PATH(Thai\\Thai17.bdf),
        MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_SUBLCD_FONT |  MCT_DIALER_FONT, 
        0, 0);
    AddFont(
        ("Thai"), ("*#0066#"), ("th-TH"), 
        FONT_DATA_FILE_PATH(Thai\\Thai_14Prop.bdf),
        MCT_SMALL_FONT, 
        0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("Thai"), ("*#0066#"), ("th-TH"),       
        FONT_DATA_FILE_PATH(VK\\Thai.bdf),
        MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 0);
#endif

#endif
#endif

#if defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_BULGARIAN__) || defined(__MMI_LANG_UKRAINIAN__)|| defined(__MMI_LANG_KAZAKH__) || defined(__MMI_LANG_MACEDONIAN__) || defined(__MMI_LANG_SERBIAN__)
#if defined (__MMI_GUOBI_BDF_FONT__)
    AddFont(
        ("Russian"), ("*#0007#"), ("ru-RU"), 
        FONT_DATA_FILE_PATH(Guobi\\Cyrillic\\Cyrillic_12.bdf),
        MCT_SMALL_FONT, 
         0, 0);
    AddFont(
        ("Russian"), ("*#0007#"), ("ru-RU"), 
        FONT_DATA_FILE_PATH(Guobi\\Cyrillic\\Cyrillic_20.bdf),
        MCT_MEDIUM_FONT | MCT_ALPHA_DIALER_FONT, 
        0, 0);
    AddFont(
        ("Russian"), ("*#0007#"), ("ru-RU"), 
        FONT_DATA_FILE_PATH(Guobi\\Cyrillic\\Cyrillic_22.bdf),
        MCT_LARGE_FONT, 
        0, 0);
    AddFont(
        ("Russian"), ("*#0007#"), ("ru-RU"), 
        FONT_DATA_FILE_PATH(Guobi\\Cyrillic\\Cyrillic_12.bdf),
        MCT_SUBLCD_FONT, 
        0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("Russian"), ("*#0007#"), ("ru-RU"), 
        FONT_DATA_FILE_PATH(VK\\vk_cyrillic14.bdf),
        MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 0);
#endif

#else
    AddFont(
        ("Russian"), ("*#0007#"), ("ru-RU"), 
        FONT_DATA_FILE_PATH(RUSSIAN\\R12_Russian_14x14_4_14P.bdf),
        MCT_SMALL_FONT, 
         0, 0);
    AddFont(
        ("Russian"), ("*#0007#"), ("ru-RU"), 
        FONT_DATA_FILE_PATH(RUSSIAN\\R12_Russian_20x20_4_20P.bdf),
        MCT_MEDIUM_FONT | MCT_ALPHA_DIALER_FONT, 
        0, 0);
    AddFont(
        ("Russian"), ("*#0007#"), ("ru-RU"), 
        FONT_DATA_FILE_PATH(RUSSIAN\\R12_Russian_22x22_4_22P.bdf),
        MCT_LARGE_FONT, 
        0, 0);
    AddFont(
        ("Russian"), ("*#0007#"), ("ru-RU"), 
        FONT_DATA_FILE_PATH(RUSSIAN\\R12_Russian_9x9_4_9P.bdf),
        MCT_SUBLCD_FONT, 
        0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("Russian"), ("*#0007#"), ("ru-RU"), 
        FONT_DATA_FILE_PATH(VK\\vk_cyrillic14.bdf),
        MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 0);
#endif

#endif
#endif

/* No such bdf file now */
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)     
    AddFont(
        ("Farsi"), ("*#0098#"), ("ps-IR"),       
        FONT_DATA_FILE_PATH(Farsi\\Farsi14.bdf),
        MCT_SMALL_FONT|MCT_SUBLCD_FONT|MCT_DIALER_FONT, 
        0, 0);
    AddFont(
        ("Farsi"), ("*#0098#"), ("ps-IR"),       
        FONT_DATA_FILE_PATH(Farsi\\Farsi20.bdf),
        MCT_MEDIUM_FONT|MCT_LARGE_FONT, 
        0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
     AddFont(
        ("Farsi"), ("*#0098#"), ("ps-IR"),       
        FONT_DATA_FILE_PATH(VK\\VK_Arabic_14.bdf),
        MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 0);
#endif

    
#elif defined(__MMI_LANG_ARABIC__)
    AddFont(
        ("Arabic"), ("*#0966#"), ("ar-SA"),       
        FONT_DATA_FILE_PATH(Arabic\\Arabic14.bdf),
        MCT_SMALL_FONT|MCT_SUBLCD_FONT|MCT_DIALER_FONT, 
        0, 0);
    AddFont(
        ("Arabic"), ("*#0966#"), ("ar-SA"),       
        FONT_DATA_FILE_PATH(Arabic\\Arabic20.bdf),
        MCT_MEDIUM_FONT|MCT_LARGE_FONT, 
        0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("Arabic"), ("*#0966#"), ("ar-SA"), 
        FONT_DATA_FILE_PATH(VK\\VK_Arabic_14.bdf),
        MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 0);
#endif

#endif

/* Hindi language */
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
    AddFont(
        ("Hindi"), ("*#0091#"), ("hi-IN"), 
        FONT_DATA_FILE_PATH(Hindi\\Hindi_14_v26.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT, 
         0, 1);
#ifdef __MMI_FONT_RESOURCE_SLIM__
    AddFont(
        ("Hindi"), ("*#0091#"), ("hi-IN"), 
        FONT_DATA_FILE_PATH(Hindi\\Hindi_20_v26.bdf),
        MCT_MEDIUM_FONT | MCT_LARGE_FONT, 
        0, 1);
#else
    AddFont(
        ("Hindi"), ("*#0091#"), ("hi-IN"), 
        FONT_DATA_FILE_PATH(Hindi\\Hindi_20_v26.bdf),
        MCT_MEDIUM_FONT, 
         0, 1);
    AddFont(
        ("Hindi"), ("*#0091#"), ("hi-IN"), 
        FONT_DATA_FILE_PATH(Hindi\\Hindi_22_v26.bdf),
        MCT_LARGE_FONT, 
         0, 1);
#endif /*__MMI_FONT_RESOURCE_SLIM__*/
    AddFont(
        ("Hindi"), ("*#0091#"), ("hi-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
         0, 0);    
#endif

#if defined(__MMI_LANG_KHMER__)  
    AddFont(
        ("Khmer"), ("*#0855#"), ("km-IN"), 
        FONT_DATA_FILE_PATH(Sea\\Khmer18x18_v01.bdf),
        MCT_SMALL_FONT |MCT_MEDIUM_FONT|MCT_LARGE_FONT|MCT_SUBLCD_FONT|MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 0);
    AddFont(
        ("Khmer"), ("*#0855#"), ("km-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
        0, 0);    
#endif

#if defined(__MMI_LANG_MYANMAR__)   
    AddFont(
        ("Myanmar"), ("*#0095#"), ("my-IN"), 
        FONT_DATA_FILE_PATH(Sea\\Myanmar18x18_v02.bdf),
        MCT_SMALL_FONT |MCT_MEDIUM_FONT|MCT_LARGE_FONT|MCT_SUBLCD_FONT|MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 0);
    AddFont(
        ("Myanmar"), ("*#0095#"), ("my-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
        0, 0);  

#endif

#if defined(__MMI_LANG_ZAWGYI_MYANMAR__)   
    AddFont(
        ("Zawgyi"), ("*#1095#"), ("my-Za"), 
        FONT_DATA_FILE_PATH(Sea\\MyanmarZawgyi_18x18p_v01.bdf),
        MCT_SMALL_FONT |MCT_MEDIUM_FONT|MCT_LARGE_FONT|MCT_SUBLCD_FONT|MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 1);
    AddFont(
        ("Zawgyi"), ("*#1095#"), ("my-Za"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
        0, 0);  

#endif

#if defined(__MMI_LANG_LAO__)       
    AddFont(
        ("Lao"), ("*#0856#"), ("lo-IN"), 
        FONT_DATA_FILE_PATH(Sea\\lao18x18_v01.bdf),
        MCT_SMALL_FONT |MCT_MEDIUM_FONT|MCT_LARGE_FONT|MCT_SUBLCD_FONT|MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 0);
    AddFont(
        ("Lao"), ("*#0856#"), ("lo-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
        0, 0);  

#endif 



#if defined(__MMI_LANG_TAMIL__)
    AddFont(
        ("Tamil"), ("*#9144#"), ("ta-IN"), 
        FONT_DATA_FILE_PATH(Tamil\\Tamil_21Wx16H_v11a.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT, 
         0, 1);
    AddFont(
        ("Tamil"), ("*#9144#"), ("ta-IN"), 
        FONT_DATA_FILE_PATH(Tamil\\Tamil_26Wx20H_v11a.bdf),
        MCT_MEDIUM_FONT, 
         0, 1);
    AddFont(
        ("Tamil"), ("*#9144#"), ("ta-IN"), 
        FONT_DATA_FILE_PATH(Tamil\\Tamil_29Wx22H_v11a.bdf),
        MCT_LARGE_FONT, 
         0, 1);
    AddFont(
        ("Tamil"), ("*#9144#"), ("ta-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
         0, 0);
#endif

/* Bengali Language */
#if defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    AddFont(
        ("Bengali"), ("*#9133#"), ("be-IN"), 
        FONT_DATA_FILE_PATH(Bengali\\Bengali_14x14p_v28b3.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT, 
         0, 1);
    AddFont(
        ("Bengali"), ("*#9133#"), ("be-IN"), 
        FONT_DATA_FILE_PATH(Bengali\\Bengali_20x20p_v28b3.bdf),
        MCT_MEDIUM_FONT, 
         0, 1);
    AddFont(
        ("Bengali"), ("*#9133#"), ("be-IN"), 
        FONT_DATA_FILE_PATH(Bengali\\Bengali_22x22p_v28b3.bdf),
        MCT_LARGE_FONT, 
         0, 1);
    AddFont(
        ("Bengali"), ("*#9133#"), ("be-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
         0, 0);
#endif

/* Gujarati Language */
#if defined(__MMI_LANG_GUJARATI__)
    AddFont(
        ("Gujarati"), ("*#9127#"), ("gu-IN"), 
        FONT_DATA_FILE_PATH(Gujarati\\Gujarati_14x14p_v18.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT, 
         0, 1);
    AddFont(
        ("Gujarati"), ("*#9127#"), ("gu-IN"), 
        FONT_DATA_FILE_PATH(Gujarati\\Gujarati_20x20p_v18.bdf),
        MCT_MEDIUM_FONT, 
         0, 1);
    AddFont(
        ("Gujarati"), ("*#9127#"), ("gu-IN"), 
        FONT_DATA_FILE_PATH(Gujarati\\Gujarati_22x22p_v18.bdf),
        MCT_LARGE_FONT, 
         0, 1);
    AddFont(
        ("Gujarati"), ("*#9127#"), ("gu-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
         0, 0);    
#endif


#if defined(__MMI_LANG_PUNJABI__)
    AddFont(
        ("Punjabi"), ("*#9172#"), ("pa-IN"), 
        FONT_DATA_FILE_PATH(Punjabi\\Punjabi_14x14p_v15.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT,
         0, 1);
    AddFont(
        ("Punjabi"), ("*#9172#"), ("pa-IN"), 
        FONT_DATA_FILE_PATH(Punjabi\\Punjabi_20x20p_v15.bdf),
        MCT_MEDIUM_FONT, 
         0, 1);        
    AddFont(
        ("Punjabi"), ("*#9172#"), ("pa-IN"), 
        FONT_DATA_FILE_PATH(Punjabi\\Punjabi_22x22p_v15.bdf),
        MCT_LARGE_FONT, 
         0, 1);
    AddFont(
        ("Punjabi"), ("*#9172#"), ("pa-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT, 
         0, 0); 
#endif


#if defined(__MMI_LANG_TELUGU__)
    AddFont(
        ("Telugu"), ("*#9140#"), ("te-IN"), 
        FONT_DATA_FILE_PATH(Telugu\\Telugu_20x16_v17a.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT,
         0, 1);
    AddFont(
        ("Telugu"), ("*#9140#"), ("te-IN"), 
        FONT_DATA_FILE_PATH(Telugu\\Telugu_26x20_v17a.bdf),
        MCT_MEDIUM_FONT,
         0, 1);
    AddFont(
        ("Telugu"), ("*#9140#"), ("te-IN"), 
        FONT_DATA_FILE_PATH(Telugu\\Telugu_28x22_v17a.bdf),
        MCT_LARGE_FONT,
         0, 1);
    AddFont(
        ("Telugu"), ("*#9140#"), ("te-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT,
         0, 0);    

#endif

#if defined(__MMI_LANG_KANNADA__)           
    AddFont(
        ("Kannada"), ("*#9180#"), ("kn-IN"), 
        FONT_DATA_FILE_PATH(Kannada\\Kannada_16x14p_v12a.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT,
        0, 1);
    AddFont(
        ("Kannada"), ("*#9180#"), ("kn-IN"), 
        FONT_DATA_FILE_PATH(Kannada\\Kannada_20x20p_v12a.bdf),
        MCT_MEDIUM_FONT,
        0, 1);
    AddFont(
        ("Kannada"), ("*#9180#"), ("kn-IN"), 
        FONT_DATA_FILE_PATH(Kannada\\Kannada_22x22p_v12a.bdf),
        MCT_LARGE_FONT,
        0, 1);
    AddFont(
        ("Kannada"), ("*#9180#"), ("kn-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT,
        0, 0);    

#endif

#if defined(__MMI_LANG_MALAYALAM__)
    AddFont(
        ("Malayalam"), ("*#9171#"), ("ml-IN"), 
        FONT_DATA_FILE_PATH(Malayalam\\Malayalam18x14_v02.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT,
        0, 1);
    AddFont(
        ("Malayalam"), ("*#9171#"), ("ml-IN"), 
        FONT_DATA_FILE_PATH(Malayalam\\Malayalam20x20_v02.bdf),
        MCT_MEDIUM_FONT,
        0, 1);
    AddFont(
        ("Malayalam"), ("*#9171#"), ("ml-IN"), 
        FONT_DATA_FILE_PATH(Malayalam\\Malayalam22x22_v02.bdf),
        MCT_LARGE_FONT,
        0, 1);
    AddFont(
        ("Malayalam"), ("*#9171#"), ("ml-IN"), 
        FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
        MCT_DIALER_FONT,
        0, 0);    

#endif

#if defined(__MMI_LANG_ORIYA__)
AddFont(
    ("Oriya"), ("*#9174#"), ("or-IN"), 
    FONT_DATA_FILE_PATH(Oriya\\Oriya_24x16p_v03.bdf),
    MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_VIRTUAL_KEYBOARD_FONT,
    0, 1);
AddFont(
    ("Oriya"), ("*#9174#"), ("or-IN"), 
    FONT_DATA_FILE_PATH(Oriya\\Oriya_32x20p_v03.bdf),
    MCT_MEDIUM_FONT,
    0, 1);
AddFont(
    ("Oriya"), ("*#9174#"), ("or-IN"), 
    FONT_DATA_FILE_PATH(Oriya\\Oriya_32x22p_v03.bdf),
    MCT_LARGE_FONT,
    0, 1);
AddFont(
    ("Oriya"), ("*#9174#"), ("or-IN"), 
    FONT_DATA_FILE_PATH(Dialing\\L_MTK_DiallingFont_27.bdf),
    MCT_DIALER_FONT,
    0, 0);    
#endif

/* No such bdf file now */
#if defined(__MMI_LANG_GREEK__)              
#if defined (__MMI_GUOBI_BDF_FONT__)
AddFont(
    ("Greek"), ("*#0030#"), ("el-GR"), 
    FONT_DATA_FILE_PATH(Guobi\\Greek\\Grc_16.bdf),
    MCT_SMALL_FONT | MCT_DIALER_FONT ,
    0, 0);
AddFont(
    ("Greek"), ("*#0030#"), ("el-GR"), 
    FONT_DATA_FILE_PATH(Guobi\\Greek\\Grc_20.bdf),
    MCT_MEDIUM_FONT,
    0, 0);
AddFont(
    ("Greek"), ("*#0030#"), ("el-GR"), 
    FONT_DATA_FILE_PATH(Guobi\\Greek\\Grc_20.bdf),
    MCT_LARGE_FONT,
    0, 0);
AddFont(
    ("Greek"), ("*#0030#"), ("el-GR"), 
    FONT_DATA_FILE_PATH(Guobi\\Greek\\Grc_16.bdf),
    MCT_SUBLCD_FONT,
    0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
AddFont(
    ("Greek"), ("*#0030#"), ("el-GR"), 
    FONT_DATA_FILE_PATH(VK\\Greek.bdf),
    MCT_VIRTUAL_KEYBOARD_FONT,
    0, 0);
#endif
     
#else
AddFont(
    ("Greek"), ("*#0030#"), ("el-GR"), 
    FONT_DATA_FILE_PATH(Greek\\uG0H14x14_4p.bdf),
    MCT_SMALL_FONT | MCT_DIALER_FONT ,
    0, 0);
AddFont(
    ("Greek"), ("*#0030#"), ("el-GR"), 
    FONT_DATA_FILE_PATH(Greek\\uG0H20x20_4p.bdf),
    MCT_MEDIUM_FONT,
    0, 0);
AddFont(
    ("Greek"), ("*#0030#"), ("el-GR"), 
    FONT_DATA_FILE_PATH(Greek\\uG0H22x22_4p.bdf),
    MCT_LARGE_FONT,
    0, 0);
AddFont(
    ("Greek"), ("*#0030#"), ("el-GR"), 
    FONT_DATA_FILE_PATH(Greek\\uG0H9x9_4p.bdf),
    MCT_SUBLCD_FONT,
    0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
AddFont(
    ("Greek"), ("*#0030#"), ("el-GR"), 
    FONT_DATA_FILE_PATH(VK\\Greek.bdf),
    MCT_VIRTUAL_KEYBOARD_FONT,
    0, 0);
#endif
    

#endif
#endif

/* No sure font size */
#if defined(__MMI_LANG_HEBREW__)
    
    AddFont(
        ("Hebrew"), ("*#0972#"), ("he-IL"), 
        FONT_DATA_FILE_PATH(Hebrew\\Hebrew_uH14x14_4.bdf),
        MCT_SMALL_FONT,
        0, 0);
    AddFont(
        ("Hebrew"), ("*#0972#"), ("he-IL"), 
        FONT_DATA_FILE_PATH(Hebrew\\Hebrew_uH20x20_4.bdf),
        MCT_MEDIUM_FONT,
        0, 0);
    AddFont(
        ("Hebrew"), ("*#0972#"), ("he-IL"), 
        FONT_DATA_FILE_PATH(Hebrew\\Hebrew_uH22x22_4.bdf),
        MCT_LARGE_FONT,
        0, 0);  
    AddFont(
        ("Hebrew"), ("*#0972#"), ("he-IL"), 
        FONT_DATA_FILE_PATH(Hebrew\\Hebrew_uH9x9_4.bdf),
        MCT_SUBLCD_FONT,
        0, 0);
    AddFont(
        ("Telugu"), ("*#9140#"), ("te-IN"), 
        FONT_DATA_FILE_PATH(Hebrew\\Hebrew_uH14x14_4.bdf),
        MCT_DIALER_FONT,
        0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("Hebrew"), ("*#0972#"), ("he-IL"), 
        FONT_DATA_FILE_PATH(VK\\Hebrew.bdf),
        MCT_VIRTUAL_KEYBOARD_FONT,
        0, 0);
#endif

        
#endif
          
#if defined(__MMI_LANG_ARMENIAN__)
    AddFont(
       ("ARMENIAN"), ("*#0374#"), ("hy-AM"), 
       FONT_DATA_FILE_PATH(Armenian\\Armenian_H14x14_4p.bdf),
       MCT_SMALL_FONT,
       0, 0);
   AddFont(
       ("ARMENIAN"), ("*#0374#"), ("hy-AM"), 
       FONT_DATA_FILE_PATH(Armenian\\Armenian_H20x20_4p.bdf),
       MCT_MEDIUM_FONT,
       0, 0);
   AddFont(
       ("ARMENIAN"), ("*#0374#"), ("hy-AM"),  
       FONT_DATA_FILE_PATH(Armenian\\Armenian_H22x22_4p.bdf),
       MCT_LARGE_FONT,
       0, 0);  
   AddFont(
       ("ARMENIAN"), ("*#0374#"), ("hy-AM"),  
       FONT_DATA_FILE_PATH(Armenian\\Armenian_H9x9_4p.bdf),
       MCT_SUBLCD_FONT | MCT_DIALER_FONT,
       0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
   AddFont(
       ("ARMENIAN"), ("*#0374#"), ("hy-AM"),  
       FONT_DATA_FILE_PATH(VK\\Armenian_vk.bdf),
       MCT_VIRTUAL_KEYBOARD_FONT,
       0, 0);
#endif

#endif

/* No such bdf file now */
#if defined(__MMI_LANG_GEORGIAN__)   
#if defined (__MMI_GUOBI_BDF_FONT__)
    AddFont(
        ("Georgian"), ("*#0995#"), ("ka-GE"), 
        FONT_DATA_FILE_PATH(Guobi\\Georgian\\Georgian_16.bdf),
        MCT_SMALL_FONT ,
        0, 0);
    AddFont(
        ("Georgian"), ("*#0995#"), ("ka-GE"), 
        FONT_DATA_FILE_PATH(Guobi\\Georgian\\Georgian_20.bdf),
        MCT_MEDIUM_FONT,
        0, 0);
    AddFont(
        ("Georgian"), ("*#0995#"), ("ka-GE"), 
        FONT_DATA_FILE_PATH(Guobi\\Georgian\\Georgian_20.bdf),
        MCT_LARGE_FONT,
        0, 0);
    AddFont(
        ("Georgian"), ("*#0995#"), ("ka-GE"), 
        FONT_DATA_FILE_PATH(Guobi\\Georgian\\Georgian_16.bdf),
        MCT_SUBLCD_FONT | MCT_DIALER_FONT,
        0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("Georgian"), ("*#0995#"), ("ka-GE"),
        FONT_DATA_FILE_PATH(VK\\Georgia_vk.bdf),
        MCT_VIRTUAL_KEYBOARD_FONT,
        0, 0);
#endif
    

#else
    AddFont(
        ("Georgian"), ("*#0995#"), ("ka-GE"), 
        FONT_DATA_FILE_PATH(Georgia\\Georgia_H14x14_4p.bdf),
        MCT_SMALL_FONT ,
        0, 0);
    AddFont(
        ("Georgian"), ("*#0995#"), ("ka-GE"), 
        FONT_DATA_FILE_PATH(Georgia\\Georgia_H20x20_4p.bdf),
        MCT_MEDIUM_FONT,
        0, 0);
    AddFont(
        ("Georgian"), ("*#0995#"), ("ka-GE"), 
        FONT_DATA_FILE_PATH(Georgia\\Georgia_H22x22_4p.bdf),
        MCT_LARGE_FONT,
        0, 0);
    AddFont(
        ("Georgian"), ("*#0995#"), ("ka-GE"), 
        FONT_DATA_FILE_PATH(Georgia\\Georgia_H9x9_4p.bdf),
        MCT_SUBLCD_FONT | MCT_DIALER_FONT,
        0, 0);

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("Georgian"), ("*#0995#"), ("ka-GE"),
        FONT_DATA_FILE_PATH(VK\\Georgia_vk.bdf),
        MCT_VIRTUAL_KEYBOARD_FONT,
        0, 0);
#endif
    

#endif
#endif

/* Chinese  */

#if defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__)

#if defined(__MMI_CHAR_SET_GB18030__) || ( defined(__MMI_CHAR_SET_GB2312__) && defined(__MMI_CHAR_SET_BIG5__) ) 
#if defined(__MMI_CHINESE_WITH_SMALL_FONT__)
    AddFont(
        ("Chinese"), ("*#0086#"), ("zh-CN"), 
        FONT_DATA_FILE_PATH(Chinese\\UNI_GB80.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT, 
        1, 0);
    AddFont(
        ("Chinese"), ("*#0886#"), ("zh-TW"), 
        FONT_DATA_FILE_PATH(Chinese\\UNI_GB80.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT, 
        1, 0);
    AddFont(
        ("Chinesec"), ("*#0086#"), ("zh-CN"), 
        FONT_DATA_FILE_PATH(Chinese\\GB18030_1920.bdf),
        MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_DIALER_FONT, 
        1, 0);
    AddFont(
        ("Chineset"), ("*#0886#"), ("zh-TW"), 
        FONT_DATA_FILE_PATH(Chinese\\GB18030_1920.bdf),
        MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_DIALER_FONT, 
        1, 0);
#else
    AddFont(
        ("Chinesec"), ("*#0086#"), ("zh-CN"), 
        FONT_DATA_FILE_PATH(Chinese\\GB18030_1920.bdf), 
        MCT_SMALL_FONT | MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_SUBLCD_FONT |MCT_DIALER_FONT, 
        1, 0);
    AddFont(
        ("Chineset"), ("*#0886#"), ("zh-TW"), 
        FONT_DATA_FILE_PATH(Chinese\\GB18030_1920.bdf ), 
        MCT_SMALL_FONT | MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_SUBLCD_FONT |MCT_DIALER_FONT, 
        1, 0);
#endif    

#elif defined(__MMI_CHAR_SET_GB2312__) && !defined(__MMI_CHAR_SET_BIG5__)
#if defined(__MMI_CHINESE_WITH_SMALL_FONT__)
    AddFont(
        ("Chinesec"), ("*#0086#"), ("zh-CN"), 
        FONT_DATA_FILE_PATH(Chinese\\GB1112.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT, 
        1, 0);
    AddFont(
        ("Chinesec"), ("*#0086#"), ("zh-CN"), 
        FONT_DATA_FILE_PATH(Chinese\\GB2312_1920.bdf),
        MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_DIALER_FONT, 
        1, 0);
#else
    AddFont(
        ("Chinesec"), ("*#0086#"), ("zh-CN"), 
        FONT_DATA_FILE_PATH(Chinese\\GB2312_1920.bdf),
        MCT_SMALL_FONT | MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_SUBLCD_FONT |MCT_DIALER_FONT , 
        1, 0);
#endif

#elif !defined(__MMI_CHAR_SET_GB2312__) && defined(__MMI_CHAR_SET_BIG5__) 
#if defined(__MMI_CHINESE_WITH_SMALL_FONT__)
    AddFont(
        ("Chineset"), ("*#0886#"), ("zh-TW"),       
        FONT_DATA_FILE_PATH(Chinese\\UNI_B5.bdf),
        MCT_SMALL_FONT | MCT_SUBLCD_FONT, 
        1, 0);
    AddFont(
        ("Chineset"), ("*#0886#"), ("zh-TW"),       
        FONT_DATA_FILE_PATH(Chinese\\TM20.bdf),
        MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_DIALER_FONT, 
        1, 0);
#else
    AddFont(
        ("Chineset"), ("*#0886#"), ("zh-TW"),       
        FONT_DATA_FILE_PATH(Chinese\\TM20.bdf),
        MCT_SMALL_FONT | MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_SUBLCD_FONT |MCT_DIALER_FONT, 
        1, 0);
#endif
#endif

#if defined(__MMI_LANG_SM_CHINESE__) 

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("Chinesec"), ("*#0086#"), ("zh-CN"),    
        FONT_DATA_FILE_PATH(VK\\L_MTK_VK_9x9.bdf),   
        MCT_VIRTUAL_KEYBOARD_FONT,
        0, 0);
#endif

#endif

#if defined(__MMI_LANG_TR_CHINESE__) 

#ifdef __MMI_VIRTUAL_KEYBOARD__
    AddFont(
        ("Chineset"), ("*#0886#"), ("zh-TW"), 
        FONT_DATA_FILE_PATH(VK\\L_MTK_VK_9x9.bdf),   
        MCT_VIRTUAL_KEYBOARD_FONT, 
        0, 0);
#endif

#endif

#endif  /* defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) */

#else   /* Vector Font */

    AddFont(
       ("English"), ("*#0044#"), ("en-US"), 
       FONT_DATA_FILE_PATH(Latin\\L_MTK_En_Large_22.bdf),
       MCT_SMALL_FONT | MCT_SUBLCD_FONT | MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_DIALER_FONT | MCT_NUMBER1_FONT | MCT_NUMBER2_FONT | MCT_VIRTUAL_KEYBOARD_FONT | MCT_TOUCH_SCREEN_LARGE, 0, 0);

#endif


#if defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__)
    
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)

    AddFont(
      "gMTKProprietaryFont", NULL, NULL, 
      FONT_DATA_FILE_PATH(MTK_Proprietary\\MTKProprietaryFont20.bdf),
      MCT_MEDIUM_FONT | MCT_LARGE_FONT | MCT_DIALER_FONT | MCT_NUMBER1_FONT | MCT_NUMBER2_FONT | MCT_TOUCH_SCREEN_LARGE | MCT_VIRTUAL_KEYBOARD_FONT,
      0, 0);

    AddFont(
     "gMTKProprietaryFont", NULL, NULL, 
     FONT_DATA_FILE_PATH(MTK_Proprietary\\MTKProprietaryFont14.bdf),
     MCT_SMALL_FONT | MCT_SUBLCD_FONT,
     0, 0);


#if defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))

#if defined(__MMI_ZI_V7__)

    /* bug */

#else /* defined(__MMI_ZI_V7__) */ 

    //#error Only Zi V7 is supported.

#endif /* defined(__MMI_ZI_V7__) */ 

#endif /* defined(__MMI_ZI__) */ 

#else
    
    //#error Multiple proprietary font only apply on 320x480, 240x400, 320x240 and 240x320
    
#endif  /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) */

#else /* defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__) */

#if (defined(__MMI_MAINLCD_320X480__)) || (defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)))

    AddFont(
        "gMTKProprietaryFont", NULL, NULL, 
        FONT_DATA_FILE_PATH(MTK_Proprietary\\MTKProprietaryFont20.bdf),
        MCT_SMALL_FONT | MCT_MEDIUM_FONT | MCT_LARGE_FONT |MCT_SUBLCD_FONT| MCT_DIALER_FONT | MCT_NUMBER1_FONT | MCT_NUMBER2_FONT | MCT_TOUCH_SCREEN_LARGE | MCT_VIRTUAL_KEYBOARD_FONT,
        0, 0);

#if defined(__MMI_ZI_V7__)
    /* bug */
#else /* defined(__MMI_ZI_V7__) */ 
    /* bug */
#endif

#else   /* defined(__MMI_MAINLCD_320X480__) */

    AddFont(
        "gMTKProprietaryFont", NULL, NULL, 
        FONT_DATA_FILE_PATH(MTK_Proprietary\\MTKProprietaryFont14.bdf),
        MCT_SMALL_FONT | MCT_MEDIUM_FONT | MCT_LARGE_FONT |MCT_SUBLCD_FONT| MCT_DIALER_FONT | MCT_NUMBER1_FONT | MCT_NUMBER2_FONT | MCT_TOUCH_SCREEN_LARGE | MCT_VIRTUAL_KEYBOARD_FONT,
        0, 0);

#if defined(__MMI_ZI_V7__)
    /* bug */
#else /* defined(__MMI_ZI_V7__) */ 
    /* bug */
#endif /* defined(__MMI_ZI_V7__) */

#endif /* defined(__MMI_MAINLCD_320X480__) */

#endif

    GenerateFontResFile();

    DeinitialFontEngine();

	return 0;
}
   // AddFont(&string("aa"), &string("bb"), &string("en-US"), MCT_ALPHA_SMALL_FONT, 0, 0, &bdf_path, 1);
	//AddFont(&string("aa"), &string("bb"), &string("en-US"), MCT_ALPHA_SMALL_FONT, 0, 0, &bdf_path, 1);
