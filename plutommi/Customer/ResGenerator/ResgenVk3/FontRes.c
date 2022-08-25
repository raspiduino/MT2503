#include "FontRes.h"
#include "MMI_features.h"

#ifndef NULL
#define NULL  (void *)0           /*  NULL    :   Null pointer */
#endif

#define  MAX_LANGUAGES     30

#include "L_English_small.h"
#include "L_gMTKProprietaryFont_small.h"
#include "L_gMTKProprietaryFont_medium.h"

const sCustFontData *g_small_font_data_array[] = {
&English_small,
&gMTKProprietaryFont_small
}; 

const sCustFontData *g_medium_font_data_array[] = {
&English_small,
&gMTKProprietaryFont_medium
}; 

const sCustFontData *g_large_font_data_array[] = {
&English_small,
&gMTKProprietaryFont_medium
}; 

const sCustFontData *g_sublcd_font_data_array[] = {
&English_small,
&gMTKProprietaryFont_small
}; 

const sCustFontData *g_dialling_font_data_array[] = {
&English_small,
&gMTKProprietaryFont_medium
}; 

const sCustFontData *g_number1_font_data_array[] = {
&English_small,
&gMTKProprietaryFont_medium
}; 

const sCustFontData *g_number2_font_data_array[] = {
&English_small,
&gMTKProprietaryFont_medium
}; 

const sCustFontData *g_touchscreen_font_data_array[] = {
&English_small,
&gMTKProprietaryFont_medium
}; 

const sCustFontData *g_touchscreen_large_font_data_array[] = {
&English_small,
&gMTKProprietaryFont_medium
}; 

const font_group_struct g_fontfamily[MAX_FONT_SIZE] = {
{2, g_small_font_data_array},
{2, g_medium_font_data_array},
{2, g_large_font_data_array},
{2, g_sublcd_font_data_array},
{2, g_dialling_font_data_array},
{2, g_number1_font_data_array},
{2, g_number2_font_data_array},
{2, g_touchscreen_font_data_array},
{2, g_touchscreen_large_font_data_array},
};
const U8 g_fontfamily_count = 9 ;

const U16 mtk_gMaxDeployedLangs = 0 

#if defined(__MMI_LANG_ENGLISH__)
+ 1      
#endif

#if defined(__MMI_LANG_POLISH__)
+ 1      
#endif

#if defined(__MMI_LANG_FRENCH__)
+ 1      
#endif

#if defined(__MMI_LANG_GERMAN__)
+ 1      
#endif

#if defined(__MMI_LANG_ITALIAN__)
+ 1      
#endif

#if defined(__MMI_LANG_ARABIC__)
+ 1
#endif

#if defined(__MMI_LANG_PERSIAN__)
+ 1
#endif
#if defined(__MMI_LANG_URDU__)
+ 1
#endif
#if defined(__MMI_LANG_SPANISH__)
+ 1      
#endif

#if defined(__MMI_LANG_DANISH__)
+ 1      
#endif

#if defined(__MMI_LANG_HEBREW__)
+ 1
#endif

#if defined(__MMI_LANG_PORTUGUESE__)
+ 1      
#endif

#if defined(__MMI_LANG_ALBANIAN__)
+ 1      
#endif

#if defined(__MMI_LANG_AZERBAIJANI__)
+ 1  
#endif

#if defined(__MMI_LANG_CATALAN__)
+ 1  
#endif

#if defined(__MMI_LANG_HAUSA__)
+ 1  
#endif

#if defined(__MMI_LANG_GALICIAN__)
+ 1  
#endif

#if defined(__MMI_LANG_BASQUE__)
+ 1  
#endif

#if defined(__MMI_LANG_IGBO__)
+ 1  
#endif

#if defined(__MMI_LANG_FILIPINO__)
+ 1  
#endif

#if defined(__MMI_LANG_IRISH__)
+ 1  
#endif

#if defined(__MMI_LANG_KAZAKH__)
+ 1  
#endif

#if defined(__MMI_LANG_MACEDONIAN__)
+ 1  
#endif

#if defined(__MMI_LANG_YORUBA__)
+ 1  
#endif

#if defined(__MMI_LANG_TAGALOG__)
+ 1  
#endif

#if defined(__MMI_LANG_SESOTHO__)
+ 1  
#endif

#if defined(__MMI_LANG_HINDI__)
+ 1
#endif

#if defined(__MMI_LANG_MARATHI__)
+ 1
#endif

#if defined(__MMI_LANG_TAMIL__)
+ 1      
#endif

#if defined(__MMI_LANG_BENGALI__)
+ 1
#endif

#if defined(__MMI_LANG_ASSAMESE__)
+ 1
#endif

#if defined(__MMI_LANG_PUNJABI__)
+ 1      
#endif
#if defined(__MMI_LANG_TELUGU__)
+ 1      
#endif
#if defined(__MMI_LANG_LAO__)
+ 1      
#endif
#if defined(__MMI_LANG_KHMER__)
+ 1      
#endif
#if defined(__MMI_LANG_MYANMAR__)
+ 1      
#endif
#if defined(__MMI_LANG_KANNADA__)
+ 1      
#endif

