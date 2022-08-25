#include "MMI_features.h"
#include "custresdef.h"
#include "AMSwitch.h"
#include "vmswitch.h"
#include "GlobalResDef.h"
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_AM">
#ifdef __PLUTO_MMI_PACKAGE__
#ifdef __MRE_AM__
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    #if defined( __PLUTO_MMI_PACKAGE__ )&& defined(__MMI_FILE_MANAGER__) && !defined(__IOT__)
    <INCLUDE file="mmi_rp_app_filemanager_def.h"/>
    #endif

    <!-----------------------------------------------------AM Shortcut app Resource Area------------------------------------------------------>
    #ifdef MMI_AM_SC_APP_AS
    <STRING id="STR_ID_AM_APP_NAME_AS"/>
    <IMAGE id="IMG_ID_AM_APP_AS" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_AS.gif"</IMAGE>
    #endif
   
    #ifdef MMI_AM_SC_APP_QQBROWSER
    <STRING id="STR_ID_AM_APP_NAME_QQBROWSER"/>
    <IMAGE id="IMG_ID_AM_APP_QQBROWSER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_QQbrowser.gif"</IMAGE>
    #endif
   
    #ifdef MMI_AM_SC_APP_QQ
    <STRING id="STR_ID_AM_APP_NAME_QQ"/>
    <IMAGE id="IMG_ID_AM_APP_QQ" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #ifdef MMI_AM_SC_APP_QQ_2010
    <STRING id="STR_ID_AM_APP_NAME_QQ_2010"/>
    <IMAGE id="IMG_ID_AM_APP_QQ_2010" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif
   
    #ifdef MMI_AM_SC_APP_WLOL
    <STRING id="STR_ID_AM_APP_NAME_WLOL"/>
    <IMAGE id="IMG_ID_AM_APP_WLOL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_WulinOL.gif"</IMAGE>
    #endif
   
    #ifdef MMI_AM_SC_APP_MOBILEKK
    <STRING id="STR_ID_AM_APP_NAME_MOBILEKK"/>
    <IMAGE id="IMG_ID_AM_APP_MOBILEKK" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_MobileKK.gif"</IMAGE>
    #endif
   
    #ifdef MMI_AM_SC_APP_STOCKSTAR
    <STRING id="STR_ID_AM_APP_NAME_STOCKSTAR"/>
    <IMAGE id="IMG_ID_AM_APP_STOCKSTAR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_StockStar.gif"</IMAGE>
    #endif
    
    #ifdef MMI_AM_SC_APP_FETION
    <STRING id="STR_ID_AM_APP_NAME_FETION"/>
    <IMAGE id="IMG_ID_AM_APP_FETION" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Fetion.gif"</IMAGE>
    #endif
   
    #ifdef MMI_AM_SC_APP_QQLANDLORD
    <STRING id="STR_ID_AM_APP_NAME_QQLANDLORD"/>
    <IMAGE id="IMG_ID_AM_APP_QQLANDLORD" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_QQLandlord.gif"</IMAGE>
    #endif
    
    #ifdef MMI_AM_SC_APP_MSN
    <STRING id="STR_ID_AM_APP_NAME_MSN"/>
    <IMAGE id="IMG_ID_AM_APP_MSN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_MSN.gif"</IMAGE>
    #endif

    #if defined (MMI_AM_SC_APP_OPERA) || defined (__MMI_MRE_APP_OPERA__) ||defined (__MMI_MRE_APP_OPERA_MINI_V6__)
    <STRING id="STR_ID_AM_APP_NAME_OPERA"/>
    <IMAGE id="IMG_ID_AM_APP_OPERA" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif
   
    #ifdef MMI_AM_SC_APP_100TV
    <STRING id="STR_ID_AM_APP_NAME_100TV"/>
    <IMAGE id="IMG_ID_AM_APP_100TV" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_100TV.gif"</IMAGE>
    #endif
   
    #ifdef MMI_AM_SC_APP_AIPIM
    <STRING id="STR_ID_AM_APP_NAME_AIPIM"/>
    <IMAGE id="IMG_ID_AM_APP_AIPIM" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_AIPIM.gif"</IMAGE>
    #endif
    
    #ifdef MMI_AM_SC_APP_LUUTOO
    <STRING id="STR_ID_AM_APP_NAME_LUUTOO"/>
    <IMAGE id="IMG_ID_AM_APP_LUUTOO" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Luutoo.gif"</IMAGE>
    #endif
    
    #ifdef MMI_AM_SC_APP_SHANGMAIL
    <STRING id="STR_ID_AM_APP_NAME_PUSHMAIL"/>
    <IMAGE id="IMG_ID_AM_APP_PUSHMAIL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Pushmail.gif"</IMAGE>
   #endif
    /***********************************************/
    #ifdef __MMI_MRE_APP_CALCULATOR__
    <STRING id="STR_ID_AM_APP_NAME_CALCULATOR"/>
    <IMAGE id="IMG_ID_AM_APP_CALCULATOR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #ifdef __MMI_MRE_APP_CONVERTER__
    <STRING id="STR_ID_AM_APP_NAME_CONVERTER"/>
    <IMAGE id="IMG_ID_AM_APP_CONVERTER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #ifdef __MMI_MRE_APP_HEALTH__
    <STRING id="STR_ID_AM_APP_NAME_HEALTH"/>
    <IMAGE id="IMG_ID_AM_APP_HEALTH" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #ifdef __MMI_MRE_APP_STOPWATCH__
    <STRING id="STR_ID_AM_APP_NAME_STOPWATCH"/>
    <IMAGE id="IMG_ID_AM_APP_STOPWATCH" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #ifdef __MMI_MRE_APP_ZAKAT__
    <STRING id="STR_ID_AM_APP_NAME_ZAKAT"/>
    <IMAGE id="IMG_ID_AM_APP_ZAKAT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif
    /***********************************************/
    #ifdef __MMI_MRE_APP_ZY_EBOOK__
    <STRING id="STR_ID_AM_APP_NAME_ZY_EBOOK"/>
    <IMAGE id="IMG_ID_AM_APP_EBOOK" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #if defined(__MMI_MRE_GAME_HAPPYWAR_EN__) || defined(__MMI_MRE_GAME_HAPPYWAR_CHS__)
    <STRING id="STR_ID_AM_APP_NAME_HAPPYWAR"/>
    <IMAGE id="IMG_ID_AM_APP_HAPPYWAR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

   #if defined(__MMI_MRE_GAME_EGYPTCODE_EN__) || defined(__MMI_MRE_GAME_EGYPTCODE_CHS__)
    <STRING id="STR_ID_AM_APP_NAME_EGYPTCODE"/>
    <IMAGE id="IMG_ID_AM_APP_EGYPTCODE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #if defined(__MMI_MRE_GAME_KINGCOMBAT_EN__) || defined(__MMI_MRE_GAME_KINGCOMBAT_CHS__)
    <STRING id="STR_ID_AM_APP_NAME_KINGCOMBAT"/>
    <IMAGE id="IMG_ID_AM_APP_KINGCOMBAT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #if defined(__MMI_MRE_GAME_GOLDMINER_EN__) || defined(__MMI_MRE_GAME_GOLDMINER_CHS__)
    <STRING id="STR_ID_AM_APP_NAME_GOLDMINER"/>
    <IMAGE id="IMG_ID_AM_APP_GOLDMINER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif
    /***********************************************/
    #if defined(__MMI_MRE_GAME_MOTO_EN__) || defined(__MMI_MRE_GAME_MOTO_CHS__)
    <STRING id="STR_ID_AM_APP_NAME_MOTO"/>
    <IMAGE id="IMG_ID_AM_APP_MOTO" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #if defined(__MMI_MRE_GAME_GIRLSLOT_EN__) || defined(__MMI_MRE_GAME_GIRLSLOT_CHS__)
    <STRING id="STR_ID_AM_APP_NAME_GIRLSLOT"/>
    <IMAGE id="IMG_ID_AM_APP_GIRLSLOT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #if defined(__MMI_MRE_GAME_PARKOUR_EN__) || defined(__MMI_MRE_GAME_PARKOUR_CHS__)
    <STRING id="STR_ID_AM_APP_NAME_PARKOUR"/>
    <IMAGE id="IMG_ID_AM_APP_PARKOUR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

    #if defined(__MMI_MRE_GAME_TEARDRESS_EN__) || defined(__MMI_MRE_GAME_TEARDRESS_CHS__)
    <STRING id="STR_ID_AM_APP_NAME_TEARDRESS"/>
    <IMAGE id="IMG_ID_AM_APP_TEARDRESS" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif

     #if defined(__MMI_MRE_GAME_HAPPYEGG_EN__) || defined(__MMI_MRE_GAME_HAPPYEGG_CHS__)
    <STRING id="STR_ID_AM_APP_NAME_HAPPYEGG"/>
    <IMAGE id="IMG_ID_AM_APP_HAPPYEGG" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    #endif   
  
    /***********************************************/

    /*******************************************************************************************************************************
     *  Following this period is for defined the reource of the MRE Application.
     ******************************************************************************************************************************/
