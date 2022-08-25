#include "MMI_features.h"
#include "CustResDef.h"

<?xml version = "1.0" encoding = "UTF-8"?>
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__)
<APP id = "APP_RINGTONECOMPOSER">
    <!--Include Area-->

    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "FunAndGamesResDef.h"/>
    <INCLUDE file = "FunAndGamesProts.h"/>
    <INCLUDE file = "GameResDef.h"/>
    #ifdef __PLUTO_MMI_PACKAGE__
    <INCLUDE file = "mmi_rp_app_filemanager_def.h"/>
    #endif
    

    <!------String resource area------>
    <STRING id = "STR_MENU3103_RINGTONE_COMPOSER"/>
    <STRING id = "STR_COMPOSER_RINGTONE_LIST"/>
    <STRING id = "STR_COMP_RINGTONE_PLAY_SPEED"/>
#ifdef __MMI_RING_COMPOSER_STYLE__	
    <STRING id = "STR_COMP_RINGTONE_PLAY_STYLE"/>
#endif
    <STRING id = "STR_COMP_RINGTONE_SEL_INST"/>
    <STRING id = "STR_COMP_RINGTONE_DUPLICATE"/>
    <STRING id = "STR_COMP_RINGTONE_EMPTYFILENAME"/>
    <STRING id = "STR_COMP_RINGTONE_FAST"/>
    <STRING id = "STR_COMP_RINGTONE_NORMAL"/>
    <STRING id = "STR_COMP_RINGTONE_SLOW"/>

#ifdef __MMI_RING_COMPOSER_STYLE__	
    <STRING id = "STR_COMP_RINGTONE_STYLE_CONTINUOUS"/>
    <STRING id = "STR_COMP_RINGTONE_STYLE_NORMAL"/>
    <STRING id = "STR_COMP_RINGTONE_STYLE_STACCATO"/>
