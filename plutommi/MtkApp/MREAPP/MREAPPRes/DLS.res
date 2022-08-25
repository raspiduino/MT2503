#include "MMI_features.h"
#if !defined(__COSMOS_MMI_PACKAGE__)
#include "custresdef.h"
#include "vmswitch.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_MRE">
#ifdef __PLUTO_MMI_PACKAGE__
    <INCLUDE file="mmi_rp_app_am_def.h"/>
#endif

//<STRING id="STR_ID_AM_MEDIA_MEMORY_UNAVAIBLE"/>


    <SCREEN id="SCR_ID_DLS_WAIT"/>
    <SCREEN id="SCR_ID_DLS_QUERY"/>

    <STRING id="STR_ID_DLS_QUERY"/>
    <STRING id="STR_DI_DLS_NETWORK_PROBLEM"/>
    <STRING id="STR_DI_DLS_FAIL_MAY_DISK_FULL"/>
    //<STRING id="STR_ID_DLS_AVAILABLE_UPDATE"/>
    <STRING id ="STR_ID_DLS_NO_UPDATE"/>
    <STRING id="STR_ID_DLS_DOWNLOADING"/>
    <STRING id="STR_ID_DLS_DOWNLOADED"/>
    <STRING id="STR_ID_DLS_HOST_NOT_FOUND"/>
    <STRING id="STR_ID_DLS_PIPE_CLOSED"/>
    //<STRING id="STR_ID_DLS_PIPE_BROKEN"/>
    //<STRING id="STR_ID_DLS_ABORT"/>
    <STRING id="STR_ID_DLS_ERR_PATH"/>
    <STRING id="STR_ID_DLS_INSTALL_SECC"/>
    <STRING id="STR_ID_DLS_INSTALLING"/>
    <STRING id="STR_ID_DLS_INSTALL_FAIL"/>
    
    <STRING id="STR_ID_DLS_NA_NAME"/>
    <STRING id="STR_ID_DLS_NA_SLK"/>
    //<STRING id="STR_ID_DLS_TEST_NAME1"/>
    //<STRING id="STR_ID_DLS_TEST_NAME2"/>


    //<STRING id="STR_ID_DLS_TEST_NAME1"/>
    //<IMAGE id="IMG_ID_DLS_TEST1" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_QQ.gif"</IMAGE>
    //<MENUITEM id="MENU_ID_MRE_SHORTCUT_TEST1" str="STR_ID_DLS_TEST_NAME1" img="IMG_ID_DLS_TEST1" highlight="mmi_mre_shortcut_submenu_highlight_test1"></MENUITEM>

    //<STRING id="STR_ID_DLS_TEST_NAME2"/>
    //<IMAGE id="IMG_ID_DLS_TEST2" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.gif"</IMAGE>
    //<MENUITEM id="MENU_ID_MRE_SHORTCUT_TEST2" str="STR_ID_DLS_TEST_NAME2" img="IMG_ID_DLS_TEST2" highlight="mmi_mre_shortcut_submenu_highlight_test2"></MENUITEM>

    //<IMAGE id="IMG_ID_DLS_TEST1" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_QQ.gif"</IMAGE>