#ifdef __MMI_MRE_CALCULATOR__
    /* MRE Calculator Application resource */

    /* When you use any ID of other module, you need to add
      that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_CALC_MENU"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_ID_CALC_MENU_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\SB_OCACU.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    //<MENUITEM id="EXTRA_CALCULATOR_MENU" str="STR_ID_CALC_MENU" highlight="HighlightCalcMenu"/>
    <MENU id="EXTRA_CALCULATOR_MENU" str="STR_ID_CALC_MENU" img="IMG_ID_CALC_MENU_ICON" highlight="HighlightCalcMenu" 
    shortcut="ON" shortcut_img="IMG_ID_CALC_MENU_ICON" launch="CalcPreEntryApp">
    </MENU>
   
#endif /* __MMI_MRE_CALCULATOR__ */

#ifdef __MMI_MRE_WORLD_CLOCK__
    /* MRE Worldclock Application resource */

    /* When you use any ID of other module, you need to add
      that header file here, so that Resgen can find the ID */
      
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="ORGANIZER_MENU_WORLDCLOCK_STRINGID"/>
    <STRING id="STR_WORLD_CLOCK_TITLE"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="ORGANIZER_MENU_WORLDCLOCK_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Worldclock\\\\SB_WORLD.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Menu Id and path of you Application , you can use compile option in Path, but need out of "" */
    <MENU id="ORGANIZER_WORLDCLOCK_MENU" type="APP_SUB" str="ORGANIZER_MENU_WORLDCLOCK_STRINGID" img="ORGANIZER_MENU_WORLDCLOCK_IMAGEID" highlight="HighlightWCMenu">
        <MENUITEM id="MITEM_WORLDCLOCK_BROWSECITY" str="STR_WORLD_CLOCK_TITLE" highlight="HighlightWcBrowseCity"></MENUITEM>
    </MENU> 

#endif /* __MMI_MRE_WORLD_CLOCK__ */

#endif /* __MRE_AM__ */

#ifdef __MMI_MRE_APP_YAHOOCRICKET__
    <STRING id="STR_ID_AM_APP_NAME_YAHOOCRICKET"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOOCRICKET" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Yahoo_Cricket.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_QQBROWSER__
    <STRING id="STR_ID_AM_APP_NAME_QQBROWSER"/>
    <IMAGE id="IMG_ID_AM_APP_QQBROWSER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_QQbrowser.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_RENREN__
    <STRING id="STR_ID_AM_APP_NAME_RENREN"/>
    <IMAGE id="IMG_ID_AM_APP_RENREN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Renren.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_KAIXIN__
    <STRING id="STR_ID_AM_APP_NAME_KAIXIN"/>
    <IMAGE id="IMG_ID_AM_APP_KAIXIN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Kaixin.gif"</IMAGE>
#endif
    
#ifdef __MMI_MRE_APP_YOUKU__
    <STRING id="STR_ID_AM_APP_NAME_YOUKU"/>
    <IMAGE id="IMG_ID_AM_APP_YOUKU" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Youku.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_SC__
    <STRING id="STR_ID_AM_APP_NAME_FRUITNINJA_SC"/>
    <IMAGE id="IMG_ID_AM_APP_FRUITNINJA_SC" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_FruitNinja_sc.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_EN__
    <STRING id="STR_ID_AM_APP_NAME_FRUITNINJA_EN"/>
    <IMAGE id="IMG_ID_AM_APP_FRUITNINJA_EN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_FruitNinja_en.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_SC__
    <STRING id="STR_ID_AM_APP_NAME_FISHINGFUN_SC"/>
    <IMAGE id="IMG_ID_AM_APP_FISHINGFUN_SC" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_FishingFun_sc.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_EN__
    <STRING id="STR_ID_AM_APP_NAME_FISHINGFUN_EN"/>
    <IMAGE id="IMG_ID_AM_APP_FISHINGFUN_EN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_FishingFun_en.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_SC__
    <STRING id="STR_ID_AM_APP_NAME_ANGRYBIRD_SC"/>
    <IMAGE id="IMG_ID_AM_APP_ANGRYBIRD_SC" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_AngryBird_sc.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_EN__
    <STRING id="STR_ID_AM_APP_NAME_ANGRYBIRD_EN"/>
    <IMAGE id="IMG_ID_AM_APP_ANGRYBIRD_EN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_AngryBird_en.gif"</IMAGE>
#endif
    
//#ifdef __MMI_MRE_APP_FBLITE__
#if defined(__MMI_MRE_APP_FBLITE__) || defined(__MMI_MRE_APP_FBLITEV11__) || defined(__MMI_MRE_APP_FACEBOOK_V2__)|| defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD__)
    <STRING id="STR_ID_AM_APP_NAME_FBLITE"/>
    <IMAGE id="IMG_ID_AM_APP_FBLITE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#if defined(__MMI_MRE_APP_FACEBOOK_V2__)|| defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD__)
    <STRING id="STR_ID_AM_APP_NAME_FBV2_MESSENGER"/>
    <IMAGE id="IMG_ID_AM_APP_FBLITE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_TWITTER__
    <STRING id="STR_ID_AM_APP_NAME_TWITTER"/>
    <IMAGE id="IMG_ID_AM_APP_TWITTER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_YOUTUBE__
    <STRING id="STR_ID_AM_APP_NAME_YOUTUBE"/>
    <IMAGE id="IMG_ID_AM_APP_YOUTUBE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#if (defined (__MMI_MRE_APP_YAHOOMV1__) || defined(__MMI_MRE_APP_YAHOOMV2__))
    <STRING id="STR_ID_AM_APP_NAME_YAHOO"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOO" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_YAHOOFINANCE__
    <STRING id="STR_ID_AM_APP_NAME_YAHOOFINANCE"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOOFINANCE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_YAHOOWEATHER__ 
    <STRING id="STR_ID_AM_APP_NAME_YAHOOWEATHER"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOOWEATHER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_YAHOONEWS__
    <STRING id="STR_ID_AM_APP_NAME_YAHOONEWS"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOONEWS" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_OPERA__
    <STRING id="STR_ID_AM_APP_NAME_OPERA"/>
    <IMAGE id="IMG_ID_AM_APP_OPERA" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_OPERA_MINI_V6__
    <STRING id="STR_ID_AM_APP_NAME_OPERA_MINI_V6"/>
    <IMAGE id="IMG_ID_AM_APP_OPERA_MINI_V6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