#if defined(__MMI_LANG_MALAYALAM__)
+ 1      
#endif
#if defined(__MMI_LANG_ORIYA__)
+ 1      
#endif
#if defined(__MMI_LANG_TURKISH__)
+ 1      
#endif

#if defined(__MMI_LANG_VIETNAMESE__)
+ 1      
#endif

#if defined(__MMI_LANG_INDONESIAN__)
+ 1      
#endif

#if defined(__MMI_LANG_CZECH__)
+ 1      
#endif

#if defined(__MMI_LANG_MALAY__)
+ 1
#endif

#if defined(__MMI_LANG_RUSSIAN__)
+ 1      
#endif

#if defined(__MMI_LANG_UKRAINIAN__)
+ 1      
#endif

#if defined(__MMI_LANG_BULGARIAN__)
+ 1      
#endif

#if defined(__MMI_LANG_THAI__)
+ 1      
#endif

#if defined(__MMI_LANG_TR_CHINESE__)
+ 1   
#endif   

#if defined(__MMI_LANG_SM_CHINESE__)
+ 1
#endif

#if defined(__MMI_LANG_NORWEGIAN__)
+ 1      
#endif

#if defined(__MMI_LANG_GUJARATI__)
+ 1      
#endif
#if defined(__MMI_LANG_FINNISH__)
+ 1      
#endif

#if defined(__MMI_LANG_HUNGARIAN__)
+ 1      
#endif

#if defined(__MMI_LANG_SLOVAK__)
+ 1      
#endif

#if defined(__MMI_LANG_DUTCH__)
+ 1      
#endif

#if defined(__MMI_LANG_SWEDISH__)
+ 1      
#endif

#if defined(__MMI_LANG_CROATIAN__)
+ 1      
#endif

#if defined(__MMI_LANG_ROMANIAN__)
+ 1
#endif

#if defined(__MMI_LANG_SLOVENIAN__)
+ 1      
#endif

#if defined(__MMI_LANG_GREEK__)
+ 1      
#endif

#if defined(__MMI_LANG_XHOSA__)
+ 1  
#endif

#if defined(__MMI_LANG_SWAHILI__)
+ 1  
#endif

#if defined(__MMI_LANG_AFRIKAANS__)
+ 1  
#endif

#if defined(__MMI_LANG_ZULU__)
+ 1  
#endif

#if defined(__MMI_LANG_LITHUANIAN__)
+ 1  
#endif

#if defined(__MMI_LANG_LATVIAN__)
+ 1  
#endif

#if defined(__MMI_LANG_ESTONIAN__)
+ 1  
#endif

#if defined(__MMI_LANG_ARMENIAN__)
+ 1  
#endif
#if defined(__MMI_LANG_SA_PORTUGUESE__)
+ 1  
#endif

#if defined(__MMI_LANG_CA_FRENCH__)
+ 1  
#endif

#if defined(__MMI_LANG_SA_SPANISH__)
+ 1  
#endif

#if defined(__MMI_LANG_HK_CHINESE__)
+ 1  
#endif

#if defined(__MMI_LANG_UK_ENGLISH__)
+ 1  
#endif

#if defined(__MMI_LANG_SERBIAN__)
+ 1  
#endif

#if defined(__MMI_LANG_ICELANDIC__)
+ 1  
#endif

#if defined(__MMI_LANG_GEORGIAN__)
+ 1  
#endif

#if defined(__MMI_LANG_MOLDOVAN__)
+ 1  
#endif

#if defined(__MMI_LANG_KOREAN__)
+ 1
#endif
;