#ifdef __MMI_MRE_APP_CALCULATOR_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_CALCULATOR_SHORTCUT" str= "STR_ID_AM_APP_NAME_CALCULATOR" img= "IMG_ID_AM_APP_CALCULATOR_SHORTCUT" highlight= "mmi_mre_shortcut_calculator_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_HEALTH_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_HEALTH_SHORTCUT" str= "STR_ID_AM_APP_NAME_HEALTH" img= "IMG_ID_AM_APP_HEALTH_SHORTCUT" highlight= "mmi_mre_shortcut_health_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_STOPWATCH_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_STOPWATCH_SHORTCUT" str= "STR_ID_AM_APP_NAME_STOPWATCH" img= "IMG_ID_AM_APP_STOPWATCH_SHORTCUT" highlight= "mmi_mre_shortcut_stopwatch_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_CONVERTER_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_CONVERTER_SHORTCUT" str= "STR_ID_AM_APP_NAME_CONVERTER" img= "IMG_ID_AM_APP_CONVERTER_SHORTCUT" highlight= "mmi_mre_shortcut_converter_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_ZAKAT_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_ZAKAT_SHORTCUT" str= "STR_ID_AM_APP_NAME_ZAKAT" img= "IMG_ID_AM_APP_ZAKAT_SHORTCUT" highlight= "mmi_mre_shortcut_zakat_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_EGYPTCODE_EN_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_EGYPTCODE_SHORTCUT" str= "STR_ID_AM_APP_NAME_EGYPTCODE" img= "IMG_ID_AM_APP_EGYPTCODE_SHORTCUT" highlight= "mmi_mre_shortcut_egyptcode_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_GIRLSLOT_EN_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_GIRLSLOT_SHORTCUT" str= "STR_ID_AM_APP_NAME_GIRLSLOT" img= "IMG_ID_AM_APP_GIRLSLOT_SHORTCUT" highlight= "mmi_mre_shortcut_girlslot_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_EN_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_GOLDMINER_SHORTCUT" str= "STR_ID_AM_APP_NAME_GOLDMINER" img= "IMG_ID_AM_APP_GOLDMINER_SHORTCUT" highlight= "mmi_mre_shortcut_goldminer_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_EN_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_HAPPYEGG_SHORTCUT" str= "STR_ID_AM_APP_NAME_HAPPYEGG" img= "IMG_ID_AM_APP_HAPPYEGG_SHORTCUT" highlight= "mmi_mre_shortcut_happyegg_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_HAPPYWAR_EN_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_HAPPYWAR_SHORTCUT" str= "STR_ID_AM_APP_NAME_HAPPYWAR" img= "IMG_ID_AM_APP_HAPPYWAR_SHORTCUT" highlight= "mmi_mre_shortcut_happywar_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_EN_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_KINGCOMBAT_SHORTCUT" str= "STR_ID_AM_APP_NAME_KINGCOMBAT" img= "IMG_ID_AM_APP_KINGCOMBAT_SHORTCUT" highlight= "mmi_mre_shortcut_kingcombat_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_MOTO_EN_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_MOTO_SHORTCUT" str= "STR_ID_AM_APP_NAME_MOTO" img= "IMG_ID_AM_APP_MOTO_SHORTCUT" highlight= "mmi_mre_shortcut_moto_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_PARKOUR_EN_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_PARKOUR_SHORTCUT" str= "STR_ID_AM_APP_NAME_PARKOUR" img= "IMG_ID_AM_APP_PARKOUR_SHORTCUT" highlight= "mmi_mre_shortcut_parkour_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_GAME_TEARDRESS_EN_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_TEARDRESS_SHORTCUT" str= "STR_ID_AM_APP_NAME_TEARDRESS" img= "IMG_ID_AM_APP_TEARDRESS_SHORTCUT" highlight= "mmi_mre_shortcut_teardress_highlight_hdlr"></MENUITEM>
#endif

#if defined(__MMI_MRE_APP_FACEBOOK_V2_SHORTCUT__) || defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD_SHORTCUT__)
    <MENUITEM id= "MENU_ID_MRE_APP_FACEBOOK_V2_SHORTCUT" str= "STR_ID_AM_APP_NAME_FBLITE" img= "IMG_ID_AM_APP_FBLITE_SHORTCUT" highlight= "mmi_mre_shortcut_facebook_v2_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_YAHOOMV2_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_YAHOOMV2_SHORTCUT" str= "STR_ID_AM_APP_NAME_YAHOO" img= "IMG_ID_AM_APP_YAHOO_SHORTCUT" highlight= "mmi_mre_shortcut_yahoomv2_highlight_hdlr"></MENUITEM>
#endif /* __MMI_MRE_APP_YAHOOMV2_SHORTCUT__ */