/*<---------------------------- ADD 3GT Game START ---------------------------->*/

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_ENG__
	<STRING id="STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_ENG"/>
    <IMAGE id="IMG_ID_AM_APP_BOWLING_ENG" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHS__
	<STRING id="STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_CHS"/>
	<IMAGE id="IMG_ID_AM_APP_BOWLING_CHS" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHT__
	<STRING id="STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_CHT"/>
    <IMAGE id="IMG_ID_AM_APP_BOWLING_CHT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_DANDELION__
    <STRING id="STR_ID_AM_APP_NAME_3GT_GAME_DANDELION"/>
    <IMAGE id="IMG_ID_AM_APP_DANDELION" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#if defined(__MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__) || defined(__MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__) || defined(__MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__)
    <STRING id="STR_ID_AM_APP_NAME_3GT_RASH_MOTOR"/>
    <IMAGE id="IMG_ID_AM_APP_3GT_RASH_MOTOR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif

#if defined(__MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__) || defined(__MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__) || defined(__MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__)
    <STRING id="STR_ID_AM_APP_NAME_3GT_BALANCE_BALL"/>
    <IMAGE id="IMG_ID_AM_APP_3GT_BALANCE_BALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
#endif
/*<---------------------------- ADD 3GT Game END ------------------------------>*/

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE1__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE1__)
	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_Asphalt6.gif"</IMAGE>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BrainChallenge3.gif"</IMAGE>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BlockBreaker3.gif"</IMAGE>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_AssassinsCreed3.gif"</IMAGE>
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE2__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE2__)
	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_Asphalt6.gif"</IMAGE>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BrainChallenge3.gif"</IMAGE>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BlockBreaker3.gif"</IMAGE>
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE3__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE3__)
	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_Asphalt6.gif"</IMAGE>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BlockBreaker3.gif"</IMAGE>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_AssassinsCreed3.gif"</IMAGE>
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE4__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE4__)
	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_Asphalt6.gif"</IMAGE>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BrainChallenge3.gif"</IMAGE>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_AssassinsCreed3.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_2ND_PACKAGE__
	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_GLIVE"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_GLIVE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_GLive.gif"</IMAGE>
	
	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_MC2"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_MC2" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_MC2.gif"</IMAGE>
#endif

#if defined (__MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250__) || defined (__MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250__)
	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_Asphalt6.gif"</IMAGE>
	
	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_GLIVE"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_GLIVE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_GLive.gif"</IMAGE>
#endif

#if defined(__MMI_MRE_APP_SINA_WEIBO__) && (__MMI_MRE_APP_SINA_WEIBO__ == __MRE_APP_DEFAULT__)
    <STRING id="STR_ID_AM_APP_NAME_SINA_WEIBO"/>
    <IMAGE id="IMG_ID_AM_APP_SINA_WEIBO" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Sina_Weibo.gif"</IMAGE>
#endif


#ifdef __MRE_APP_LAUNCH__

#ifdef __MMI_MRE_APP_QQ2010__
    <STRING id="STR_ID_AM_APP_NAME_QQ_2010"/>
    <IMAGE id="IMG_ID_AM_APP_QQ" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_QQ_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_QQ_2010" str="STR_ID_AM_APP_NAME_QQ_2010" img="IMG_ID_MRE_APP_QQ_SMALL" highlight="mmi_am_la_highlight_QQ_2010"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_QQBROWSER__
    <STRING id="STR_ID_AM_APP_NAME_QQBROWSER"/>
    <IMAGE id="IMG_ID_AM_APP_QQBROWSER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_QQbrowser.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_QQBROWSER_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_QQBROWSER" str="STR_ID_AM_APP_NAME_QQBROWSER" img="IMG_ID_MRE_APP_QQBROWSER_SMALL" highlight="mmi_am_la_highlight_QQBrowser"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_RENREN__
    <STRING id="STR_ID_AM_APP_NAME_RENREN"/>
    <IMAGE id="IMG_ID_AM_APP_RENREN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Renren.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_RENREN_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_RENREN" str="STR_ID_AM_APP_NAME_RENREN" img="IMG_ID_MRE_APP_RENREN_SMALL" highlight="mmi_am_la_highlight_renren"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_KAIXIN__
    <STRING id="STR_ID_AM_APP_NAME_KAIXIN"/>
    <IMAGE id="IMG_ID_AM_APP_KAIXIN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Kaixin.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_KAIXIN_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_Kaixin_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_KAIXIN" str="STR_ID_AM_APP_NAME_KAIXIN" img="IMG_ID_MRE_APP_KAIXIN_SMALL" highlight="mmi_am_la_highlight_kaixin"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_YOUKU__
    <STRING id="STR_ID_AM_APP_NAME_YOUKU"/>
    <IMAGE id="IMG_ID_AM_APP_KYOUKU" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Youku.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_YOUKU_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_Youku_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_YOUKU" str="STR_ID_AM_APP_NAME_YOUKU" img="IMG_ID_MRE_APP_YOUKU_SMALL" highlight="mmi_am_la_highlight_youku"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_SC__
    <STRING id="STR_ID_AM_APP_NAME_FRUITNINJA_SC"/>
    <IMAGE id="IMG_ID_AM_APP_FRUITNINJA_SC" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_FruitNinja_sc.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_FRUITNINJA_SC_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_FruitNinja_sc_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_FRUITNINJA_SC" str="STR_ID_AM_APP_NAME_FRUITNINJA_SC" img="IMG_ID_MRE_APP_FRUITNINJA_SC_SMALL" highlight="mmi_am_la_highlight_fruitninja_sc"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_EN__
    <STRING id="STR_ID_AM_APP_NAME_FRUITNINJA_EN"/>
    <IMAGE id="IMG_ID_AM_APP_FRUITNINJA_EN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_FruitNinja_en.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_FRUITNINJA_EN_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_YFruitNinja_en_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_FRUITNINJA_EN" str="STR_ID_AM_APP_NAME_FRUITNINJA_EN" img="IMG_ID_MRE_APP_FRUITNINJA_EN_SMALL" highlight="mmi_am_la_highlight_fruitninja_en"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_SC__
    <STRING id="STR_ID_AM_APP_NAME_FISHINGFUN_SC"/>
    <IMAGE id="IMG_ID_AM_APP_FISHINGFUN_SC" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_FishingFun_sc.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_FISHINGFUN_SC_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_FishingFun_sc_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_FISHINGFUN_SC" str="STR_ID_AM_APP_NAME_FISHINGFUN_SC" img="IMG_ID_MRE_APP_FISHINGFUN_SC_SMALL" highlight="mmi_am_la_highlight_fishingfun_sc"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_EN__
    <STRING id="STR_ID_AM_APP_NAME_FISHINGFUN_EN"/>
    <IMAGE id="IMG_ID_AM_APP_FISHINGFUN_EN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_FishingFun_en.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_FISHINGFUN_EN_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_FishingFun_en_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_FISHINGFUN_EN" str="STR_ID_AM_APP_NAME_FISHINGFUN_EN" img="IMG_ID_MRE_APP_FISHINGFUN_EN_SMALL" highlight="mmi_am_la_highlight_fishingbun_en"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_SC__
    <STRING id="STR_ID_AM_APP_NAME_ANGRYBIRD_SC"/>
    <IMAGE id="IMG_ID_AM_APP_ANGRYBIRD_SC" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_AngryBird_sc.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_ANGRYBIRD_SC_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_AngryBird_sc_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_ANGRYBIRD_SC" str="STR_ID_AM_APP_NAME_ANGRYBIRD_SC" img="IMG_ID_MRE_APP_ANGRYBIRD_SC_SMALL" highlight="mmi_am_la_highlight_angrybird_sc"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_EN__
    <STRING id="STR_ID_AM_APP_NAME_ANGRYBIRD_EN"/>
    <IMAGE id="IMG_ID_AM_APP_ANGRYBIRD_EN" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_AngryBird_en.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_ANGRYBIRD_EN_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_AngryBird_en_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_ANGRYBIRD_EN" str="STR_ID_AM_APP_NAME_ANGRYBIRD_EN" img="IMG_ID_MRE_APP_ANGRYBIRD_EN_SMALL" highlight="mmi_am_la_highlight_angrybird_en"></MENUITEM>