#endif 
    <STRING id = "STR_COMP_RINGTONE_PIANO" scope = "XML"/>
    <STRING id = "STR_COMP_RINGTONE_GUITAR" scope = "XML"/>
    <STRING id = "STR_COMP_RINGTONE_VIOLIN" scope = "XML"/>
    <STRING id = "STR_COMP_RINGTONE_SAXOPHONE" scope = "XML"/>
    <STRING id = "STR_COMP_RINGTONE_STEELDRUMS" scope = "XML"/>
    <STRING id = "STR_COMP_RINGTONE_FLUTE" scope = "XML"/>
    <STRING id = "STR_COMP_RINGTONE_HARMONICA" scope = "XML"/>
    <STRING id = "STR_COMP_RINGTONE_TRUMPET" scope = "XML"/>
    <STRING id = "STR_COMP_RINGTONE_MUSICBOX" scope = "XML"/>
    <STRING id = "STR_COMP_RINGTONE_XYLOPHONE" scope = "XML"/>
    <STRING id = "STR_COMP_RINGTONE_EMPTYRINGTONE"/>
    <STRING id = "STR_CAP_COMP_RINGTONE_DELETE"/>
    <STRING id = "STR_RING_COMPOSE_TITLE"/>
  
    <!------Image resource area------>
    <IMAGE id = "IMG_RING_COMPOSER_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Instrument\\\\R_BG.Gif"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_COMPOSER_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Instrument\\\\TH_R_BG.Gif"</IMAGE>
    
    <IMAGE id = "IMG_3BY2_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\WNOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY2_OCT_L_M_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\WNOTEFLA.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY2_OCT_L_M_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\WNOTESHA.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY2_OCT_U_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\WNOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY2_OCT_U_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\WNOTEFLA_H.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY2_OCT_U_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\WNOTESHA_H.bmp"</IMAGE>

    <IMAGE id = "IMG_1_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\WNOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_1_OCT_L_M_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\flat\\\\WNOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_1_OCT_L_M_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\sharp\\\\NOTE.bmp"</IMAGE>

    <IMAGE id = "IMG_1_OCT_U_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\WNOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_1_OCT_U_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\flat\\\\WNOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_1_OCT_U_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\sharp\\\\note_H.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY4_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\2NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY4_OCT_L_M_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\2NOTEFLA.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY4_OCT_L_M_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\2NOTESHA.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY4_OCT_U_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\2NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY4_OCT_U_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\2NOTEFLA_H.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY4_OCT_U_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\2NOTESHA_H.bmp"</IMAGE>

    <IMAGE id = "IMG_1BY2_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\2NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY2_OCT_L_M_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\flat\\\\2NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY2_OCT_L_M_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\sharp\\\\2NOTE.bmp"</IMAGE>

    <IMAGE id = "IMG_1BY2_OCT_U_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\2NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY2_OCT_U_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\flat\\\\2NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY2_OCT_U_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\sharp\\\\2NOTE_H.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY8_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\4NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY8_OCT_L_M_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\4NOTEFLA.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY8_OCT_L_M_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\4NOTESHA.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY8_OCT_U_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\4NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY8_OCT_U_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\4NOTEFLA_H.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY8_OCT_U_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\4NOTESHA_H.bmp"</IMAGE>

    <IMAGE id = "IMG_1BY4_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\4NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY4_OCT_L_M_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\flat\\\\4NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY4_OCT_L_M_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\sharp\\\\4NOTE.bmp"</IMAGE>

    <IMAGE id = "IMG_1BY4_OCT_U_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\4NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY4_OCT_U_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\flat\\\\4NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY4_OCT_U_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\sharp\\\\4NOTE_H.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY16_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\8NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY16_OCT_L_M_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\8NOTEFLA.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY16_OCT_L_M_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\8NOTESHA.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY16_OCT_U_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\8NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY16_OCT_U_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\8NOTEFLA_H.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY16_OCT_U_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\8NOTESHA_H.bmp"</IMAGE>

    <IMAGE id = "IMG_1BY8_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\8NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY8_OCT_L_M_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\flat\\\\8NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY8_OCT_L_M_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\sharp\\\\8NOTE.bmp"</IMAGE>

    <IMAGE id = "IMG_1BY8_OCT_U_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\8NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY8_OCT_U_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\flat\\\\8NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY8_OCT_U_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\sharp\\\\8NOTE_H.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY32_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\16NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY32_OCT_L_M_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\16NOTEFLA.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY32_OCT_L_M_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\16NOTESHA.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY32_OCT_U_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\16NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY32_OCT_U_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\16NOTEFLA_H.bmp"</IMAGE>
    <IMAGE id = "IMG_3BY32_OCT_U_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\16NOTESHA_H.bmp"</IMAGE>

    <IMAGE id = "IMG_1BY16_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\16NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY16_OCT_L_M_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\flat\\\\16NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY16_OCT_L_M_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\sharp\\\\16NOTE.bmp"</IMAGE>

    <IMAGE id = "IMG_1BY16_OCT_U_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\16NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY16_OCT_U_F">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\flat\\\\16NOTE_H.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY16_OCT_U_S">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\sharp\\\\16NOTE_H.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY8_OCT_L_M">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\4Rest.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY4_OCT_L_M">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\4Rest.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY16_OCT_L_M">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\8Rest.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY8_OCT_L_M">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\8Rest.bmp"</IMAGE>

    <IMAGE id = "IMG_3BY32_OCT_L_M">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\dot\\\\16Rest.bmp"</IMAGE>
    <IMAGE id = "IMG_1BY16_OCT_L_M">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\note\\\\16Rest.bmp"</IMAGE>

#ifdef __MMI_RING_COMPOSER_REPEAT__	
    <IMAGE id = "TOUCH_IMG_REPEAT_START">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_repeat_L.bmp"</IMAGE>
    <IMAGE id = "TOUCH_IMG_REPEAT_END">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_repeat_R.bmp"</IMAGE>
#endif 

    <IMAGE id = "IMG_RING_EVENTBL_ON">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\event\\\\BL.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_EVENTBL_OFF">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\event\\\\BLOFF.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_EVENTLED_ON">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\event\\\\LIGHT.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_EVENTLED_OFF">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\event\\\\LIGHT_N.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_EVENTVIB_ON">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\event\\\\VIB.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_EVENTVIB_OFF">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\event\\\\VIB_N.bmp"</IMAGE>
#ifdef __MMI_RING_COMPOSER_REPEAT__
    <IMAGE id = "IMG_RING_REPEAT_START">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R_Start.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_INFINITE">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R0.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_ONE">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R1.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_TWO">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R2.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_THREE">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R3.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_FOUR">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R4.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_FIVE">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R5.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_SIX">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R6.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_SEVEN">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R7.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_EIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R8.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_NINE">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R9.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_REPEAT_END">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\repeat\\\\R1.bmp"</IMAGE>