#ifdef __MMI_MRE_APP_YAHOOFINANCE_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_YAHOOFINANCE_SHORTCUT" str= "STR_ID_AM_APP_NAME_YAHOOFINANCE" img= "IMG_ID_AM_APP_YAHOOFINANCE_SHORTCUT" highlight= "mmi_mre_shortcut_yahoofinance_highlight_hdlr"></MENUITEM>
#endif /* __MMI_MRE_APP_YAHOOFINANCE_SHORTCUT__ */

#ifdef __MMI_MRE_APP_YAHOONEWS_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_YAHOONEWS_SHORTCUT" str= "STR_ID_AM_APP_NAME_YAHOONEWS" img= "IMG_ID_AM_APP_YAHOONEWS_SHORTCUT" highlight= "mmi_mre_shortcut_yahoonews_highlight_hdlr"></MENUITEM>
#endif /* __MMI_MRE_APP_YAHOONEWS_SHORTCUT__ */

#ifdef __MMI_MRE_APP_YAHOOWEATHER_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_YAHOOWEATHER_SHORTCUT" str= "STR_ID_AM_APP_NAME_YAHOOWEATHER" img= "IMG_ID_AM_APP_YAHOOWEATHER_SHORTCUT" highlight= "mmi_mre_shortcut_yahooweather_highlight_hdlr"></MENUITEM>
#endif /* __MMI_MRE_APP_YAHOOWEATHER_SHORTCUT__ */

#ifdef __MMI_MRE_APP_YAHOOCRICKET_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_YAHOOCRICKET_SHORTCUT" str= "STR_ID_AM_APP_NAME_YAHOOCRICKET" img= "IMG_ID_AM_APP_YAHOOCRICKET_SHORTCUT" highlight= "mmi_mre_shortcut_yahoocricket_highlight_hdlr"></MENUITEM>
#endif /* __MMI_MRE_APP_YAHOOCRICKET_SHORTCUT__ */

#ifdef __MMI_MRE_APP_TWITTER_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_TWITTER_SHORTCUT" str= "STR_ID_AM_APP_NAME_TWITTER" img= "IMG_ID_AM_APP_TWITTER_SHORTCUT" highlight= "mmi_mre_shortcut_twitter_highlight_hdlr"></MENUITEM>
#endif /* __MMI_MRE_APP_TWITTER_SHORTCUT__ */

#ifdef __MMI_MRE_APP_GAMELOFT_LIVE_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_GAMELOFT_LIVE_SHORTCUT" str= "STR_ID_AM_APP_NAME_GAMELOFT_GLIVE" img= "IMG_ID_AM_APP_GAMELOFT_GLIVE_SHORTCUT" highlight= "mmi_mre_shortcut_gameloft_live_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_GMOBI_APPSTORE_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_GMOBI_APPSTORE_SHORTCUT" str= "STR_ID_AM_APP_NAME_GMOBI_APPSTORE" img= "IMG_ID_AM_APP_GMOBI_APPSTORE_SHORTCUT" highlight= "mmi_mre_shortcut_gmobi_appstore_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT" str= "STR_ID_AM_APP_NAME_MBOUNCE_APPSTORE" img= "IMG_ID_AM_APP_MBOUNCE_APPSTORE_SHORTCUT" highlight= "mmi_mre_shortcut_mbounce_appstore_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_KKFUN_APPSTORE_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_KKFUN_APPSTORE_SHORTCUT" str= "STR_ID_AM_APP_NAME_KKFUN_APPSTORE" img= "IMG_ID_AM_APP_KKFUN_APPSTORE_SHORTCUT" highlight= "mmi_mre_shortcut_kkfun_appstore_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_MOBIM_APPSTORE_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_MOBIM_APPSTORE_SHORTCUT" str= "STR_ID_AM_APP_NAME_MOBIM_APPSTORE" img= "IMG_ID_AM_APP_MOBIM_APPSTORE_SHORTCUT" highlight= "mmi_mre_shortcut_mobim_appstore_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_MTONE_APPSTORE_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_MTONE_APPSTORE_SHORTCUT" str= "STR_ID_AM_APP_NAME_MTONE_APPSTORE" img= "IMG_ID_AM_APP_MTONE_APPSTORE_SHORTCUT" highlight= "mmi_mre_shortcut_mtone_appstore_highlight_hdlr"></MENUITEM>
#endif /* __MMI_MRE_APP_MTONE_APPSTORE_SHORTCUT__ */