#endif

#if (defined (__MMI_MRE_APP_YAHOOMV1__) || defined(__MMI_MRE_APP_YAHOOMV2__))
    <STRING id="STR_ID_AM_APP_NAME_YAHOO"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOO" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_YAHOO_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_YAHOO" str="STR_ID_AM_APP_NAME_YAHOO" img="IMG_ID_MRE_APP_YAHOO_SMALL" highlight="mmi_am_la_highlight_Yahoo"></MENUITEM>
#endif
    
//#ifdef __MMI_MRE_APP_FBLITE__
#if defined(__MMI_MRE_APP_FBLITE__) || defined(__MMI_MRE_APP_FBLITEV11__)
    <STRING id="STR_ID_AM_APP_NAME_FBLITE"/>
    <IMAGE id="IMG_ID_AM_APP_FBLITE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_FBLITE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_FBLITE" str="STR_ID_AM_APP_NAME_FBLITE" img="IMG_ID_MRE_APP_FBLITE_SMALL" highlight="mmi_am_la_highlight_fblite"></MENUITEM>    
#endif
//#ifdef __MMI_MRE_APP_FACEBOOK_V2__
#if defined(__MMI_MRE_APP_FACEBOOK_V2__) || defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD__)
    <STRING id="STR_ID_AM_APP_NAME_FBLITE"/>
    <IMAGE id="IMG_ID_AM_APP_FBLITE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_FBLITE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_FACEBOOK_V2" str="STR_ID_AM_APP_NAME_FBLITE" img="IMG_ID_MRE_APP_FBLITE_SMALL" highlight="mmi_am_la_highlight_facebook_v2"></MENUITEM>    
#endif

#if defined(__MMI_MRE_APP_FACEBOOK_V2__) || defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD__)
    <STRING id="STR_ID_AM_APP_NAME_FBV2_MESSENGER"/>
    <IMAGE id="IMG_ID_AM_APP_FBLITE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_FBLITE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_FACEBOOK_V2_MESSENGER" str="STR_ID_AM_APP_NAME_FBV2_MESSENGER" img="IMG_ID_MRE_APP_FBLITE_SMALL" highlight="mmi_am_la_highlight_facebook_v2_messenger"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_TWITTER__
    <STRING id="STR_ID_AM_APP_NAME_TWITTER"/>
    <IMAGE id="IMG_ID_AM_APP_TWITTER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_TWITTER_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_TWITTER" str="STR_ID_AM_APP_NAME_TWITTER" img="IMG_ID_MRE_APP_TWITTER_SMALL" highlight="mmi_am_la_highlight_twitter"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_YOUTUBE__
    <STRING id="STR_ID_AM_APP_NAME_YOUTUBE"/>
    <IMAGE id="IMG_ID_AM_APP_YOUTUBE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_YOUTUBE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_YOUTUBE" str="STR_ID_AM_APP_NAME_YOUTUBE" img="IMG_ID_MRE_APP_YOUTUBE_SMALL" highlight="mmi_am_la_highlight_YouTube"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_YAHOOFINANCE__
    <STRING id="STR_ID_AM_APP_NAME_YAHOOFINANCE"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOOFINANCE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_YAHOOFINANCE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_YAHOOFINANCE" str="STR_ID_AM_APP_NAME_YAHOOFINANCE" img="IMG_ID_MRE_APP_YAHOOFINANCE_SMALL" highlight="mmi_am_la_highlight_yahoofinance"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_YAHOOWEATHER__ 
    <STRING id="STR_ID_AM_APP_NAME_YAHOOWEATHER"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOOWEATHER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_YAHOOWEATHER_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_YAHOOWEATHER" str="STR_ID_AM_APP_NAME_YAHOOWEATHER" img="IMG_ID_MRE_APP_YAHOOWEATHER_SMALL" highlight="mmi_am_la_highlight_yahooweather"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_YAHOONEWS__
    <STRING id="STR_ID_AM_APP_NAME_YAHOONEWS"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOONEWS" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_YAHOONEWS_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_YAHOONEWS" str="STR_ID_AM_APP_NAME_YAHOONEWS" img="IMG_ID_MRE_APP_YAHOONEWS_SMALL" highlight="mmi_am_la_highlight_yahoonews"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_YAHOOCRICKET__
    <STRING id="STR_ID_AM_APP_NAME_YAHOOCRICKET"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOOCRICKET" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Yahoo_Cricket.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_YAHOOCRICKET_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_YAHOOCRICKET" str="STR_ID_AM_APP_NAME_YAHOOCRICKET" img="IMG_ID_MRE_APP_YAHOOCRICKET_SMALL" highlight="mmi_am_la_highlight_yahoocricket"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_OPERA__
    <STRING id="STR_ID_AM_APP_NAME_OPERA"/>
    <IMAGE id="IMG_ID_AM_APP_OPERA" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_OPERA_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_OPERA" str="STR_ID_AM_APP_NAME_OPERA" img="IMG_ID_MRE_APP_OPERA_SMALL" highlight="mmi_am_la_highlight_opera"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_OPERA_MINI_V6__
    <STRING id="STR_ID_AM_APP_NAME_OPERA_MINI_V6"/>
    <IMAGE id="IMG_ID_AM_APP_OPERA_MINI_V6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_OPERA_MINI_V6_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_OPERA_MINI_V6" str="STR_ID_AM_APP_NAME_OPERA_MINI_V6" img="IMG_ID_MRE_APP_OPERA_MINI_V6_SMALL" highlight="mmi_am_la_highlight_opera_min_v6"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_YAHOO__
    <STRING id="STR_ID_AM_APP_NAME_YAHOO"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOO" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_YAHOO_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_YAHOO" str="STR_ID_AM_APP_NAME_YAHOO" img="IMG_ID_MRE_APP_YAHOO_SMALL" highlight="mmi_am_la_highlight_Yahoo"></MENUITEM>
#endif


/***********************************************/
#ifdef __MMI_MRE_APP_CALCULATOR__
    <STRING id="STR_ID_AM_APP_NAME_CALCULATOR"/>
    <IMAGE id="IMG_ID_AM_APP_CALCULATOR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_CALCULATOR_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_APP_CALCULATOR" str="STR_ID_AM_APP_NAME_CALCULATOR" img="IMG_ID_MRE_APP_CALCULATOR_SMALL" highlight="mmi_am_la_highlight_CALCULATOR"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_CONVERTER__
    <STRING id="STR_ID_AM_APP_NAME_CONVERTER"/>
    <IMAGE id="IMG_ID_AM_APP_CONVERTER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_CONVERTER_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_APP_CONVERTER" str="STR_ID_AM_APP_NAME_CONVERTER" img="IMG_ID_MRE_APP_CONVERTER_SMALL" highlight="mmi_am_la_highlight_CONVERTER"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_HEALTH__
    <STRING id="STR_ID_AM_APP_NAME_HEALTH"/>
    <IMAGE id="IMG_ID_AM_APP_HEALTH" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_HEALTH_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_APP_HEALTH" str="STR_ID_AM_APP_NAME_HEALTH" img="IMG_ID_MRE_APP_HEALTH_SMALL" highlight="mmi_am_la_highlight_HEALTH"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_STOPWATCH__
    <STRING id="STR_ID_AM_APP_NAME_STOPWATCH"/>
    <IMAGE id="IMG_ID_AM_APP_STOPWATCH" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_STOPWATCH_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_STOPWATCH" str="STR_ID_AM_APP_NAME_STOPWATCH" img="IMG_ID_MRE_APP_STOPWATCH_SMALL" highlight="mmi_am_la_highlight_STOPWATCH"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_ZAKAT__
    <STRING id="STR_ID_AM_APP_NAME_ZAKAT"/>
    <IMAGE id="IMG_ID_AM_APP_ZAKAT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_ZAKAT_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_ZAKAT" str="STR_ID_AM_APP_NAME_ZAKAT" img="IMG_ID_MRE_APP_ZAKAT_SMALL" highlight="mmi_am_la_highlight_ZAKAT"></MENUITEM>    
