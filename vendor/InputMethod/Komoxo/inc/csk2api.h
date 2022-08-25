
/***************************************************************************
 
Description: Input method library interface

Copyright (C) 2000-2007 Beijing Komoxo Inc.
All rights reserved.

****************************************************************************/

#ifndef CSK2API_H
#define CSK2API_H

#ifdef __cplusplus 
extern "C"{ 
#endif 

/*-------------------------------------------------------------------------*/
/*                                                                         */
/* Basic type defines                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/

#define CS_VOID     void
#define CS_PVOID    void*
#define CS_PCVOID   const void*

typedef signed char             CS_INT8;
typedef unsigned char           CS_BYTE;
typedef signed short            CS_SHORT;
typedef unsigned short          CS_WORD;
typedef signed  int             CS_INT;
typedef unsigned int            CS_UINT;
typedef signed long             CS_LONG;
typedef unsigned long           CS_DWORD;
typedef float                   CS_FLOAT32;
typedef double                  CS_DOUBLE;

typedef unsigned char           CS_CHAR;
typedef unsigned char*          CS_PSTR;
typedef const unsigned char*    CS_PCSTR;

typedef unsigned short          CS_WCHAR;
typedef unsigned short*         CS_PWSTR;
typedef const unsigned short*   CS_PCWSTR;

typedef int                     CS_BOOL;

typedef unsigned long           CS_RESULT;
typedef void *                  CS_HANDLE;
typedef CS_HANDLE               CS_HIMM;
typedef CS_HANDLE               CS_HCORE;

typedef unsigned short          CS_POINTERID;

#define CS_TRUE                 1
#define CS_FALSE                0

/*-------------------------------------------------------------------------*/
/*                                                                         */
/* Virtual key defines                                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/

#define CS_VK_NONE          0x0

#define CS_VK_1             0x31
#define CS_VK_2             0x32
#define CS_VK_3             0x33
#define CS_VK_4             0x34
#define CS_VK_5             0x35
#define CS_VK_6             0x36
#define CS_VK_7             0x37
#define CS_VK_8             0x38
#define CS_VK_9             0x39
#define CS_VK_L1            0x3A
#define CS_VK_L2            0x3B
#define CS_VK_L3            0x3C
#define CS_VK_R1            0x3D
#define CS_VK_R2            0x3E
#define CS_VK_R3            0x3F

#define CS_VK_A             0x61
#define CS_VK_BACKSPACE     0x08
#define CS_VK_LEFT          0x25
#define CS_VK_UP            0x26
#define CS_VK_RIGHT         0x27
#define CS_VK_DOWN          0x28
#define CS_VK_SELECT        0x29

/* Symbian    在拼音/笔画中作为CS_VK_SPACE使用, 其他情况为CS_VK_0 */
/* Smartphone 在拼音输入法中作为CS_VK_AUX使用, 其他情况下为CS_VK_0 */
#define CS_VK_0             0x30

/* Symbian    在拼音输入法中作为CS_VK_AUX使用, 其他情况下为CS_VK_START */
/* Smartphone 作为CS_VK_IME使用 */
#define CS_VK_STAR          0x2a

/* Symbian    作为CS_VK_IME使用 */
/* Smartphone 作为CS_VK_SPACE使用 */
#define CS_VK_POUND         0x23

/* 功能键, 没有与键盘直接对应, 如果输入法管理器收到以下键可以直接交给Provider使用 */
#define CS_VK_SPACE         0x20  /* 空格\切分*/
#define CS_VK_AUX           0x41  /* 显示AUX(目前拼音专用)*/
#define CS_VK_IME           0x40  /* 切换输入法*/

#define CS_VK_PLUS          0x42

#define CS_VK_LONGCLICK     0x00010000      /* 表示长按键 */
#define CS_VK_REPEAT        0x00020000      /* 表示长按键 */

/*-------------------------------------------------------------------------*/
/*                                                                         */
/* Error code defines                                                      */
/*                                                                         */
/*-------------------------------------------------------------------------*/

#define CS_ERROR_SUCCESS                    0x00000000
#define CS_ERROR_UNKNOWN                    0x00000001

#define CS_ERROR_USED                       0x00000700
#define CS_ERROR_UNUSED                     0x00000701
#define CS_ERROR_COMMIT						0x00000702
#define CS_ERROR_TIPS                       0x00000800

/*-------------------------------------------------------------------------*/
/*                                                                         */
/* Input method defines                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/

/*  language id */
#define CHS_CHARSET     936
#define CHT_CHARSET     950
#define ENG_CHARSET     1252

/* Language identifiers */

#define CS_LANG_CHS             1
#define CS_LANG_CHT             2
#define CS_LANG_ENGLISH         10
#define CS_LANG_RUSSIAN         20
#define CS_LANG_GERMAN          30
#define CS_LANG_VIETNAMESE      31
#define CS_LANG_INDONESIAN      32
#define CS_LANG_TURKISH         33
#define CS_LANG_MALAY           34
#define CS_LANG_GREEK           35
#define CS_LANG_THAI            36
#define CS_LANG_DANISH          37
#define CS_LANG_DUTCH           38
#define CS_LANG_POLISH          39
#define CS_LANG_FRENCH          40
#define CS_LANG_HUNGARIAN       41
#define CS_LANG_HEBREW          42
#define CS_LANG_BULGARIAN       43
#define CS_LANG_CZECH           44
#define CS_LANG_FINNISH         45
#define CS_LANG_PERSIAN         46
#define CS_LANG_SLOVAK          47
#define CS_LANG_NORWEGIAN       48
#define CS_LANG_SWEDISH         49
#define CS_LANG_SPANISH         50
#define CS_LANG_CROATIAN        51
#define CS_LANG_ROMANIAN        52
#define CS_LANG_SLOVENIAN       53
#define CS_LANG_UKRAINIAN       54
#define CS_LANG_SWAHILI         55
#define CS_LANG_LITHUANIAN      56
#define CS_LANG_ARMENIAN        57
#define CS_LANG_TAGALOG         58
#define CS_LANG_PORTUGUESE      60
#define CS_LANG_ITALIAN         70
#define CS_LANG_ARABIC          80
#define CS_LANG_HINDI           90
#define CS_LANG_HINGLISH        91
#define CS_LANG_BENGALI         92
#define CS_LANG_HANGUL          93
#define CS_LANG_UYGHUR          94
#define CS_LANG_URDU            95
#define CS_LANG_TELUGU          96
#define CS_LANG_MARATHI         97
#define CS_LANG_TAMIL           98
#define CS_LANG_MYANMAR         99

/* Input method identifiers */

#define IM_SURETYPE_BASE        10000
#define IM_USER_MULTITYPE_BASE  20000

#define IM_LATINFULLKEY_BASE	0x10000
#define IM_FULLKEY_BASE         0x10000

#define IM_NONE                 0
#define IM_PINYIN               1
#define IM_STROKE               2
#define IM_MAGIC_ONE            3
#define IM_STROKE_BIG5          4
#define IM_PINYIN_DZ            5
#define IM_123                  7
#define IM_ZHUYIN_MT            8
#define IM_ZHUYIN               9
#define IM_PINYIN_SURETYPE      (IM_PINYIN + IM_SURETYPE_BASE)
#define IM_PINYIN_FULLKEY       11
#define IM_ZHUYIN_FULLKEY       12

#define IM_ZHUYIN_MT_FULL       13
#define IM_ZHUYIN_2             14      // for second zhuyin qwerty keyboard definition
                                        // there is not IM_ZHUYIN_2, must use (IM_ZHUYIN_2 + IM_FULLKEY_BASE)

#define IM_NUMBER               22

#define IM_PINYIN_TC            30
#define IM_PINYIN_FULLKEY_TC    31
#define IM_ZHUYIN_MT_SC         32
#define IM_ZHUYIN_FULLKEY_SC    33

#define IM_ENGLISH              101
#define IM_ABC_LOWER            102
#define IM_ABC_UPPER            103
#define IM_ABC_LEAD_UPPER       104
#define IM_ABC                  105
#define IM_ENGLISH_LEAD_UPPER	107
#define IM_ENGLISH_UPPER        108
#define IM_ENGLISH_LOWER        109

#define IM_RUSSIAN              201
#define IM_ABC_LOWER_RUS        202
#define IM_ABC_UPPER_RUS        203
#define IM_ABC_LEAD_UPPER_RUS   204
#define IM_ABC_RUS              205
#define IM_RUSSIAN_LEAD_UPPER   207
#define IM_RUSSIAN_UPPER        208
#define IM_RUSSIAN_LOWER        209

#define IM_GERMAN               301
#define IM_ABC_LOWER_DE         302
#define IM_ABC_UPPER_DE         303
#define IM_ABC_LEAD_UPPER_DE    304
#define IM_ABC_DE               305
#define IM_GERMAN_LEAD_UPPER    307
#define IM_GERMAN_UPPER         308
#define IM_GERMAN_LOWER         309

#define IM_VIETNAMESE           311
#define IM_ABC_LOWER_VI         312
#define IM_ABC_UPPER_VI         313
#define IM_ABC_LEAD_UPPER_VI    314
#define IM_ABC_VI               315
#define IM_VIETNAMESE_LEAD_UPPER    317
#define IM_VIETNAMESE_UPPER     318
#define IM_VIETNAMESE_LOWER     319

#define IM_INDONESIAN           321
#define IM_ABC_LOWER_ID         322
#define IM_ABC_UPPER_ID         323
#define IM_ABC_LEAD_UPPER_ID    324
#define IM_ABC_ID               325
#define IM_INDONESIAN_LEAD_UPPER     327
#define IM_INDONESIAN_UPPER     328
#define IM_INDONESIAN_LOWER     329

#define IM_TURKISH              331
#define IM_ABC_LOWER_TR         332
#define IM_ABC_UPPER_TR         333
#define IM_ABC_LEAD_UPPER_TR    334
#define IM_ABC_TR               335
#define IM_TURKISH_LEAD_UPPER        337
#define IM_TURKISH_UPPER        338
#define IM_TURKISH_LOWER        339

#define IM_MALAY                341
#define IM_ABC_LOWER_MS         342
#define IM_ABC_UPPER_MS         343
#define IM_ABC_LEAD_UPPER_MS    344
#define IM_ABC_MS               345
#define IM_MALAY_LEAD_UPPER          347
#define IM_MALAY_UPPER          348
#define IM_MALAY_LOWER          349

#define IM_GREEK                351
#define IM_ABC_LOWER_EL         352
#define IM_ABC_UPPER_EL         353
#define IM_ABC_LEAD_UPPER_EL    354
#define IM_ABC_EL               355
#define IM_GREEK_LEAD_UPPER          357
#define IM_GREEK_UPPER          358
#define IM_GREEK_LOWER          359

#define IM_THAI                 361
#define IM_THAI_MT              363
#define IM_THAI_123             364

#define IM_DANISH               371
#define IM_ABC_LOWER_DA         372
#define IM_ABC_UPPER_DA         373
#define IM_ABC_LEAD_UPPER_DA    374
#define IM_ABC_DA               375
#define IM_DANISH_LEAD_UPPER         377
#define IM_DANISH_UPPER         378
#define IM_DANISH_LOWER         379

#define IM_DUTCH                381
#define IM_ABC_LOWER_NL         382
#define IM_ABC_UPPER_NL         383
#define IM_ABC_LEAD_UPPER_NL    384
#define IM_ABC_NL               385
#define IM_DUTCH_LEAD_UPPER          387
#define IM_DUTCH_UPPER          388
#define IM_DUTCH_LOWER          389

#define IM_POLISH               391
#define IM_ABC_LOWER_PL         392
#define IM_ABC_UPPER_PL         393
#define IM_ABC_LEAD_UPPER_PL    394
#define IM_ABC_PL               395
#define IM_POLISH_LEAD_UPPER         397
#define IM_POLISH_UPPER         398
#define IM_POLISH_LOWER         399

#define IM_FRENCH               401
#define IM_ABC_LOWER_FR         402
#define IM_ABC_UPPER_FR         403
#define IM_ABC_LEAD_UPPER_FR    404
#define IM_ABC_FR               405
#define IM_FRENCH_LEAD_UPPER         407
#define IM_FRENCH_UPPER         408
#define IM_FRENCH_LOWER         409

#define IM_HUNGARIAN            411
#define IM_ABC_LOWER_HU         412
#define IM_ABC_UPPER_HU         413
#define IM_ABC_LEAD_UPPER_HU    414
#define IM_ABC_HU               415
#define IM_HUNGARIAN_LEAD_UPPER      417
#define IM_HUNGARIAN_UPPER      418
#define IM_HUNGARIAN_LOWER      419
 
#define IM_HEBREW               421
#define IM_HEBREW_MT            423

#define IM_BULGARIAN            431
#define IM_ABC_LOWER_BG         432
#define IM_ABC_UPPER_BG         433
#define IM_ABC_LEAD_UPPER_BG    434
#define IM_ABC_BG               435
#define IM_BULGARIAN_LEAD_UPPER      437
#define IM_BULGARIAN_UPPER      438
#define IM_BULGARIAN_LOWER      439

#define IM_CZECH                441
#define IM_ABC_LOWER_CS         442
#define IM_ABC_UPPER_CS         443
#define IM_ABC_LEAD_UPPER_CS    444
#define IM_ABC_CS               445
#define IM_CZECH_LEAD_UPPER          447
#define IM_CZECH_UPPER          448
#define IM_CZECH_LOWER          449

#define IM_FINNISH              451
#define IM_ABC_LOWER_FI         452
#define IM_ABC_UPPER_FI         453
#define IM_ABC_LEAD_UPPER_FI    454
#define IM_ABC_FI               455
#define IM_FINNISH_LEAD_UPPER        457
#define IM_FINNISH_UPPER        458
#define IM_FINNISH_LOWER        459

#define IM_PERSIAN              461
#define IM_PERSIAN_MT           463
#define IM_PERSIAN_123          464

#define IM_SLOVAK               471
#define IM_ABC_LOWER_SK         472
#define IM_ABC_UPPER_SK         473
#define IM_ABC_LEAD_UPPER_SK    474
#define IM_ABC_SK               475
#define IM_SLOVAK_LEAD_UPPER         477
#define IM_SLOVAK_UPPER         478
#define IM_SLOVAK_LOWER         479

#define IM_NORWEGIAN            481
#define IM_ABC_LOWER_NO         482
#define IM_ABC_UPPER_NO         483
#define IM_ABC_LEAD_UPPER_NO    484
#define IM_ABC_NO               485
#define IM_NORWEGIAN_LEAD_UPPER      487
#define IM_NORWEGIAN_UPPER      488
#define IM_NORWEGIAN_LOWER      489

#define IM_SWEDISH              491
#define IM_ABC_LOWER_SV         492
#define IM_ABC_UPPER_SV         493
#define IM_ABC_LEAD_UPPER_SV    494
#define IM_ABC_SV               495
#define IM_SWEDISH_LEAD_UPPER        497
#define IM_SWEDISH_UPPER        498
#define IM_SWEDISH_LOWER        499

#define IM_SPANISH              501
#define IM_ABC_LOWER_ES         502
#define IM_ABC_UPPER_ES         503
#define IM_ABC_LEAD_UPPER_ES    504
#define IM_ABC_ES               505
#define IM_SPANISH_LEAD_UPPER        507
#define IM_SPANISH_UPPER        508
#define IM_SPANISH_LOWER        509

#define IM_CROATIAN             511
#define IM_ABC_LOWER_HR         512
#define IM_ABC_UPPER_HR         513
#define IM_ABC_LEAD_UPPER_HR    514
#define IM_ABC_HR               515
#define IM_CROATIAN_LEAD_UPPER       517
#define IM_CROATIAN_UPPER       518
#define IM_CROATIAN_LOWER       519

#define IM_ROMANIAN             521
#define IM_ABC_LOWER_RO         522
#define IM_ABC_UPPER_RO         523
#define IM_ABC_LEAD_UPPER_RO    524
#define IM_ABC_RO               525
#define IM_ROMANIAN_LEAD_UPPER       527
#define IM_ROMANIAN_UPPER       528
#define IM_ROMANIAN_LOWER       529

#define IM_SLOVENIAN            531
#define IM_ABC_LOWER_SL         532
#define IM_ABC_UPPER_SL         533
#define IM_ABC_LEAD_UPPER_SL    534
#define IM_ABC_SL               535
#define IM_SLOVENIAN_LEAD_UPPER      537
#define IM_SLOVENIAN_UPPER      538
#define IM_SLOVENIAN_LOWER      539

#define IM_UKRAINIAN            541
#define IM_ABC_LOWER_UK         542
#define IM_ABC_UPPER_UK         543
#define IM_ABC_LEAD_UPPER_UK    544
#define IM_ABC_UK               545
#define IM_UKRAINIAN_LEAD_UPPER      547
#define IM_UKRAINIAN_UPPER      548
#define IM_UKRAINIAN_LOWER      549

#define IM_SWAHILI              551
#define IM_ABC_LOWER_SW         552
#define IM_ABC_UPPER_SW         553
#define IM_ABC_LEAD_UPPER_SW    554
#define IM_ABC_SW               555
#define IM_SWAHILI_LEAD_UPPER        557
#define IM_SWAHILI_UPPER        558
#define IM_SWAHILI_LOWER        559
           
#define IM_LITHUANIAN           561
#define IM_ABC_LOWER_LT         562
#define IM_ABC_UPPER_LT         563
#define IM_ABC_LEAD_UPPER_LT    564
#define IM_ABC_LT               565
#define IM_LITHUANIAN_LEAD_UPPER     567
#define IM_LITHUANIAN_UPPER     568
#define IM_LITHUANIAN_LOWER     569

#define IM_ARMENIAN             571
#define IM_ABC_LOWER_HY         572
#define IM_ABC_UPPER_HY         573
#define IM_ABC_LEAD_UPPER_HY    574
#define IM_ABC_HY               575
#define IM_ARMENIAN_LEAD_UPPER       577
#define IM_ARMENIAN_UPPER       578
#define IM_ARMENIAN_LOWER       579

// tagalog only has multitap, IM_TAGALOG can't used now!!!
#define IM_TAGALOG              581
#define IM_ABC_LOWER_TL         582
#define IM_ABC_UPPER_TL         583
#define IM_ABC_LEAD_UPPER_TL    584
#define IM_ABC_TL               585
#define IM_TAGALOG_LEAD_UPPER       587
#define IM_TAGALOG_UPPER       588
#define IM_TAGALOG_LOWER       589

#define IM_PORTUGUESE           601
#define IM_ABC_LOWER_PT         602
#define IM_ABC_UPPER_PT         603
#define IM_ABC_LEAD_UPPER_PT    604
#define IM_ABC_PT               605
#define IM_PORTUGUESE_LEAD_UPPER     607
#define IM_PORTUGUESE_UPPER     608
#define IM_PORTUGUESE_LOWER     609

#define IM_ITALIAN              701
#define IM_ABC_LOWER_IT         702
#define IM_ABC_UPPER_IT         703
#define IM_ABC_LEAD_UPPER_IT    704
#define IM_ABC_IT               705
#define IM_ITALIAN_LEAD_UPPER        707
#define IM_ITALIAN_UPPER        708
#define IM_ITALIAN_LOWER        709

#define IM_ARABIC               801
#define IM_ARABIC_MT            803
#define IM_ARABIC_123           804

#define IM_HINDI                901
#define IM_HINDI_MT             903
#define IM_HINDI_123            904

#define IM_HINGLISH             911
#define IM_ABC_LOWER_HIN        912
#define IM_ABC_UPPER_HIN        913
#define IM_ABC_LEAD_UPPER_HIN   914
#define IM_ABC_HIN              915
#define IM_HINGLISH_LEAD_UPPER       917
#define IM_HINGLISH_UPPER       918
#define IM_HINGLISH_LOWER       919

#define IM_BENGALI              921
#define IM_BENGALI_MT           923
#define IM_BENGALI_123          924

#define IM_HANGUL               931
#define IM_HANGUL_MT            933

#define IM_UYGHUR               941
#define IM_UYGHUR_MT            943

#define IM_URDU                 951
#define IM_URDU_MT              953

#define IM_TELUGU               961
#define IM_TELUGU_MT            963

#define IM_MARATHI              971
#define IM_MARATHI_MT           973

#define IM_TAMIL                981
#define IM_TAMIL_MT             983

#define IM_MYANMAR              991
#define IM_MYANMAR_MT           993

#define CS_BASE_IM(im_id)                   ((im_id) & 0xFFFF)
#define CS_LANG_FROM_LATIN_IM(im_id)        ((im_id) / 10)
#define CS_BASE_LATIN_IM_FROM_LANG(lang_id) ((lang_id) * 10 + 1)
#define CS_IS_LATIN_IM(im_id)               ((im_id) >= IM_ENGLISH && (im_id) < IM_SURETYPE_BASE)
#define CS_IM_TO_BASE_LATIN_IM(im_id)       (CS_BASE_LATIN_IM_FROM_LANG(CS_LANG_FROM_LATIN_IM(im_id)))

/* IM Identifiers */
#define CS_TYPE_FROM_LATIN_IM(im_id)        ((im_id) % 10)
#define CS_IS_LATIN_MULTITAP_TYPE(tp)       ((tp) >= 2 && (tp) <= 5)
#define CS_IS_LATIN_SMART_TYPE(tp)          (((tp) == 1) || ((tp) >= 7 && (tp) <= 9))


/* client event type */
#define CS_EVENT_KEYBOARD       0x0001
#define CS_EVENT_TIMER          0x0002
#define CS_EVENT_CHAR			0x0003
#define CS_EVENT_CHAR_APPEND    0x0003
#define CS_EVENT_CHAR_REPLACE   0x0004

/* event for full keyboard or touch panel */
#define	CS_EVENT_APPENDCHAR		0x0010
#define CS_EVENT_REMOVECHAR		0x0020
#define CS_EVENT_SELECTCAND		0x0040
#define CS_EVENT_REMOVEALL		0x0080
#define CS_EVENT_PAGENEXT		0x0100
#define CS_EVENT_PAGEPREVIOUS	0x0200

/* client window state */
#define CS_FLAG_STATE_EDIT      1
#define CS_FLAG_STATE_CAND      2
#define CS_FLAG_STATE_USER      3
#define CS_FLAG_STATE_ACTIVE    4

/* candidate and pychoice window PAGEUP/PAGEDOWN flags */
#define CS_FLAG_PAGEUP          0x0001
#define CS_FLAG_PAGEDOWN        0x0002

/* timer operator */
#define CS_TIMER_SET            1
#define CS_TIMER_CLEAR          2

/* association flags for stroke and pinyin input method */
#define CS_ASSOCIATION_ON              1            /* switch on association*/
#define CS_ASSOCIATION_OFF             0            /* switch off assocition (default)*/

/* keyboard layout for five-stroke input method (default) */
#define CS_STROKE_STANDARD_LAYOUT      0x0000       
/* national standard layout
        1-5 key: hen shu pie na zhe
        6 key  : ? anything
        7 key : magic-one for symbols, digits and english
 */

#define CS_STROKE_CSTAR_LAYOUT_ONE      0x0001
/* cstar defined keyboad layout
        1 key: magic-one for symbols, digits and english
        2-6 keys: hen shu pie na zhe
        7 key: ? anything
 */

/* config whether disable wildcard or not. default is not disable wildcard */
#define CS_STROKE_DISABLE_WILDCARD_OFF  0  /* Enable stroke wildcard. (default) */
#define CS_STROKE_DISABLE_WILDCARD_ON   1  /* Disable stroke wildcard. */ 


#define CS_PINYIN_MODE_1                0x0001      // user can edit pinyin, the "star" key is iterator choice
#define CS_PINYIN_MODE_2                0x0002      // user can't edit pinyin, user can't step candidates
#define CS_PINYIN_MODE_3                0x0003      // user can't edit pinyin, user can step candidates

#define CS_CANDIDATE_MODE_1                0x0001      // 1 line candidates
#define CS_CANDIDATE_MODE_2                0x0002      // 2 line candidates

#define CS_FULLKEY_PINYIN_MODE_1        0x0001      // 全键盘输入时，候选字自动加入标签
#define CS_FULLKEY_PINYIN_MODE_2        0x0002      // 全键盘输入时，需要按方向键后，才有候选字标签

/* fuzzy phone flags for pinyin input method */
#define CS_FUZZY_SHENGMU_NUM    10
#define CS_FUZZY_Z_ZH           0x0001    /* 打开模糊音 z zh*/
#define CS_FUZZY_C_CH           0x0002    /* 打开模糊音 c ch*/
#define CS_FUZZY_S_SH           0x0004    /* 打开模糊音 s sh */
#define CS_FUZZY_H_F            0x0008    /* 打开模糊音 h f */
#define CS_FUZZY_N_L            0x0010    /* 打开模糊音 n l */

#define CS_FUZZY_YUNMU_NUM      10
#define CS_FUZZY_IN_ING         0x0100    /* 打开模糊音 in ing */
#define CS_FUZZY_EN_ENG         0x0200    /* 打开模糊音 en eng */
#define CS_FUZZY_AN_ANG         0x0400    /* 打开模糊音 an ang */
#define CS_FUZZY_IAN_IANG       0x0800    /* 打开模糊音 ian iang */
#define CS_FUZZY_UAN_UANG       0x1000    /* 打开模糊音 uan uang */

#define CS_EUDW_DISABLED        0x8000   /* 取消西文的用户自定义词 */

/* Alphabetic language input mdoe flags */
#define CS_ALPHABETIC_PHRASE_INPUT     0            /* Phrase input for alphabetic language*/
#define CS_ALPHABETIC_WORD_INPUT       1            /* Word input for alphabetic language */

/* magic one on star key */
#define CS_MAGICONE_DEFAULT             0
#define CS_MAGICONE_STAR                1

/* Language database list */

typedef struct
{
    int             input_method;
    const void*     language_database;
} CS_IME_INFO;

extern const CS_IME_INFO cs_ldb_pinyin_cizu;
extern const CS_IME_INFO cs_ldb_pinyin_suretype;
extern const CS_IME_INFO cs_ldb_pinyin_danzi;
extern const CS_IME_INFO cs_ldb_pinyin_tc;
extern const CS_IME_INFO cs_ldb_pinyin_tc_suretype;

extern const CS_IME_INFO cs_ldb_zhuyin;
extern const CS_IME_INFO cs_ldb_zhuyin_cizu;
extern const CS_IME_INFO cs_ldb_zhuyin_danzi;
extern const CS_IME_INFO cs_ldb_zhuyin_sc;

extern const CS_IME_INFO cs_ldb_stroke_chs;
extern const CS_IME_INFO cs_ldb_stroke_gb2312;
extern const CS_IME_INFO cs_ldb_stroke_gbk;
extern const CS_IME_INFO cs_ldb_stroke_gb18030;
extern const CS_IME_INFO cs_ldb_stroke_big5;
extern const CS_IME_INFO cs_ldb_stroke_big5hkscs;

extern const CS_IME_INFO cs_ldb_english;

extern const CS_IME_INFO cs_ldb_armenian;
extern const CS_IME_INFO cs_ldb_arabic;
extern const CS_IME_INFO cs_ldb_bengali;
extern const CS_IME_INFO cs_ldb_bulgarian;
extern const CS_IME_INFO cs_ldb_czech;
extern const CS_IME_INFO cs_ldb_danish;
extern const CS_IME_INFO cs_ldb_dutch;
extern const CS_IME_INFO cs_ldb_finnish;
extern const CS_IME_INFO cs_ldb_french;
extern const CS_IME_INFO cs_ldb_german;
extern const CS_IME_INFO cs_ldb_greek;
extern const CS_IME_INFO cs_ldb_hebrew;
extern const CS_IME_INFO cs_ldb_hindi;
extern const CS_IME_INFO cs_ldb_hinglish;
extern const CS_IME_INFO cs_ldb_hungarian;
extern const CS_IME_INFO cs_ldb_indonesian;
extern const CS_IME_INFO cs_ldb_italian;
extern const CS_IME_INFO cs_ldb_lithuanian;
extern const CS_IME_INFO cs_ldb_malay;
extern const CS_IME_INFO cs_ldb_norwegian;
extern const CS_IME_INFO cs_ldb_persian;
extern const CS_IME_INFO cs_ldb_polish;
extern const CS_IME_INFO cs_ldb_portuguese;
extern const CS_IME_INFO cs_ldb_romanian;
extern const CS_IME_INFO cs_ldb_russian;
extern const CS_IME_INFO cs_ldb_slovak;
extern const CS_IME_INFO cs_ldb_slovenian;
extern const CS_IME_INFO cs_ldb_spanish;
extern const CS_IME_INFO cs_ldb_swahili;
extern const CS_IME_INFO cs_ldb_swedish;
extern const CS_IME_INFO cs_ldb_tagalog;
extern const CS_IME_INFO cs_ldb_thai;
extern const CS_IME_INFO cs_ldb_turkish;
extern const CS_IME_INFO cs_ldb_ukrainian;
extern const CS_IME_INFO cs_ldb_vietnamese;
extern const CS_IME_INFO cs_ldb_hangul;
extern const CS_IME_INFO cs_ldb_uyghur;
extern const CS_IME_INFO cs_ldb_urdu;
extern const CS_IME_INFO cs_ldb_telugu;
extern const CS_IME_INFO cs_ldb_marathi;
extern const CS_IME_INFO cs_ldb_tamil;
extern const CS_IME_INFO cs_ldb_myanmar;

extern const CS_IME_INFO cs_ldb_english_suretype;

/* Input method configuration table */

typedef const CS_IME_INFO* CS_IME_INFO_PTR;

extern const CS_IME_INFO_PTR cs_input_method_config[];

/* language params*/
typedef struct
{
    int             dwLangId;           /* [in]  language id*/
    int             nMethods;           /* [out] the input methods number of current language*/
    unsigned short  idIM[12];           /* [out] input methods id, max is 8, which is IM_PINYIN, IM_BIHUA, IM_ABC, etc.*/
} CS_LANG_PARAMS, *PCS_LANG_PARAMS;

typedef int (*CS_GET_TEXT_WIDTH_FUNC)(const unsigned short* text, int length);
typedef int (*CALLBACK_READ_UPDATE_DATA)(unsigned char *buffer, int pos, int length);

typedef int (*CALLBACK_CHECK_VALID_HANZI)(unsigned short unichr);
typedef int (*CALLBACK_GET_CONTEXT)(const unsigned short **text, int *length);

/* UI specified parameters */
typedef struct
{
    int             nMaxPYChoice;        /* [in] max display number of pinyin combination*/
    int             nWinWidth;           /* [in] Candidate window width*/
    int             nLableWidth;         /* [in] Lable width*/
    
	CS_GET_TEXT_WIDTH_FUNC		pGetTextWidthFunc;	/* 获取字符串宽度的回调函数 */
	CALLBACK_READ_UPDATE_DATA	pfnReadUpdateData;	/* 读取更新词库回调函数，如果为空，则不使用更新词库 */
}CS_IMM_PARAMS, *PCS_IMM_PARAMS;

/* user-defined-word and auto-frequence-adjustment data params*/
typedef struct
{
    int             iUserCacheSize;     /* [in] user-word buffer size*/
    char*           pUserCache;         /* [in] user-word buffer address*/
} CS_USER_PARAMS, *PCS_USER_PARAMS;

/* UI client content for basic API */
typedef struct
{
    /* Commit content*/
    unsigned short pCommit[64];

    /* pre-edit content*/
    unsigned short pPreBuffer[64];      /* buffer of pre-edit window*/
    unsigned short nPreEdit;            /* number of pre-edit content*/
    unsigned short iHotPreEdit;         /* the hotspot of pre-edit*/

    /* Candidate content*/
    unsigned short pCandBuffer[64];     /* buffer of candidate window*/
    unsigned short nCand;               /* number of candidate content*/
    unsigned short iHotCand;            /* the hotspot of candidate*/

    /* pychoice content*/
    unsigned short pChoiceBuffer[64];
    unsigned short nChoice;
    unsigned short iHotChoice;

    /* underline content*/
    unsigned short pUnderlineBuffer[64];
    unsigned short nUnderline;
    unsigned short iHotUnderline;

    /* user word content*/
    unsigned short pUserWordBuffer[64];
    unsigned short nUserWord;
    unsigned short iHotUserWord;

    /* underline caret pos begin from 0,*/
    unsigned short iCaretPos;
    unsigned short bShowCaret;

    /* Page up/down flag of Candidate and Pinyin-Choice window*/
    unsigned short flagPageCand;
    unsigned short flagPageChoice;

    /* state*/
    unsigned short flagState;

    /* Timer operator*/
    unsigned short flagTimer;
} CS_IMM_CONTENT, *PCS_IMM_CONTENT;

typedef unsigned short MULTI_STRING[16];

typedef struct 
{
    unsigned short multi_key_number;
    unsigned short long_multi_key_number;
    const MULTI_STRING *multi_table;
    const MULTI_STRING *long_multi_table;
} CS_MULTI_STRING_TABLE;

/* options for input method*/
typedef struct
{
    CALLBACK_CHECK_VALID_HANZI  pfnCheckValidHanzi;
    CALLBACK_GET_CONTEXT        pfnGetContext;

    unsigned int     dwPYFuzzy:16;       /* 模糊音设置*/
    unsigned int     dwStrokeLayout:1;   /* 笔画键盘布局*/
    unsigned int     dwStrokeWildCard:1; /* Stroke wildcard config */
    unsigned int     dwAssoPinyin:1;     /* 拼音联想设置*/
    unsigned int     dwAssoStroke:1;     /* 笔画联想设置*/
    unsigned int     dwPinyinMode:2;     /* 拼音操作模式 */
    unsigned int     dwCandidateMode:2;  /* 候选项模式 */
    unsigned int     dwMarScript:2;      /* 火星文选项 */
    unsigned int     dwAlphaBeticInputMode:2;    /* 字母语言输入模式 整句/单词 */
    unsigned int     dwFullkeyPinyinMode : 2;
    unsigned int     dwMagicOne : 2;
} CS_IMM_OPTIONS, *PCS_IMM_OPTIONS;

typedef struct
{
    unsigned short key;
    unsigned short value[11];
}QWERTY_KEYMAP;

/* Initialization/Cleanup */
CS_HIMM CS_IMM_Initialize(PCS_LANG_PARAMS pLangParams, PCS_IMM_PARAMS pImmParams, PCS_USER_PARAMS pUserParam);
CS_RESULT CS_IMM_Terminate(CS_HIMM hImm);

/* Input method selection */
CS_UINT CS_IMM_GetInputMethod(CS_HIMM hImm);
CS_RESULT CS_IMM_SetInputMethod(CS_HIMM hImm, CS_UINT iNewMethod);

CS_RESULT CS_IMM_SetInputMethodEx(CS_HIMM hImm, CS_UINT iNewMethod, const QWERTY_KEYMAP* keymap);

/* Add User defined multitype input method */
CS_RESULT CS_IMM_AddMultiIM(CS_HIMM hImm, CS_UINT iMethod, const CS_MULTI_STRING_TABLE* multi_table);

/* Event handler */
CS_RESULT CS_IMM_EventHandle(CS_HIMM hImm, CS_UINT hEvent, CS_UINT iMsg, PCS_IMM_CONTENT pContent);

/* Options */
CS_RESULT CS_IMM_SetOptionsEx(CS_HIMM hImm, const CS_IMM_OPTIONS* pOptions);
CS_RESULT CS_IMM_GetOptionsEx(CS_HIMM hImm, PCS_IMM_OPTIONS pOptions);

/* add user phase */
/* the input method must IM_PINYIN */
CS_RESULT CS_IMM_AddPhase(CS_HIMM hImm, unsigned short *szPhrase, int nLen);

CS_RESULT CS_IMM_CheckAsso(CS_HIMM hImm, unsigned short wContext, unsigned short *szAsso, int *pNumber);

CS_RESULT CS_IMM_QueryProperties(CS_HIMM hImm, int *pProperties);

const char* CS_IMM_GetVersion(void);

const char* CS_IMM_GetPinyinCharset(const CS_IME_INFO* ime_info);

/* Query Hanzi Association */
CS_RESULT   HanziAsso_QueryAsso(CS_BOOL  isPinyin,
								CS_WCHAR wContext,	/* 上下文内容unicode字符串，如“开始” */
                                CS_PWSTR pwzAsso,		/* 返回的联想候选序列*/
								CS_INT  *pnAsso);		/* 输入为所要的联想最大个数，返回的是实际候选个数*/

/*
 *
 * service provider interface 
 *
 */
typedef enum KMX_ACTIVE_STATE
{
	kmx_en_try,
	kmx_en_notice,
	kmx_en_actived
} kmx_active_state;

typedef struct
{
    int window_width;
    int label_width;
    int char_width;
    int reserved;
} CANDIDATE_WINDOW_METRICS;

kmx_active_state CS_IMM_GetActiveState(void);

void CS_IMM_SetOutputNumber(unsigned int);

int mmi_get_candidate_window_metrics(CANDIDATE_WINDOW_METRICS* metrics);

/*-------------------------------------------------------------------------*/
/*                                                                         */
/* Chinese pinyin and bpmf query                                           */
/*                                                                         */
/*-------------------------------------------------------------------------*/

CS_BOOL CS_IMM_QueryCodePinyin(CS_WORD wCode, CS_WCHAR *wszPinyin);

CS_BOOL CS_IMM_QueryCodeZhuyin(CS_WORD wCode, CS_WCHAR *wszZhuyin);

/*-------------------------------------------------------------------------*/
/*                                                                         */
/* Chinese stroke query                                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/

/* Stroke code constants */

#define CS_IMM_STROKE_H     1   /* Heng */
#define CS_IMM_STROKE_S     2   /* Shu  */
#define CS_IMM_STROKE_P     3   /* Pie  */
#define CS_IMM_STROKE_D     4   /* Dian */
#define CS_IMM_STROKE_Z     5   /* Zhe  */

/* Maximum stroke count of Chinese character */

#define CS_IMM_MAX_STROKE   63

int CS_IMM_QueryStroke_gb(
    unsigned short char_code,
    char* buffer,
    int buffer_length);

int CS_IMM_QueryStroke_gbk(
    unsigned short char_code,
    char* buffer,
    int buffer_length);

int CS_IMM_QueryStroke_big5(
    unsigned short char_code,
    char* buffer,
    int buffer_length);

/*-------------------------------------------------------------------------*/
/*                                                                         */
/* UI extension                                                            */
/*                                                                         */
/*-------------------------------------------------------------------------*/

#define CS_CAPACITY_QUERY_FLAG_TYPE_CAND 1
#define CS_CAPACITY_QUERY_FLAG_TYPE_COMP (1 << 1)
#define CS_CAPACITY_QUERY_FLAG_TYPE_AUX  (1 << 2)

#define CS_CAPACITY_QUERY_FLAG_STYLE_DIGIT_LABEL            (1 << 7)
#define CS_CAPACITY_QUERY_FLAG_STYLE_STAR                   (1 << 8)
#define CS_CAPACITY_QUERY_FLAG_STYLE_SHOW_PREV_ARROW        (1 << 9)
#define CS_CAPACITY_QUERY_FLAG_STYLE_SHOW_NEXT_ARROW        (1 << 10)


#define CS_MAX_CAND_CAPACITY_SIZE 9

typedef struct
{
    const unsigned short*   str;
    unsigned short          count;
    unsigned short          more_avaliable;
    unsigned int            flags;
}CS_CAPACITY_QUERY_PARAMS;

typedef int (*CALLBACK_QUERY_CAPACITY)(CS_CAPACITY_QUERY_PARAMS *params);

typedef struct
{
    unsigned int size;  /* Option size, for compatiablity. */
    CALLBACK_QUERY_CAPACITY pfnQueryCapacity;
}CS_IMM_EXTRA_OPTIONS;

CS_RESULT CS_IMM_SetExtraOptions(const CS_IMM_EXTRA_OPTIONS* pOptions);

const CS_IMM_EXTRA_OPTIONS* CS_IMM_GetExtraOptions(void);

#ifdef __cplusplus 
} 
#endif 

#endif /* CSK2API_H */