#ifdef __MMI_MRE_APP_MODING_APPSTORE_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_MODING_APPSTORE_SHORTCUT" str= "STR_ID_AM_APP_NAME_MODING_APPSTORE" img= "IMG_ID_AM_APP_MODING_APPSTORE_SHORTCUT" highlight= "mmi_mre_shortcut_moding_appstore_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_MOMAGIC_APPSTORE_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_MOMAGIC_APPSTORE_SHORTCUT" str= "STR_ID_AM_APP_NAME_MOMAGIC_APPSTORE" img= "IMG_ID_AM_APP_MOMAGIC_APPSTORE_SHORTCUT" highlight= "mmi_mre_shortcut_momagic_appstore_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_BC_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_GAMELOFT_BC_SHORTCUT" str= "STR_ID_AM_APP_NAME_GAMELOFT_BRAINCHALLENGE" img= "IMG_ID_AM_APP_GAMELOFT_BC_SHORTCUT" highlight= "mmi_mre_shortcut_gameloft_bc_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_BB_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_GAMELOFT_BB_SHORTCUT" str= "STR_ID_AM_APP_NAME_GAMELOFT_BLOCKBREAKER" img= "IMG_ID_AM_APP_GAMELOFT_BB_SHORTCUT" highlight= "mmi_mre_shortcut_gameloft_bb_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_AC_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_GAMELOFT_AC_SHORTCUT" str= "STR_ID_AM_APP_NAME_GAMELOFT_ASSASSINCREED" img= "IMG_ID_AM_APP_GAMELOFT_AC_SHORTCUT" highlight= "mmi_mre_shortcut_gameloft_ac_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_MC2_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_GAMELOFT_MC2_SHORTCUT" str= "STR_ID_AM_APP_NAME_GAMELOFT_MC2" img= "IMG_ID_AM_APP_GAMELOFT_MC2_SHORTCUT" highlight= "mmi_mre_shortcut_gameloft_mc2_highlight_hdlr"></MENUITEM>
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_AS6_SHORTCUT__
    <MENUITEM id= "MENU_ID_MRE_APP_GAMELOFT_AS6_SHORTCUT" str= "STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6" img= "IMG_ID_AM_APP_GAMELOFT_AS6_SHORTCUT" highlight= "mmi_mre_shortcut_gameloft_as6_highlight_hdlr"></MENUITEM>
#endif

#if defined(__MMI_MRE_APP_MOBIM_FCWR__) && (__MMI_MRE_APP_MOBIM_FCWR__&__MRE_APP_SHORTCUT__)
    <MENUITEM id= "MENU_ID_MRE_APP_MOBIM_FCWR" str= "STR_ID_AM_APP_MOBIM_FCWR" img= "IMG_ID_AM_APP_MOBIM_FCWR" highlight= "mmi_mre_shortcut_mobim_fcwr_highlight_hdlr"></MENUITEM>
#endif

#if defined(__MMI_MRE_APP_MITAKE_MSTOCK__) && (__MMI_MRE_APP_MITAKE_MSTOCK__&__MRE_APP_SHORTCUT__)
    <MENUITEM id= "MENU_ID_MRE_APP_MITAKE_MSTOCK" str= "STR_ID_AM_APP_MITAKE_MSTOCK" img= "IMG_ID_AM_APP_MITAKE_MSTOCK" highlight= "mmi_mre_shortcut_mitake_mstock_highlight_hdlr"></MENUITEM>
#endif
</APP>
#endif /* !defined(__COSMOS_MMI_PACKAGE__) */