#endif 
    <IMAGE id = "TOUCH_IMG_1_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_WNOTE.bmp"</IMAGE>
    <IMAGE id = "TOUCH_IMG_1BY2_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_2NOTE.bmp"</IMAGE>
    <IMAGE id = "TOUCH_IMG_1BY4_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_4NOTE.bmp"</IMAGE>
    <IMAGE id = "TOUCH_IMG_1BY8_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_8NOTE.bmp"</IMAGE>
    <IMAGE id = "TOUCH_IMG_1BY16_OCT_L_M_N">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_16NOTE.bmp"</IMAGE>
    <IMAGE id = "TOUCH_IMG_1BY4_OCT_L_M">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_4Rest.bmp"</IMAGE>
    <IMAGE id = "TOUCH_IMG_1BY8_OCT_L_M">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_8Rest.bmp"</IMAGE>
    <IMAGE id = "TOUCH_IMG_1BY16_OCT_L_M">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_16Rest.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RNGC_HASH">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_HASH.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_P">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_DOWN.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_DOT">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\notes\\\\TH_DOT.bmp"</IMAGE>

    <IMAGE id = "IMG_TOUCH_RING_OK">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Symbol\\\\OK.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_NEXT">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Symbol\\\\NEXT.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_PREV">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Symbol\\\\PREV.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_EDIT">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Symbol\\\\EDIT.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_INSERT">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Symbol\\\\INSERT.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Symbol\\\\PLAY.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Symbol\\\\PAUSE.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_UP">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Symbol\\\\UP.bmp"</IMAGE>
    <IMAGE id = "IMG_TOUCH_RING_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Symbol\\\\DOWN.bmp"</IMAGE>

#ifdef __MMI_RING_COMPOSER_REPEAT__	
    <IMAGE id = "IMG_TOUCH_RING_SELECTION">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\ringbg\\\\TH_selectionarea_repeat.bmp"</IMAGE>
#elif (defined(__MMI_MAINLCD_128X160__) && !defined(__MMI_RNGC_ENABLE_INS_LED_NOTE__))
    <IMAGE id = "IMG_TOUCH_RING_SELECTION">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\ringbg\\\\TH_selectionarea_noled.bmp"</IMAGE>
#else
    <IMAGE id = "IMG_TOUCH_RING_SELECTION">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\ringbg\\\\TH_selectionarea.bmp"</IMAGE>
#endif 
    <IMAGE id = "IMG_TOUCH_RING_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\ringbg\\\\TH_toolbar.bmp"</IMAGE>

    <!------Instrument images------>
    <IMAGE id = "IMG_RING_INSTRU1">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\instrument\\\\R_DRUM.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_INSTRU2">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\instrument\\\\R_FLUTE.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_INSTRU3">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\instrument\\\\R_GUITR.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_INSTRU4">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\instrument\\\\R_HARM.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_INSTRU5">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\instrument\\\\R_MUSBOX.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_INSTRU6">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\instrument\\\\R_PIANO.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_INSTRU7">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\instrument\\\\R_SAX.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_INSTRU8">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\instrument\\\\R_VLION.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_INSTRU9">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\instrument\\\\R_TRUM.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_INSTRU10">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\instrument\\\\R_XYLO.bmp"</IMAGE>

#if (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
    <IMAGE id = "IMG_RING_INSTRU_LEFT_ARROW_UP">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Arrow\\\\TH_L_UP.bmp"</IMAGE>
    <IMAGE id = "IMG_RING_INSTRU_RIGHT_ARROW_UP">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\Touch\\\\Arrow\\\\TH_R_UP.bmp"</IMAGE>
#endif 
    <IMAGE id = "IMG_MENU3103_RINGTONE_COMPOSER">CUST_IMG_PATH"\\\\MainLCD\\\\RingComposer\\\\SB_FRING.bmp"</IMAGE>

    <!------Menu resources------>
    
    
    <MENU id="MENU3103_RINGTONE_COMPOSER" type="APP_MAIN" str="STR_MENU3103_RINGTONE_COMPOSER" img="IMG_MENU3103_RINGTONE_COMPOSER" highlight="HighlightRngcMenu" 
     shortcut="ON" shortcut_img="IMG_MENU3103_RINGTONE_COMPOSER" launch="EntryRngcApp">
                   
    </MENU>
    
#if defined(__MMI_FILE_MANAGER__)        
        <MENU id="MENU_COMP_RINGTONE_COMP_SELMENU_1" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS" >
        /* Could write MENUITEM in menu directly */