#endif
/***********************************************/

#ifdef __MMI_MRE_APP_ZY_EBOOK__
    <STRING id="STR_ID_AM_APP_NAME_ZY_EBOOK"/>
    <IMAGE id="IMG_ID_AM_APP_EBOOK" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_EBOOK_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_ZY_EBOOK" str="STR_ID_AM_APP_NAME_ZY_EBOOK" img="IMG_ID_MRE_APP_EBOOK_SMALL" highlight="mmi_am_la_highlight_ZY_EBOOK"></MENUITEM>
#endif


#ifdef __MMI_MRE_GAME_HAPPYWAR_EN__
    <STRING id="STR_ID_AM_APP_NAME_HAPPYWAR"/>
    <IMAGE id="IMG_ID_AM_APP_HAPPYWAR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_HAPPYWAR_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_HAPPYWAR" str="STR_ID_AM_APP_NAME_HAPPYWAR" img="IMG_ID_MRE_APP_HAPPYWAR_SMALL" highlight="mmi_am_la_highlight_HAPPYWAR_EN"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_HAPPYWAR_CHS__
    <STRING id="STR_ID_AM_APP_NAME_HAPPYWAR"/>
    <IMAGE id="IMG_ID_AM_APP_HAPPYWAR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_HAPPYWAR_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_HAPPYWAR" str="STR_ID_AM_APP_NAME_HAPPYWAR" img="IMG_ID_MRE_APP_HAPPYWAR_SMALL" highlight="mmi_am_la_highlight_HAPPYWAR_CHS"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_EGYPTCODE_EN__
    <STRING id="STR_ID_AM_APP_NAME_EGYPTCODE"/>
    <IMAGE id="IMG_ID_AM_APP_EGYPTCODE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_EGYPTCODE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_EGYPTCODE" str="STR_ID_AM_APP_NAME_EGYPTCODE" img="IMG_ID_MRE_APP_EGYPTCODE_SMALL" highlight="mmi_am_la_highlight_EGYPTCODE_EN"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_EGYPTCODE_CHS__
    <STRING id="STR_ID_AM_APP_NAME_EGYPTCODE"/>
    <IMAGE id="IMG_ID_AM_APP_EGYPTCODE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_EGYPTCODE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_EGYPTCODE" str="STR_ID_AM_APP_NAME_EGYPTCODE" img="IMG_ID_MRE_APP_EGYPTCODE_SMALL" highlight="mmi_am_la_highlight_EGYPTCODE_CHS"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_EN__
    <STRING id="STR_ID_AM_APP_NAME_KINGCOMBAT"/>
    <IMAGE id="IMG_ID_AM_APP_KINGCOMBAT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_KINGCOMBAT_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_KINGCOMBAT" str="STR_ID_AM_APP_NAME_KINGCOMBAT" img="IMG_ID_MRE_APP_KINGCOMBAT_SMALL" highlight="mmi_am_la_highlight_KINGCOMBAT_EN"></MENUITEM>    
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_CHS__
    <STRING id="STR_ID_AM_APP_NAME_KINGCOMBAT"/>
    <IMAGE id="IMG_ID_AM_APP_KINGCOMBAT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_KINGCOMBAT_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_KINGCOMBAT" str="STR_ID_AM_APP_NAME_KINGCOMBAT" img="IMG_ID_MRE_APP_KINGCOMBAT_SMALL" highlight="mmi_am_la_highlight_KINGCOMBAT_CHS"></MENUITEM>    
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_EN__
    <STRING id="STR_ID_AM_APP_NAME_GOLDMINER"/>
    <IMAGE id="IMG_ID_AM_APP_GOLDMINER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_GOLDMINER_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GOLDMINER" str="STR_ID_AM_APP_NAME_GOLDMINER" img="IMG_ID_MRE_APP_GOLDMINER_SMALL" highlight="mmi_am_la_highlight_GOLDMINER_EN"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_CHS__
    <STRING id="STR_ID_AM_APP_NAME_GOLDMINER"/>
    <IMAGE id="IMG_ID_AM_APP_GOLDMINER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_GOLDMINER_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GOLDMINER" str="STR_ID_AM_APP_NAME_GOLDMINER" img="IMG_ID_MRE_APP_GOLDMINER_SMALL" highlight="mmi_am_la_highlight_GOLDMINER_CHS"></MENUITEM>
#endif
/***********************************************/

#ifdef __MMI_MRE_GAME_MOTO_EN__
    <STRING id="STR_ID_AM_APP_NAME_MOTO"/>
    <IMAGE id="IMG_ID_AM_APP_MOTO" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_MOTO_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_MOTO" str="STR_ID_AM_APP_NAME_MOTO" img="IMG_ID_MRE_APP_MOTO_SMALL" highlight="mmi_am_la_highlight_MOTO_EN"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_MOTO_CHS__
    <STRING id="STR_ID_AM_APP_NAME_MOTO"/>
    <IMAGE id="IMG_ID_AM_APP_MOTO" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_MOTO_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_MOTO" str="STR_ID_AM_APP_NAME_MOTO" img="IMG_ID_MRE_APP_MOTO_SMALL" highlight="mmi_am_la_highlight_MOTO_CHS"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_GIRLSLOT_EN__
    <STRING id="STR_ID_AM_APP_NAME_GIRLSLOT"/>
    <IMAGE id="IMG_ID_AM_APP_GIRLSLOT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_GIRLSLOT_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GIRLSLOT" str="STR_ID_AM_APP_NAME_GIRLSLOT" img="IMG_ID_MRE_APP_GIRLSLOT_SMALL" highlight="mmi_am_la_highlight_GIRLSLOT_EN"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_GIRLSLOT_CHS__
    <STRING id="STR_ID_AM_APP_NAME_GIRLSLOT"/>
    <IMAGE id="IMG_ID_AM_APP_GIRLSLOT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_GIRLSLOT_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GIRLSLOT" str="STR_ID_AM_APP_NAME_GIRLSLOT" img="IMG_ID_MRE_APP_GIRLSLOT_SMALL" highlight="mmi_am_la_highlight_GIRLSLOT_CHS"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_PARKOUR_EN__
    <STRING id="STR_ID_AM_APP_NAME_PARKOUR"/>
    <IMAGE id="IMG_ID_AM_APP_PARKOUR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_PARKOUR_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_PARKOUR" str="STR_ID_AM_APP_NAME_PARKOUR" img="IMG_ID_MRE_APP_PARKOUR_SMALL" highlight="mmi_am_la_highlight_PARKOUR_EN"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_PARKOUR_CHS__
    <STRING id="STR_ID_AM_APP_NAME_PARKOUR"/>
    <IMAGE id="IMG_ID_AM_APP_PARKOUR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_PARKOUR_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_PARKOUR" str="STR_ID_AM_APP_NAME_PARKOUR" img="IMG_ID_MRE_APP_PARKOUR_SMALL" highlight="mmi_am_la_highlight_PARKOUR_CHS"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_TEARDRESS_EN__
    <STRING id="STR_ID_AM_APP_NAME_TEARDRESS"/>
    <IMAGE id="IMG_ID_AM_APP_TEARDRESS" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_TEARDRESS_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_TEARDRESS" str="STR_ID_AM_APP_NAME_TEARDRESS" img="IMG_ID_MRE_APP_TEARDRESS_SMALL" highlight="mmi_am_la_highlight_TEARDRESS_EN"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_TEARDRESS_CHS__
    <STRING id="STR_ID_AM_APP_NAME_TEARDRESS"/>
    <IMAGE id="IMG_ID_AM_APP_TEARDRESS" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_TEARDRESS_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_TEARDRESS" str="STR_ID_AM_APP_NAME_TEARDRESS" img="IMG_ID_MRE_APP_TEARDRESS_SMALL" highlight="mmi_am_la_highlight_TEARDRESS_CHS"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_EN__
    <STRING id="STR_ID_AM_APP_NAME_HAPPYEGG"/>
    <IMAGE id="IMG_ID_AM_APP_HAPPYEGG" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_HAPPYEGG_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_HAPPYEGG" str="STR_ID_AM_APP_NAME_HAPPYEGG" img="IMG_ID_MRE_APP_HAPPYEGG_SMALL" highlight="mmi_am_la_highlight_HAPPYEGG_EN"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_CHS__
    <STRING id="STR_ID_AM_APP_NAME_HAPPYEGG"/>
    <IMAGE id="IMG_ID_AM_APP_HAPPYEGG" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_HAPPYEGG_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_HAPPYEGG" str="STR_ID_AM_APP_NAME_HAPPYEGG" img="IMG_ID_MRE_APP_HAPPYEGG_SMALL" highlight="mmi_am_la_highlight_HAPPYEGG_CHS"></MENUITEM>