const sLanguageDetails mtk_gLanguageArray[MAX_LANGUAGES] =
{
#if defined(__MMI_LANG_ENGLISH__)
{
 {(char)0x45,(char)0x0,(char)0x6E,(char)0x0,(char)0x67,(char)0x0,(char)0x6C,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x0,(char)0x00,(char)0x00},//Language Name
  "*#0044#",//SSC string name
 "en-US"
},
#endif

#if defined(__MMI_LANG_FRENCH__)
{
{(char)0x46,(char)0x0,(char)0x72,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0,(char)0xe7,(char)0x0,(char)0x61,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x00},//Language Name
"*#0033#",
 "fr-FR"
},
#endif

#if defined(__MMI_LANG_SPANISH__)
{
{(char)0x45,(char)0x0,(char)0x73,(char)0x0,(char)0x70,(char)0x0,(char)0x61,(char)0x0,(char)0xf1,(char)0x0,(char)0x6f,(char)0x0,(char)0x6c,(char)0x0,(char)0x00,(char)0x00},//Language Name
"*#0034#",
 "es-ES"
},
#endif

#if defined(__MMI_LANG_DANISH__)
{
{(char)0x44,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x0},//Language Name
"*#0045#",
 "da-DK"
},
#endif

#if defined(__MMI_LANG_POLISH__)
{
{(char)0x6A,(char)0x00 , (char)0x19,(char)0x01,  (char)0x7A,(char)0x00,  (char)0x79,(char)0x00,  (char)0x6B,(char)0x00 , (char)0x00,(char)0x20, (char)0x70,(char)0x00 , (char)0x6F,(char)0x00,  (char)0x6C,(char)0x00,  (char)0x73,(char)0x00, (char)0x6B,(char)0x00,  (char)0x69,(char)0x00 ,(char)0x00,(char)0x00},//Language Name
"*#0048#",
 "pl-PL"
},
#endif

#if defined(__MMI_LANG_PORTUGUESE__)
{
 {(char)0x50, (char)0x0, (char)0x6f, (char)0x0, (char)0x72, (char)0x0, (char)0x74, (char)0x0, (char)0x75, (char)0x0, (char)0x67, (char)0x0, (char)0x75, (char)0x0, (char)0xea, (char)0x0, (char)0x73, (char)0x0, (char)0x00, (char)0x0},//Language Name
  "*#0351#",//SSC string name
 "pt-PT"
},
#endif

#if defined(__MMI_LANG_ALBANIAN__)
{
{(char)0x41,(char)0x0,(char)0x6c,(char)0x0,(char)0x62,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0},//Language Name
  "*#0355#",//SSC string name
 "sq-SQ"
},
#endif

//English
#if defined(__MMI_LANG_UK_ENGLISH__)
{
 {(char)0x55,(char)0x0,(char)0x4B,(char)0x0,(char)0x20,(char)0x0,(char)0x45,(char)0x0,(char)0x6E,(char)0x0,(char)0x67,(char)0x0,(char)0x6C,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x0,(char)0x00,(char)0x00},//Language Name
  "*#0441#",//SSC string name
 "en-UK"
},
#endif

#if defined(__MMI_LANG_CA_FRENCH__)
{
{(char)0x43,(char)0x0,(char)0x41,(char)0x0,(char)0x20,(char)0x0,(char)0x46,(char)0x0,(char)0x72,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0,(char)0xe7,(char)0x0,(char)0x61,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x00},//Language Name
"*#0001#",
 "fr-CA"
},
#endif

#if defined(__MMI_LANG_SA_SPANISH__)
{
{(char)0x4C,(char)0x0,(char)0x41,(char)0x0,(char)0x20,(char)0x0,(char)0x45,(char)0x0,(char)0x73,(char)0x0,(char)0x70,(char)0x0,(char)0x61,(char)0x0,(char)0xf1,(char)0x0,(char)0x6f,(char)0x0,(char)0x6c,(char)0x0,(char)0x00,(char)0x00},//Language Name
"*#0054#",
 "es-SA"
},
#endif

#if defined(__MMI_LANG_SA_PORTUGUESE__)
{
 {(char)0x42,(char)0x0,(char)0x5A,(char)0x0,(char)0x20,(char)0x0,(char)0x50, (char)0x0, (char)0x6f, (char)0x0, (char)0x72, (char)0x0, (char)0x74, (char)0x0, (char)0x75, (char)0x0, (char)0x67, (char)0x0, (char)0x75, (char)0x0, (char)0xea, (char)0x0, (char)0x73, (char)0x0, (char)0x00, (char)0x0},//Language Name
  "*#0055#",//SSC string name
 "pt-BZ"
},
#endif

#if defined(__MMI_LANG_ICELANDIC__)
{
{(char)0xCD,(char)0x0,(char)0x73,(char)0x0,(char)0x6C,(char)0x0,(char)0x65,(char)0x0,(char)0x6E,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x0,(char)0x61,(char)0x0,(char)0x00,(char)0x00},//Language Name
"*#0354#",
 "is-IS"
},
#endif

#if defined(__MMI_LANG_SERBIAN__)
{
{(char)0x41,(char)0x04,(char)0x40,(char)0x04,(char)0x3F,(char)0x04,(char)0x41,(char)0x04,(char)0x3A,(char)0x04,(char)0x38,(char)0x04,(char)0x00,(char)0x00},//Language Name
"*#0381#",
 "sr-SR"
},
#endif


#if defined (__MMI_LANG_KOREAN__)
{
{ (char)0x5C, (char)0xD5, (char)0x6D, (char)0xAD, (char)0xB4, (char)0xC5, (char)0x00, (char)0x00 },
"*#0082#",
"ko" 
},  
#endif

#if defined(__MMI_LANG_AZERBAIJANI__)
{
{(char)0x41, (char)0x00, (char)0x7A, (char)0x00, (char)0x59, (char)0x02, (char)0x72,  (char)0x00, (char)0x62, (char)0x00, (char)0x61,  (char)0x00,  (char)0x79, (char)0x00,  (char)0x63, (char)0x00,  (char)0x61, (char)0x00,  (char)0x6E, (char)0x00,  (char)0x64, (char)0x00,  (char)0x69, (char)0x00,  (char)0x6C, (char)0x00,  (char)0x69, (char)0x00, (char)0x00,(char)0x00},//Language Name
"*#0994#",
 "az-AZ"
},
#endif

#if defined(__MMI_LANG_CATALAN__)
{
{(char)0x63 ,(char)0x0  ,(char)0x61 ,(char)0x0  ,(char)0x74 ,(char)0x0  ,(char)0x61 ,(char)0x0  ,(char)0x6C ,(char)0x0  ,(char)0xE0,(char)0x0,(char)0x00,(char)0x00 },//Language Name
"*#0376#",
 "ca-CA"
},
#endif

#if defined(__MMI_LANG_HAUSA__)
{
{(char)0x48 ,(char)0x0  ,(char)0x61 ,(char)0x0  ,(char)0x75 ,(char)0x0  ,(char)0x73 ,(char)0x0  ,(char)0x61 ,(char)0x0,(char)0x00,(char)0x00},//Language Name
"*#2342#",
 "ha-HA"
},
#endif


#if defined(__MMI_LANG_KAZAKH__)
{
{(char)0x9A ,(char)0x04 ,(char)0x30 ,(char)0x04 ,(char)0x37 ,(char)0x04 ,(char)0x30 ,(char)0x04 ,(char)0x9B ,(char)0x04 ,(char)0x20 ,(char)0x0,(char)0x42 ,(char)0x04 ,(char)0x56 ,(char)0x04 ,(char)0x3B ,(char)0x04 ,(char)0x56 ,(char)0x04,(char)0x00,(char)0x00},//Language Name
"*#0007#",

 "kk-KK"
},
#endif

#if defined(__MMI_LANG_GALICIAN__)
{
{(char)0x47,(char)0x00,(char)0x61,(char)0x00,(char)0x6C,(char)0x00,(char)0x65,(char)0x00,(char)0x67,(char)0x00,(char)0x6F,(char)0x00,(char)0x00,(char)0x00},//Language Name
"*#3498#",

  "gl-ES",
 },
#endif

#if defined(__MMI_LANG_BASQUE__)
{
{(char)0x45,(char)0x00,(char)0x75,(char)0x00,(char)0x73,(char)0x00,(char)0x6B,(char)0x00,(char)0x61,(char)0x00,(char)0x72,(char)0x00,(char)0x61,(char)0x00,(char)0x00,(char)0x00},//Language Name
"*#3495#",

    "eu-ES",
},
#endif

#if defined(__MMI_LANG_IGBO__)
{
{(char)0x41,(char)0x00,(char)0x73,(char)0x00,(char)0x1EE5,(char)0x00,(char)0x73,(char)0x00,(char)0x1EE5,(char)0x00,(char)0x20,(char)0x00,(char)0x49,(char)0x00,(char)0x67,(char)0x00,(char)0x62,(char)0x00,(char)0x6F,(char)0x00,(char)0x00,(char)0x00},//Language Name
 "*#2343#",

   "ig-NG",
},
#endif

#if defined(__MMI_LANG_FILIPINO__)
{
{(char)0x46,(char)0x00,(char)0x69,(char)0x00,(char)0x6C,(char)0x00,(char)0x69,(char)0x00,(char)0x70,(char)0x00,(char)0x69,(char)0x00,(char)0x6E,(char)0x00,(char)0x6F ,(char)0x00,(char)0x00},//Language Name
"*#0063#",
"fil-PH",
},
#endif

#if defined(__MMI_LANG_IRISH__)
{
{(char)0x47,(char)0x00,(char)0x61,(char)0x00,(char)0x65,(char)0x00,(char)0x69,(char)0x00,(char)0x6C,(char)0x00,(char)0x67 ,(char)0x00,(char)0x65,(char)0x00,(char)0x00},//Language Name
"*#0353#",
"ga-IE",
},
#endif



#if defined(__MMI_LANG_MACEDONIAN__)
{
{(char)0x1C ,(char)0x04 ,(char)0x30 ,(char)0x04 ,(char)0x3A ,(char)0x04 ,(char)0x35 ,(char)0x04 ,(char)0x34 ,(char)0x04 ,(char)0x3E ,(char)0x04 ,(char)0x3D ,(char)0x04 ,(char)0x41 ,(char)0x04 ,(char)0x3A ,(char)0x04 ,(char)0x38 ,(char)0x04

,(char)0x00,(char)0x00},//Language Name
"*#0389#",
 "mk-MK"
},
#endif

#if defined(__MMI_LANG_SESOTHO__)
{
{(char)0x73, (char)0x00,  (char)0x65, (char)0x00,  (char)0x53, (char)0x00, (char)0x6F, (char)0x00, (char)0x74, (char)0x00, (char)0x68, (char)0x00,  (char)0x6F, (char)0x00,(char)0x00,(char)0x00},//Language Name
"*#0266#",
 "st-ST"
},
#endif


#if defined(__MMI_LANG_TAGALOG__)
{
{(char)0x54, (char)0x00,   (char)0x61, (char)0x00,   (char)0x67, (char)0x00,   (char)0x61, (char)0x00,   (char)0x6C, (char)0x00,   (char)0x6F, (char)0x00,   (char)0x67, (char)0x00,(char)0x00,(char)0x00},//Language Name
"*#0631#",

 "tl-TL"
},
#endif

#if defined(__MMI_LANG_YORUBA__)
{
{(char)0xE8, (char)0x00,  (char)0x64, (char)0x00,  (char)0xE8, (char)0x00,  (char)0x59, (char)0x00,  (char)0x6F, (char)0x00,  (char)0x72,  (char)0x00,  (char)0xF9, (char)0x00,  (char)0x62,  (char)0x00,  (char)0xE1, (char)0x00,(char)0x00,(char)0x00},//Language Name
"*#2341#",

 "yo-YO"
},
#endif


#if defined(__MMI_LANG_ITALIAN__)
{
{(char)0x49,(char)0x0,(char)0x74,(char)0x0,(char)0x61,(char)0x0,(char)0x6c,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0,(char)0x6f,(char)0x00},//Language Name
"*#0039#",

 "it-IT"
},
#endif

#if defined(__MMI_LANG_GERMAN__)
{
{(char)0x44,(char)0x0,(char)0x65,(char)0x0,(char)0x75,(char)0x0,(char)0x74,(char)0x0,(char)0x73,(char)0x0,(char)0x63,(char)0x0,(char)0x68,(char)0x0,(char)0x00,(char)0x00},//Language Name
"*#0049#",

 "de-DE"
},
#endif

#if defined(__MMI_LANG_MALAY__)
{
{(char)0x42,(char)0x0,(char)0x61,(char)0x0,(char)0x68,(char)0x0,(char)0x61,(char)0x0,(char)0x73,(char)0x0,(char)0x61,(char)0x0,(char)0x20,(char)0x0,(char)0x4d,(char)0x00,(char)0x65,(char)0x00,(char)0x6c,(char)0x00,(char)0x61,(char)0x00,(char)0x79,(char)0x00,(char)0x75,(char)0x00},//Language Name
"*#0060#",

 "ms-MY"
},
#endif

#if defined(__MMI_LANG_INDONESIAN__)
{
{(char)0x42,(char)0x0,(char)0x61,(char)0x0,(char)0x68,(char)0x0,(char)0x61,(char)0x0,(char)0x73,(char)0x0,(char)0x61,(char)0x0,(char)0x20,(char)0x0,(char)0x49,(char)0x00,(char)0x6e,(char)0x00,(char)0x64,(char)0x00,(char)0x6f,(char)0x00,(char)0x6e,(char)0x00,(char)0x65,(char)0x00,(char)0x73,(char)0x00,(char)0x69,(char)0x00,(char)0x61,(char)0x00},//Language Name
"*#0062#",

 "id-ID"
},
#endif

#if defined(__MMI_LANG_CZECH__)
{
{(char)0x43,(char)0x0,(char)0x7A,(char)0x0,(char)0x65,(char)0x0,(char)0x63,(char)0x0,(char)0x68,(char)0x0},//Language Name
"*#0420#",

 "cs-CZ"
},
#endif

#if defined(__MMI_LANG_NORWEGIAN__)
{
{(char)0x4E,(char)0x0,(char)0x6F,(char)0x0,(char)0x72,(char)0x0,(char)0x77,(char)0x0,(char)0x65,(char)0x0,(char)0x67,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x00},//Language Name
"*#0047#",

 "nb-NO"
},
#endif
//Norwegian end

#if defined(__MMI_LANG_SLOVAK__)
{
{(char)0x53,(char)0x0,(char)0x6C,(char)0x0,(char)0x6F,(char)0x0,(char)0x76,(char)0x0,(char)0x61,(char)0x0,(char)0x6B,(char)0x00},//Language Name
"*#0421#",

 "sk-SK"
},
#endif

#if defined(__MMI_LANG_DUTCH__)
{
{(char)0x44,(char)0x0,(char)0x75,(char)0x0,(char)0x74,(char)0x0,(char)0x63,(char)0x0,(char)0x68,(char)0x00},
"*#0031#",

 "nl-NL"
},
#endif
#if defined(__MMI_LANG_FINNISH__)
{
{(char)0x46,(char)0x0,(char)0x69,(char)0x0,(char)0x6E,(char)0x0,(char)0x6E,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x00},//Language Name
"*#0358#",

 "fi-FI"
},
#endif
#if defined(__MMI_LANG_HUNGARIAN__)
{
{(char)0x48,(char)0x0,(char)0x75,(char)0x0,(char)0x6E,(char)0x0,(char)0x67,(char)0x0,(char)0x61,(char)0x0,(char)0x72,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
"*#0036#",

 "hu-HU"
},
#endif

#if defined(__MMI_LANG_VIETNAMESE__)
{
{(char)0x54,(char)0x0,(char)0x69,(char)0x0,(char)0xbf,(char)0x1e,(char)0x6e,(char)0x0,(char)0x67,(char)0x0,(char)0x20,(char)0x0,(char)0x56,(char)0x0,(char)0x69,(char)0x00,(char)0xc7,(char)0x1e,(char)0x74,(char)0x00},//Language Name
"*#0084#",

 "vi-VN"
},
#endif

#if defined(__MMI_LANG_TURKISH__)
{
{(char)0x54, (char)0x0, (char)0xfc, (char)0x0, (char)0x72, (char)0x0, (char)0x6b, (char)0x0, (char)0xe7, (char)0x0, (char)0x65, (char)0x0, (char)0x00, (char)0x0},//Language Name
"*#0090#",

 "tr-TR"
},
#endif

#if defined(__MMI_LANG_RUSSIAN__)
{
{(char)0x20,(char)0x04,(char)0x43,(char)0x04,(char)0x41,(char)0x04,(char)0x41,(char)0x04,(char)0x3a,(char)0x04,(char)0x38,(char)0x04,(char)0x39,(char)0x04,(char)0x20,(char)0x00,(char)0x4f,(char)0x04,(char)0x37,(char)0x04,(char)0x4b,(char)0x04,(char)0x3a,(char)0x04},//Language Name
"*#0007#",

 "ru-RU"
},
#endif

#if defined(__MMI_LANG_BULGARIAN__)
{
{(char)0x11,(char)0x04,(char)0x4A,(char)0x04,(char)0x3B,(char)0x04,(char)0x33,(char)0x04,(char)0x30,(char)0x04,(char)0x40,(char)0x04,(char)0x38,(char)0x04,(char)0x4F,(char)0x04},//Language Name
"*#0359#",

 "bg-BG"
},
#endif

#if defined(__MMI_LANG_UKRAINIAN__)
{
{(char)0x43,(char)0x04,  (char)0x3A,(char)0x04,  (char)0x40,(char)0x04,  (char)0x30,(char)0x04,  (char)0x57,(char)0x04,  (char)0x01,(char)0x03 , (char)0x3D,(char)0x04,  (char)0x41,(char)0x04,  (char)0x4C,(char)0x04,  (char)0x3A,(char)0x04,  (char)0x30,(char)0x04 , (char)0x00,(char)0x20, (char)0x3C,(char)0x04,  (char)0x3E,(char)0x04,  (char)0x01,(char)0x03,  (char)0x32,(char)0x04,  (char)0x30,(char)0x04 ,(char)0x00,(char)0x00},//Language Name
"*#0380#",

 "uk-UA"
},
#endif

//Arabic language
#if defined(__MMI_LANG_ARABIC__)
{
{(char)0x27,(char)0x06,(char)0xDF,(char)0xFE,(char)0xCC,(char)0xFE,(char)0xAD,(char)0xFE,(char)0x91,(char)0xFE,(char)0xF4,(char)0xFE,(char)0x94,(char)0xFE,(char)0x00,(char)0x00},
"*#0966#",

"ar-SA"
},
#endif

#if defined(__MMI_LANG_PERSIAN__)
{
{(char)0x50, (char)0x0, (char)0x65, (char)0x0, (char)0x72, (char)0x0,(char)0x73,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},
"*#0098#",

"ps-IR"
},
#endif
#if defined(__MMI_LANG_URDU__)
{
{(char)0x55, (char)0x0, (char)0x72, (char)0x0, (char)0x64, (char)0x0,(char)0x75,(char)0x0},
"*#0092#",

"ur-PK"
},
#endif
#if defined(__MMI_LANG_HEBREW__)
{
{ (char)0x48, (char)0x0, (char)0x65, (char)0x0, (char)0x62, (char)0x0, (char)0x72, (char)0x0, (char)0x65, (char)0x0, (char)0x77, (char)0x0},
"*#0972#",

"he-IL"
}, 
#endif

//Thai language
#if defined(__MMI_LANG_THAI__)
{
{(char)0x44,(char)0x0E,(char)0x17,(char)0x0E,(char)0x22,(char)0x0E,(char)0x00,(char)0x00},
"*#0066#",

"th-TH"
},
#endif

//Greek
#if defined(__MMI_LANG_GREEK__)
{
{ (char)0x47, (char)0x0, (char)0x72, (char)0x0, (char)0x65, (char)0x0, (char)0x65, (char)0x0, (char)0x6b, (char)0x0,},//Language Name
"*#0030#",

 "el-GR"
},
#endif

//Traditional Chinese
#if defined(__MMI_LANG_TR_CHINESE__)
{
{(char)0x41,(char)0x7E,(char)0xD4,(char)0x9A,(char)0x2D,(char)0x4E,(char)0x87,(char)0x65,(char)0x00,(char)0x00},//Language Name
 "*#0886#",//SSC string name

 "zh-TW"
},
#endif

#if defined(__MMI_LANG_HK_CHINESE__)
{{ (char)0xE3, (char)0x5E, (char)0x71, (char)0x67, (char)0x71, (char)0x8A, (char)0x00, (char)0x0,},
"*#0852#",

"zh-HK"
},  
#endif /* defined(__MMI_LANG_HK_CHINESE__) */

//Simplified Chinese
#if defined(__MMI_LANG_SM_CHINESE__)
{
{(char)0x80,(char)0x7B,(char)0x53,(char)0x4F,(char)0x2D,(char)0x4E,(char)0x87,(char)0x65,(char)0x00,(char)0x00},//Language Name
 "*#0086#",//SSC string name
 
 "zh-CN"
},
#endif

#if defined(__MMI_LANG_SWEDISH__)
{
{(char)0x53,(char)0x0,(char)0x77,(char)0x0,(char)0x65,(char)0x0,(char)0x64,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x00},//Language Name
"*#0046#",

 "sv-SE"
},
#endif

#if defined(__MMI_LANG_CROATIAN__)
{
{(char)0x43,(char)0x0,(char)0x72,(char)0x0,(char)0x6F,(char)0x0,(char)0x61,(char)0x0,(char)0x74,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x00},//Language Name
"*#0385#",

 "hr-HR"
},
#endif

#if defined(__MMI_LANG_ROMANIAN__)
{
{(char)0x52,(char)0x0,(char)0x6f,(char)0x0,(char)0x6d,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x00},//Language Name
"*#0040#",

 "ro-RO"
},
#endif
#if defined(__MMI_LANG_SLOVENIAN__)
{
{(char)0x53,(char)0x0,(char)0x6C,(char)0x0,(char)0x6F,(char)0x0,(char)0x76,(char)0x0,(char)0x65,(char)0x0,(char)0x6E,(char)0x00,(char)0x69,(char)0x00,(char)0x61,(char)0x00,(char)0x6E,(char)0x00},//Language Name
"*#0386#",

 "sl-SI"
},
#endif

#if defined(__MMI_LANG_HINDI__)
{
{(char)0x39, (char)0x09, (char)0x3F, (char)0x09, (char)0x28, (char)0x09, (char)0x4D, (char)0x09, (char)0x26, (char)0x09, (char)0x40, (char)0x09},
 "*#0091#",

 "hi-IN"
},
#endif


#if defined(__MMI_LANG_MARATHI__)
{
{(char)0x2E, (char)0x09, (char)0x30, (char)0x09, (char)0x3E, (char)0x09, (char)0x20, (char)0x09, (char)0x40, (char)0x09},
 "*#9122#",

 "mr-IN"
},
#endif
#if defined(__MMI_LANG_TAMIL__)
{
{ (char)0xA4, (char)0x0B, (char)0xAE, (char)0x0B, (char)0xBF, (char)0x0B, (char)0xB4, (char)0x0B, (char)0xCD, (char)0x0B,},
"*#9144#",

"ta-IN"
},
#endif

#if defined(__MMI_LANG_GUJARATI__)
{
{ (char)0x97, (char)0x0A, (char)0xC1, (char)0x0A, (char)0x9C, (char)0x0A, (char)0xB0, (char)0x0A, (char)0xBE, (char)0x0A, (char)0xA4, (char)0x0A, (char)0xC0, (char)0x0A,},
"*#9127#",

"gu-IN"
},
#endif
#if defined(__MMI_LANG_BENGALI__)
{
{ (char)0xac, (char)0x09, (char)0xbe, (char)0x09, (char)0x82, (char)0x09, (char)0xb2, (char)0x09, (char)0xbe, (char)0x09, (char)0x0,},
 "*#9133#",

 "be-IN"
},
#endif
#if defined(__MMI_LANG_ASSAMESE__)
{
{ (char)0x85, (char)0x09, (char)0xb8, (char)0x09, (char)0xae, (char)0x09, (char)0xc0, (char)0x09, (char)0xdf, (char)0x09, (char)0xbe, (char)0x09, (char)0x0,},
 "*#9161#",

 "as-IN"
},
#endif
#if defined(__MMI_LANG_PUNJABI__)
{
{ (char)0x2A, (char)0x0A, (char)0x02, (char)0x0A, (char)0x1C, (char)0x0A, (char)0x3E, (char)0x0A, (char)0x2C, (char)0x0A,(char)0x40, (char)0x0A,},
"*#9172#",

"pa-IN"
},
#endif
#if defined(__MMI_LANG_TELUGU__)
{
{ (char)0x24, (char)0x0C, (char)0x32, (char)0x0C, (char)0x41, (char)0x0C, (char)0x17, (char)0x0C, (char)0x41, (char)0x0C},
"*#9140#",

"te-IN"
},
#endif
#if defined(__MMI_LANG_KANNADA__)
{
{ (char)0x95, (char)0x0C, (char)0xA8, (char)0x0C, (char)0xCD, (char)0x0C, (char)0xA8, (char)0x0C, (char)0xA1, (char)0x0C},
"*#9180#",

"kn-IN"
},
#endif
#if defined(__MMI_LANG_MALAYALAM__)
{
{ (char)0x2E, (char)0x0D, (char)0x32, (char)0x0D, (char)0x2F, (char)0x0D, (char)0x3E, (char)0x0D, (char)0x33, (char)0x0D, (char)0x2E, (char)0x0D, (char)0x4D, (char)0x0D},
"*#9171#",

"ml-IN"
},
#endif
#if defined(__MMI_LANG_LAO__)
{
{ (char)0xC0, (char)0x0E, (char)0xA1, (char)0x0E, (char)0xB7, (char)0x0E, (char)0xAD, (char)0x0E, (char)0x87, (char)0x0E, (char)0xA5, (char)0x0E, (char)0xB2, (char)0x0E, (char)0xA7, (char)0x0E},
"*#0856#",
"lo-IN"
},
#endif
#if defined(__MMI_LANG_KHMER__)
{
{ (char)0x97, (char)0x17, (char)0xB6, (char)0x17, (char)0x9F, (char)0x17, (char)0xB6, (char)0x17, (char)0x81, (char)0x17, (char)0xD2, (char)0x17, (char)0x98, (char)0x17, (char)0xC2, (char)0x17, (char)0x9A, (char)0x17 },
"*#0855#",
"km-IN"
},
#endif
#if defined(__MMI_LANG_MYANMAR__)
{
{ (char)0x19, (char)0x10, (char)0x3C, (char)0x10, (char)0x14, (char)0x10, (char)0x3A, (char)0x10, (char)0x19, (char)0x10, (char)0x2C, (char)0x10},
"*#0095#",
"my-IN"
},
#endif
#if defined(__MMI_LANG_ORIYA__)
{
{ (char)0x13, (char)0x0B, (char)0x21, (char)0x0B, (char)0x3F, (char)0x0B, (char)0x06, (char)0x0B,},
"*#9174#",

"or-IN"
},
#endif
#if defined(__MMI_LANG_XHOSA__)
{
 {(char)0x58,(char)0x0,(char)0x68,(char)0x0,(char)0x6F,(char)0x0,(char)0x73,(char)0x0,(char)0x61,(char)0x0},//Language Name
  "*#0027#",//SSC string name

 "xh-ZA"
},
#endif
#if defined(__MMI_LANG_SWAHILI__)
{
 {(char)0x53,(char)0x0,(char)0x77,(char)0x0,(char)0x61,(char)0x0,(char)0x68,(char)0x0,(char)0x69,(char)0x0,(char)0x6C,(char)0x0,(char)0x69,(char)0x0},//Language Name
  "*#0255#",//SSC string name

 "sw-TZ"
},
#endif
#if defined(__MMI_LANG_AFRIKAANS__)
{
 {(char)0x41,(char)0x0,(char)0x66,(char)0x0,(char)0x72,(char)0x0,(char)0x69,(char)0x0,(char)0x6B,(char)0x0,(char)0x61,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0,(char)0x73,(char)0x0},//Language Name
  "*#0264#",//SSC string name
 
 "af-NA"
},
#endif
#if defined(__MMI_LANG_ZULU__)
{
 {(char)0x5A,(char)0x0,(char)0x75,(char)0x0,(char)0x6C,(char)0x0,(char)0x75,(char)0x0},//Language Name
  "*#0268#",//SSC string name

 "zu-SZ"
},
#endif
#if defined(__MMI_LANG_LITHUANIAN__)
{
 {(char)0x4C,(char)0x0,(char)0x69,(char)0x0,(char)0x74,(char)0x0,(char)0x68,(char)0x0,(char)0x75,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0370#",//SSC string name

 "lt-LT"
},
#endif
#if defined(__MMI_LANG_LATVIAN__)
{
 {(char)0x4C,(char)0x0,(char)0x61,(char)0x0,(char)0x74,(char)0x0,(char)0x76,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0371#",//SSC string name
 
 "lv-LV"
},
#endif
#if defined(__MMI_LANG_ESTONIAN__)
{
 {(char)0x45,(char)0x0,(char)0x73,(char)0x0,(char)0x74,(char)0x0,(char)0x6F,(char)0x0,(char)0x6E,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0372#",//SSC string name

 "et-EE"
},
#endif
#if defined(__MMI_LANG_ARMENIAN__)
{
 {(char)0x41,(char)0x0,(char)0x72,(char)0x0,(char)0x6D,(char)0x0,(char)0x65,(char)0x0,(char)0x6E,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0374#",//SSC string name

 "hy-AM"
},
#endif
#if defined(__MMI_LANG_GEORGIAN__)
{
 {(char)0x47,(char)0x0,(char)0x65,(char)0x0,(char)0x6F,(char)0x0,(char)0x72,(char)0x0,(char)0x67,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0995#",//SSC string name

 "ka-GE"
},
#endif
#if defined(__MMI_LANG_MOLDOVAN__)
{
 {(char)0x4D,(char)0x0,(char)0x6F,(char)0x0,(char)0x6C,(char)0x0,(char)0x64,(char)0x0,(char)0x6F,(char)0x0,(char)0x76,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0373#",//SSC string name

 "mo-MD"
},
#endif



};