#ifdef __PLUTO_MMI_PACKAGE__
        <MENUITEM_ID>@OID:MENU_ID_FMGR_AUD_OPTION_PLAY</MENUITEM_ID>
#endif        
        <MENUITEM id="MENU_COMP_RINGTONE_COMP_SELEDIT" str="STR_GLOBAL_EDIT" highlight="HighlightRngcEdit"/>
        <MENUITEM id="MENU_COMP_RINGTONE_COMP_SELADD" str="STR_GLOBAL_ADD" highlight="HighlightRngcAdd"/>
#ifdef __PLUTO_MMI_PACKAGE__        
        <MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_RENAME</MENUITEM_ID>
        <MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_DELETE</MENUITEM_ID>
        <MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_DELETE_ALL</MENUITEM_ID>
        <MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_FORWARD_USE</MENUITEM_ID>
        <MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND</MENUITEM_ID>        
#endif              
       </MENU>
#endif   

    
  
    <MENU id = "MENU_COMP_RINGTONE_COMP_ADDOPT" type = "OPTION" str = "@OID:STR_GLOBAL_OPTIONS" img = "@OID:IMG_GLOBAL_OPTIONS" highlight = "HighlightRngcCompToneOpt">
        <MENUITEM id = "MENU_COMP_RINGTONE_COMP_PLAY" str = "@OID:STR_GLOBAL_PLAY"/>
        <MENU id = "MENU_COMP_RINGTONE_COMP_PLAY_SPEED" type = "APP_SUB" str = "STR_COMP_RINGTONE_PLAY_SPEED" highlight = "HighlightRngcGenericOptHdlr" hint = "mmi_rngc_opt_hint_select_speed">
            <MENUITEM id = "MENU_COMP_RINGTONE_FAST" str = "STR_COMP_RINGTONE_FAST" img = "@OID:IMG_GLOBAL_L1"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_NORMAL" str = "STR_COMP_RINGTONE_NORMAL" img = "@OID:IMG_GLOBAL_L2"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_SLOW" str = "STR_COMP_RINGTONE_SLOW" img = "@OID:IMG_GLOBAL_L3"/>
        </MENU>
    
#ifdef __MMI_RING_COMPOSER_STYLE__
        <MENU id = "MENU_COMP_RINGTONE_COMP_PLAY_STYLE" type = "APP_SUB" str = "STR_COMP_RINGTONE_PLAY_STYLE" highlight = "HighlightRngcGenericOptHdlr" hint = "mmi_rngc_opt_hint_select_style">
            <MENUITEM id = "MENU_COMP_RINGTONE_STYLE_CONTINUOUS" str = "STR_COMP_RINGTONE_STYLE_CONTINUOUS" img = "@OID:IMG_GLOBAL_L1"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_STYLE_NORMAL" str = "STR_COMP_RINGTONE_STYLE_NORMAL" img = "@OID:IMG_GLOBAL_L2"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_STYLE_STACCATO" str = "STR_COMP_RINGTONE_STYLE_STACCATO" img = "@OID:IMG_GLOBAL_L3"/>
        </MENU>
#endif 
#if defined( DSP_WT_SYN ) && (defined(WT150K) || defined(WT100K) || defined(WT70K))
        <MENU id = "MENU_COMP_RINGTONE_COMP_SEL_INST" type = "APP_SUB" str = "STR_COMP_RINGTONE_SEL_INST" highlight = "HighlightRngcGenericOptHdlr" hint = "mmi_rngc_opt_hint_select_inst">
            <MENUITEM id = "MENU_COMP_RINGTONE_PIANO" str = "STR_COMP_RINGTONE_PIANO" img = "@OID:IMG_GLOBAL_L1"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_GUITAR" str = "STR_COMP_RINGTONE_GUITAR" img = "@OID:IMG_GLOBAL_L2"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_VIOLIN" str = "STR_COMP_RINGTONE_VIOLIN" img = "@OID:IMG_GLOBAL_L3"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_SAXOPHONE" str = "STR_COMP_RINGTONE_SAXOPHONE" img = "@OID:IMG_GLOBAL_L4"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_STEELDRUMS" str = "STR_COMP_RINGTONE_STEELDRUMS" img = "@OID:IMG_GLOBAL_L5"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_FLUTE" str = "STR_COMP_RINGTONE_FLUTE" img = "@OID:IMG_GLOBAL_L6"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_HARMONICA" str = "STR_COMP_RINGTONE_HARMONICA" img = "@OID:IMG_GLOBAL_L7"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_TRUMPET" str = "STR_COMP_RINGTONE_TRUMPET" img = "@OID:IMG_GLOBAL_L8"/>
        </MENU>