#endif


/*<---------------------------- ADD 3GT Game START ---------------------------->*/

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_ENG__
    <STRING id="STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_ENG"/>
    <IMAGE id="IMG_ID_AM_APP_BOWLING_ENG" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_APP_3GT_BOWLING.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_3GT_GAME_BOWLING_ENG_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_3GT_BOWLING_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_BOWLING_ENG" str="STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_ENG" img="IMG_ID_MRE_APP_3GT_GAME_BOWLING_ENG_SMALL" highlight="mmi_am_la_highlight_BOWLING_ENG"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHS__
    <STRING id="STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_CHS"/>
    <IMAGE id="IMG_ID_AM_APP_BOWLING_CHS" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_APP_3GT_BOWLING.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_3GT_GAME_BOWLING_CHS_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_3GT_BOWLING_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_BOWLING_CHS" str="STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_CHS" img="IMG_ID_MRE_APP_3GT_GAME_BOWLING_CHS_SMALL" highlight="mmi_am_la_highlight_BOWLING_CHS"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHT__
    <STRING id="STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_CHT"/>
    <IMAGE id="IMG_ID_AM_APP_BOWLING_CHT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_APP_3GT_BOWLING.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_3GT_GAME_BOWLING_CHT_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_3GT_BOWLING_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_BOWLING_CHT" str="STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_CHT" img="IMG_ID_MRE_APP_3GT_GAME_BOWLING_CHT_SMALL" highlight="mmi_am_la_highlight_BOWLING_CHT"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_DANDELION__
    <STRING id="STR_ID_AM_APP_NAME_3GT_GAME_DANDELION"/>
    <IMAGE id="IMG_ID_AM_APP_DANDELION" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_APP_3GT_DANDELION.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_3GT_GAME_DANDELION_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_3GT_DANDELION_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_DANDELION" str="STR_ID_AM_APP_NAME_3GT_GAME_DANDELION" img="IMG_ID_MRE_APP_3GT_GAME_DANDELION_SMALL" highlight="mmi_am_la_highlight_DANDELION"></MENUITEM>    
#endif

#if defined(__MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__) || defined(__MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__) || defined(__MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__)
    <STRING id="STR_ID_AM_APP_NAME_3GT_RASH_MOTOR"/>
    <IMAGE id="IMG_ID_AM_APP_3GT_RASH_MOTOR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_3gt_Rash_Motor.gif"</IMAGE>
#endif 

#if defined(__MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__) || defined(__MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__) || defined(__MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__)
    <STRING id="STR_ID_AM_APP_NAME_3GT_BALANCE_BALL"/>
    <IMAGE id="IMG_ID_AM_APP_3GT_BALANCE_BALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_3gt_Balance_Ball.gif"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__
    <MENUITEM id="MENU_ID_MRE_3GT_RASH_MOTOR_CHS" str="STR_ID_AM_APP_NAME_3GT_RASH_MOTOR" highlight="mmi_am_la_highlight_3gt_rash_motor_chs"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__
    <MENUITEM id="MENU_ID_MRE_3GT_RASH_MOTOR_CHT" str="STR_ID_AM_APP_NAME_3GT_RASH_MOTOR" highlight="mmi_am_la_highlight_3gt_rash_motor_cht"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__
    <MENUITEM id="MENU_ID_MRE_3GT_RASH_MOTOR_ENG" str="STR_ID_AM_APP_NAME_3GT_RASH_MOTOR" highlight="mmi_am_la_highlight_3gt_rash_motor_eng"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__
    <MENUITEM id="MENU_ID_MRE_3GT_BALANCE_BALL_CHS" str="STR_ID_AM_APP_NAME_3GT_BALANCE_BALL" highlight="mmi_am_la_highlight_3gt_balance_ball_chs"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__
    <MENUITEM id="MENU_ID_MRE_3GT_BALANCE_BALL_CHT" str="STR_ID_AM_APP_NAME_3GT_BALANCE_BALL" highlight="mmi_am_la_highlight_3gt_balance_ball_cht"></MENUITEM>    
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__
    <MENUITEM id="MENU_ID_MRE_3GT_BALANCE_BALL_ENG" str="STR_ID_AM_APP_NAME_3GT_BALANCE_BALL" highlight="mmi_am_la_highlight_3gt_balance_ball_eng"></MENUITEM>    
#endif

/*<---------------------------- ADD 3GT Game END ------------------------------>*/

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE1__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE1__)
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_Asphalt6.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_Asphalt6.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_ASPHALT6" str="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6" img="IMG_ID_AM_APP_GAMELOFT_ASPHALT6_SMALL" highlight="mmi_am_la_highlight_GameLoft_ASPHALT6"></MENUITEM>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BrainChallenge3.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_BrainChallenge3.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_BRAINCHALLENGE" str="STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE" img="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE_SMALL" highlight="mmi_am_la_highlight_GameLoft_BRAINCHALLENGE"></MENUITEM>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BlockBreaker3.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_BlockBreaker3.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_BLOCKBREAKER" str="STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER" img="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER_SMALL" highlight="mmi_am_la_highlight_GameLoft_BLOCKBREAKER"></MENUITEM>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_AssassinsCreed3.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_AssassinsCreed3.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_ASSASSINCREED" str="STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED" img="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED_SMALL" highlight="mmi_am_la_highlight_GameLoft_ASSASSINCREED"></MENUITEM>
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE2__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE2__)
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_Asphalt6.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_Asphalt6.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_ASPHALT6" str="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6" img="IMG_ID_AM_APP_GAMELOFT_ASPHALT6_SMALL" highlight="mmi_am_la_highlight_GameLoft_ASPHALT6"></MENUITEM>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BrainChallenge3.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_BrainChallenge3.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_BRAINCHALLENGE" str="STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE" img="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE_SMALL" highlight="mmi_am_la_highlight_GameLoft_BRAINCHALLENGE"></MENUITEM>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BlockBreaker3.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_BlockBreaker3.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_BLOCKBREAKER" str="STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER" img="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER_SMALL" highlight="mmi_am_la_highlight_GameLoft_BLOCKBREAKER"></MENUITEM>
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE3__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE3__)
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_Asphalt6.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_Asphalt6.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_ASPHALT6" str="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6" img="IMG_ID_AM_APP_GAMELOFT_ASPHALT6_SMALL" highlight="mmi_am_la_highlight_GameLoft_ASPHALT6"></MENUITEM>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BlockBreaker3.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_BlockBreaker3.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_BLOCKBREAKER" str="STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER" img="IMG_ID_AM_APP_GAMELOFT_BLOCKBREAKER_SMALL" highlight="mmi_am_la_highlight_GameLoft_BLOCKBREAKER"></MENUITEM>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_AssassinsCreed3.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_AssassinsCreed3.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_ASSASSINCREED" str="STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED" img="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED_SMALL" highlight="mmi_am_la_highlight_GameLoft_ASSASSINCREED"></MENUITEM>
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE4__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE4__)
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_Asphalt6.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_Asphalt6.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_ASPHALT6" str="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6" img="IMG_ID_AM_APP_GAMELOFT_ASPHALT6_SMALL" highlight="mmi_am_la_highlight_GameLoft_ASPHALT6"></MENUITEM>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_BrainChallenge3.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_BrainChallenge3.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_BRAINCHALLENGE" str="STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE" img="IMG_ID_AM_APP_GAMELOFT_BRAINCHALLENGE_SMALL" highlight="mmi_am_la_highlight_GameLoft_BRAINCHALLENGE"></MENUITEM>

	<STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED"/>
	<IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_AssassinsCreed3.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_AssassinsCreed3.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_ASSASSINCREED" str="STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED" img="IMG_ID_AM_APP_GAMELOFT_ASSASSINCREED_SMALL" highlight="mmi_am_la_highlight_GameLoft_ASSASSINCREED"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_2ND_PACKAGE__
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_GLIVE"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_GLIVE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_GLive.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_GLIVE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_GLive.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_GLIVE" str="STR_ID_AM_APP_NAME_GAMELOFT_GLIVE" img="IMG_ID_AM_APP_GAMELOFT_GLIVE_SMALL" highlight="mmi_am_la_highlight_gameloft_glive"></MENUITEM>

    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_MC2"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_MC2" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_mc2.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_MC2_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_mc2.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_MC2" str="STR_ID_AM_APP_NAME_GAMELOFT_MC2" img="IMG_ID_AM_APP_GAMELOFT_MC2_SMALL" highlight="mmi_am_la_highlight_gameloft_mc2"></MENUITEM>
#endif

#if defined (__MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250__) || defined (__MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250__)
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_Asphalt6.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_ASPHALT6_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_Asphalt6.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_ASPHALT6" str="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6" img="IMG_ID_AM_APP_GAMELOFT_ASPHALT6_SMALL" highlight="mmi_am_la_highlight_GameLoft_ASPHALT6"></MENUITEM>
    
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_GLIVE"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_GLIVE" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Gameloft_GLive.gif"</IMAGE>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_GLIVE_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\AM_App_Gameloft_GLive.bmp"</IMAGE>    
    <MENUITEM id="MENU_ID_MRE_APP_GAMELOFT_GLIVE" str="STR_ID_AM_APP_NAME_GAMELOFT_GLIVE" img="IMG_ID_AM_APP_GAMELOFT_GLIVE_SMALL" highlight="mmi_am_la_highlight_gameloft_glive"></MENUITEM>
#endif

#if defined(__MMI_MRE_APP_SINA_WEIBO__) && (__MMI_MRE_APP_SINA_WEIBO__ == __MRE_APP_DEFAULT__)
    <STRING id="STR_ID_AM_APP_NAME_SINA_WEIBO"/>
    <IMAGE id="IMG_ID_AM_APP_SINA_WEIBO" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Sina_Weibo.gif"</IMAGE>
    <IMAGE id="IMG_ID_MRE_APP_SINA_WEIBO_SMALL" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_Sina_Weibo_Small.bmp"</IMAGE>
    <MENUITEM id="MENU_ID_MRE_SINA_WEIBO" str="STR_ID_AM_APP_NAME_SINA_WEIBO" img="IMG_ID_MRE_APP_SINA_WEIBO_SMALL" highlight="mmi_am_la_highlight_sina_weibo"></MENUITEM>
#endif