#elif  (defined( DSP_WT_SYN ) && defined(WT20K))
        <MENU id = "MENU_COMP_RINGTONE_COMP_SEL_INST" type = "APP_SUB" str = "STR_COMP_RINGTONE_SEL_INST" highlight = "HighlightRngcGenericOptHdlr">
            <MENUITEM id = "MENU_COMP_RINGTONE_GUITAR" str = "STR_COMP_RINGTONE_GUITAR" img = "@OID:IMG_GLOBAL_L1"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_VIOLIN" str = "STR_COMP_RINGTONE_VIOLIN" img = "@OID:IMG_GLOBAL_L2"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_FLUTE" str = "STR_COMP_RINGTONE_FLUTE" img = "@OID:IMG_GLOBAL_L3"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_TRUMPET" str = "STR_COMP_RINGTONE_TRUMPET" img = "@OID:IMG_GLOBAL_L4"/>
        </MENU>
#else
        <MENU id = "MENU_COMP_RINGTONE_COMP_SEL_INST" type = "APP_SUB" str = "STR_COMP_RINGTONE_SEL_INST" highlight = "HighlightRngcGenericOptHdlr">
            <MENUITEM id = "MENU_COMP_RINGTONE_PIANO" str = "STR_COMP_RINGTONE_PIANO" img = "@OID:IMG_GLOBAL_L1"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_GUITAR" str = "STR_COMP_RINGTONE_GUITAR" img = "@OID:IMG_GLOBAL_L2"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_VIOLIN" str = "STR_COMP_RINGTONE_VIOLIN" img = "@OID:IMG_GLOBAL_L3"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_SAXOPHONE" str = "STR_COMP_RINGTONE_SAXOPHONE" img = "@OID:IMG_GLOBAL_L4"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_STEELDRUMS" str = "STR_COMP_RINGTONE_STEELDRUMS" img = "@OID:IMG_GLOBAL_L5"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_FLUTE" str = "STR_COMP_RINGTONE_FLUTE" img = "@OID:IMG_GLOBAL_L6"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_HARMONICA" str = "STR_COMP_RINGTONE_HARMONICA" img = "@OID:IMG_GLOBAL_L7"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_TRUMPET" str = "STR_COMP_RINGTONE_TRUMPET" img = "@OID:IMG_GLOBAL_L8"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_MUSICBOX" str = "STR_COMP_RINGTONE_MUSICBOX" img = "@OID:IMG_GLOBAL_L9"/>
            <MENUITEM id = "MENU_COMP_RINGTONE_XYLOPHONE" str = "STR_COMP_RINGTONE_XYLOPHONE" img = "@OID:IMG_GLOBAL_L10"/>
        </MENU>
#endif 
        <MENUITEM id = "MENU_COMP_RINGTONE_COMP_SAVE" str = "@OID:STR_GLOBAL_SAVE"/>
    </MENU>

    <SCREEN id = "SCR_COMPOSE_RINGTONE"/>
    <SCREEN id = "SCR_ID_RNGC_MAIN"/>
    <SCREEN id = "SCR_COMPOSE_RINGTONE_OPTION"/>
    <SCREEN id = "SCR_COMPOSE_RINGTONE_OPTION_PLAY"/>
    <SCREEN id = "SCR_COMP_RINGTONE_ADD_OPT"/>
    <SCREEN id = "SCR_COMP_RINGTONE_SPEED"/>
    <SCREEN id = "SCR_COMP_RINGTONE_STYLE"/>
    <SCREEN id = "SCR_COMP_RINGTONE_INSTRUMENT"/>
    <SCREEN id = "SCR_COMP_RINGTONE_SAVEFILE"/>
    <SCREEN id = "SCR_COMP_RINGTONE_SAVE_OPT"/>
    <SCREEN id = "SCR_COMPOSER_ENGINE"/>
    <SCREEN id = "SCR_COMPOSE_RINGTONE_DELETE"/>
    <SCREEN id = "SCR_COMPOSE_RINGTONE_DELETE_CNF"/>
    <SCREEN id = "SCR_COMP_RINGTONE_SAVE_CNF"/>

    /* Callback manager*/
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="mmi_rngcomposer_notify_hdlr"/>

</APP>
#endif 