#endif /* __MRE_APP_LAUNCH__ */
#endif /* __PLUTO_MMI_PACKAGE__ */
/*******************************************************************************************************************************
 *  MRE APP shortcuts resource
 ******************************************************************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__
#define MRE_SHORTCUT_IMG_FILE_TYPE ".png"
#define MRE_SHORTCUT_IMG_PATH RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\MRE_Shortcut"
#elif defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
#define MRE_SHORTCUT_IMG_FILE_TYPE ".png"
#define MRE_SHORTCUT_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_Shortcut_Launcher"
#define MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE ".png"
#define MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_Shortcut_KeyLauncher"
#elif defined(__MMI_VUI_LAUNCHER__)
#define MRE_SHORTCUT_IMG_FILE_TYPE ".png"
#define MRE_SHORTCUT_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_Shortcut_Launcher"
#elif defined(__MMI_VUI_LAUNCHER_KEY__)
#define MRE_SHORTCUT_IMG_FILE_TYPE ".png"
#define MRE_SHORTCUT_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_Shortcut_KeyLauncher"
#elif defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
#define MRE_SHORTCUT_IMG_FILE_TYPE ".png"
#define MRE_SHORTCUT_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_Shortcut_Launcher"
#elif defined(__MMI_LAUNCHER_APP_LIST__)
#define MRE_SHORTCUT_IMG_FILE_TYPE ".png"
#define MRE_SHORTCUT_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_Shortcut_Launcher"
#else
#define MRE_SHORTCUT_IMG_FILE_TYPE ".bmp"
#define MRE_SHORTCUT_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\MRE_Shortcut"
#endif

#ifdef __MMI_MRE_APP_CALCULATOR_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_CALCULATOR"/>
    <IMAGE id="IMG_ID_AM_APP_CALCULATOR_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Caculator"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_CALCULATOR_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Caculator"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_HEALTH_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_HEALTH"/>
    <IMAGE id="IMG_ID_AM_APP_HEALTH_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Health"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_HEALTH_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Health"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_STOPWATCH_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_STOPWATCH"/>
    <IMAGE id="IMG_ID_AM_APP_STOPWATCH_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\StopWatch"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_STOPWATCH_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\StopWatch"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_CONVERTER_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_CONVERTER"/>
    <IMAGE id="IMG_ID_AM_APP_CONVERTER_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Convertor"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_CONVERTER_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Convertor"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_ZAKAT_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_ZAKAT"/>
    <IMAGE id="IMG_ID_AM_APP_ZAKAT_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\ZakatCalculator"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_ZAKAT_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\ZakatCalculator"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_GAME_EGYPTCODE_EN_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_EGYPTCODE"/>
    <IMAGE id="IMG_ID_AM_APP_EGYPTCODE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mtone_EgyptCode"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_EGYPTCODE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mtone_EgyptCode"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_GAME_GIRLSLOT_EN_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_GIRLSLOT"/>
    <IMAGE id="IMG_ID_AM_APP_GIRLSLOT_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mtone_GirlSlot"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_GIRLSLOT_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mtone_GirlSlot"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_EN_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_GOLDMINER"/>
    <IMAGE id="IMG_ID_AM_APP_GOLDMINER_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mtone_GoldenMiner"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_GOLDMINER_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mtone_GoldenMiner"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_EN_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_HAPPYEGG"/>
    <IMAGE id="IMG_ID_AM_APP_HAPPYEGG_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mtone_HappyEgg"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_HAPPYEGG_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mtone_HappyEgg"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_GAME_HAPPYWAR_EN_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_HAPPYWAR"/>
    <IMAGE id="IMG_ID_AM_APP_HAPPYWAR_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mtone_HappyWar"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_HAPPYWAR_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mtone_HappyWar"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_EN_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_KINGCOMBAT"/>
    <IMAGE id="IMG_ID_AM_APP_KINGCOMBAT_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mtone_KingCombat"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_KINGCOMBAT_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mtone_KingCombat"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_GAME_MOTO_EN_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_MOTO"/>
    <IMAGE id="IMG_ID_AM_APP_MOTO_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mtone_Moto"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_MOTO_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mtone_Moto"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_GAME_PARKOUR_EN_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_PARKOUR"/>
    <IMAGE id="IMG_ID_AM_APP_PARKOUR_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mtone_Parkour"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_PARKOUR_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mtone_Parkour"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_GAME_TEARDRESS_EN_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_TEARDRESS"/>
    <IMAGE id="IMG_ID_AM_APP_TEARDRESS_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mtone_TearDress"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_TEARDRESS_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mtone_TearDress"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#if defined(__MMI_MRE_APP_FACEBOOK_V2_SHORTCUT__) || defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD_SHORTCUT__)
    <STRING id="STR_ID_AM_APP_NAME_FBLITE"/>
    <IMAGE id="IMG_ID_AM_APP_FBLITE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Facebook"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_FBLITE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Facebook"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_YAHOOMV2_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_YAHOO"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOO_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Yahoo_messenger"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_YAHOO_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Yahoo_messenger"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_YAHOOFINANCE_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_YAHOOFINANCE"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOOFINANCE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Yahoo_finance"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_YAHOOFINANCE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Yahoo_finance"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_YAHOONEWS_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_YAHOONEWS"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOONEWS_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Yahoo_news"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_YAHOONEWS_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Yahoo_news"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_YAHOOWEATHER_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_YAHOOWEATHER"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOOWEATHER_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Yahoo_weather"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_YAHOOWEATHER_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Yahoo_weather"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_YAHOOCRICKET_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_YAHOOCRICKET"/>
    <IMAGE id="IMG_ID_AM_APP_YAHOOCRICKET_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Yahoo_cricket"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_YAHOOCRICKET_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Yahoo_cricket"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_TWITTER_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_TWITTER"/>
    <IMAGE id="IMG_ID_AM_APP_TWITTER_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Twitter"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_TWITTER_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Twitter"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_LIVE_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_GLIVE"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_GLIVE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Gameloft_live"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_GLIVE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Gameloft_live"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_GMOBI_APPSTORE_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_GMOBI_APPSTORE"/>
    <IMAGE id="IMG_ID_AM_APP_GMOBI_APPSTORE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Gmobi_appstore"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_GMOBI_APPSTORE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Gmobi_appstore"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_MBOUNCE_APPSTORE"/>
    <IMAGE id="IMG_ID_AM_APP_MBOUNCE_APPSTORE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\MBounce_appstore"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_MBOUNCE_APPSTORE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\MBounce_appstore"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_KKFUN_APPSTORE_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_KKFUN_APPSTORE"/>
    <IMAGE id="IMG_ID_AM_APP_KKFUN_APPSTORE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\KkfunStore"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_KKFUN_APPSTORE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\KkfunStore"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_MOBIM_APPSTORE_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_MOBIM_APPSTORE"/>
    <IMAGE id="IMG_ID_AM_APP_MOBIM_APPSTORE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mobim_appstore"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_MOBIM_APPSTORE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mobim_appstore"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_MTONE_APPSTORE_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_MTONE_APPSTORE"/>
    <IMAGE id="IMG_ID_AM_APP_MTONE_APPSTORE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Mtone_MStore"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_MTONE_APPSTORE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mtone_MStore"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_MODING_APPSTORE_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_MODING_APPSTORE"/>
    <IMAGE id="IMG_ID_AM_APP_MODING_APPSTORE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Moding_appstore"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_MODING_APPSTORE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Moding_appstore"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_MOMAGIC_APPSTORE_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_MOMAGIC_APPSTORE"/>
    <IMAGE id="IMG_ID_AM_APP_MOMAGIC_APPSTORE_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Momagic_appstore"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_MOMAGIC_APPSTORE_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Momagic_appstore"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_BC_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_BC_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\BrainChallenge3"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_BC_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\BrainChallenge3"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_BB_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_BB_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\BlockBreaker3"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_BB_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\BlockBreaker3"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_AC_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_AC_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\AssassinCreed3"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_AC_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\AssassinCreed3"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_MC2_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_MC2"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_MC2_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\ModernCombat2"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_MC2_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\ModernCombat2"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_AS6_SHORTCUT__
    <STRING id="STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6"/>
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_AS6_SHORTCUT">MRE_SHORTCUT_IMG_PATH"\\\\Asphalt6"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_GAMELOFT_AS6_SHORTCUT_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Asphalt6"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#if defined(__MMI_MRE_APP_VOGINS_MOBILE_MARKET__) && (__MMI_MRE_APP_VOGINS_MOBILE_MARKET__&__MRE_APP_SHORTCUT__)
    <STRING id="STR_ID_AM_APP_VOGINS_MOBILE_MARKET"/>
    <IMAGE id="IMG_ID_AM_APP_VOGINS_MOBILE_MARKET">MRE_SHORTCUT_IMG_PATH"\\\\Vogins_mobilemarket"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_VOGINS_MOBILE_MARKET_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Vogins_mobilemarket"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#if defined(__MMI_MRE_APP_IBINGO_UISTORE__) && (__MMI_MRE_APP_IBINGO_UISTORE__&__MRE_APP_SHORTCUT__)
    <STRING id="STR_ID_AM_APP_IBINGO_UISTORE"/>
    <IMAGE id="IMG_ID_AM_APP_IBINGO_UISTORE">MRE_SHORTCUT_IMG_PATH"\\\\iBingo_uistore"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_IBINGO_UISTORE_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\iBingo_uistore"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#if defined(__MMI_MRE_APP_MOBIM_FCWR__) && (__MMI_MRE_APP_MOBIM_FCWR__&__MRE_APP_SHORTCUT__)
    <STRING id="STR_ID_AM_APP_MOBIM_FCWR"/>
    <IMAGE id="IMG_ID_AM_APP_MOBIM_FCWR">MRE_SHORTCUT_IMG_PATH"\\\\FCWR"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_MOBIM_FCWR_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\FCWR"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif

#if defined(__MMI_MRE_APP_MITAKE_MSTOCK__) && (__MMI_MRE_APP_MITAKE_MSTOCK__&__MRE_APP_SHORTCUT__)
    <STRING id="STR_ID_AM_APP_MITAKE_MSTOCK"/>
    <IMAGE id="IMG_ID_AM_APP_MITAKE_MSTOCK">MRE_SHORTCUT_IMG_PATH"\\\\Mitake_mStock"MRE_SHORTCUT_IMG_FILE_TYPE</IMAGE>
    #if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_AM_APP_MITAKE_MSTOCK_KEY_LAUNCHER">MRE_SHORTCUT_IMG_KEY_LAUNCHER_PATH"\\\\Mitake_mStock"MRE_SHORTCUT_IMG_KEY_LAUNCHER_FILE_TYPE</IMAGE>
    #endif
#endif
</APP>
