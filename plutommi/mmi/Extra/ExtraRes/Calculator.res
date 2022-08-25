
#include "mmi_features.h"
#include "custresdef.h"
#include "Calculator.h"
#if ((defined(__MMI_MAINLCD_128X160__)||defined(__MMI_MAINLCD_176X220__)||defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_240X400__)||defined(__MMI_MAINLCD_320X240__)||defined(__MMI_MAINLCD_320X480__)) && !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__))
#ifndef __CALC_SLIM_FOR_61__
#define __CALC_SLIM_FOR_61__
#endif
#endif

//#if defined(__MMI_CALCULATOR__) && !defined(__COSMOS_MMI_PACKAGE__)
#if defined(__MMI_CALCULATOR__)

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_CALCULATOR" 
#ifdef __MMI_APP_MANAGER_SUPPORT__
    package_name="native.mtk.calculator"
    name="STR_ID_CALC_MENU"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON      
    img="MAIN_MENU_CALC_ICON"
#endif    
    launch="CalcPreEntryApp"
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    
    <!------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_CALC_MENU"/>
  #ifdef __MMI_OP02_0100__
    <STRING id="STR_ID_OP_DIVIDE_ERROR"/>
    <STRING id="STR_ID_OP_RESULT_EXCEED"/>
  #endif
     
    <!-------------------------------String Resource not suport mult-language ------------------------------------->
#if !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_SLIM_IMG_RES__)
    <STRING id="STR_ID_CALC_MP">"M+"</STRING>
    <STRING id="STR_ID_CALC_MM">"M-"</STRING>
    <STRING id="STR_ID_CALC_MR">"MR"</STRING>
    <STRING id="STR_ID_CALC_MC">"MC"</STRING>
    <STRING id="STR_ID_CALC_EQUAL">"="</STRING>
#endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON  
    <IMAGE id = "MAIN_MENU_CALC_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\MainMenu\\\\Icons\\\\Calculator.png"</IMAGE>
#endif
#endif
      
#ifdef __MMI_SLIM_IMG_RES__
    <IMAGE id="IMG_ID_CALC_MENU_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Calculator\\\\SB_OCACU.bmp"</IMAGE>
#else
    <IMAGE id="IMG_ID_CALC_MENU_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\SB_OCACU.bmp"</IMAGE>
#endif /*__MMI_SLIM_IMG_RES__*/

#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_TOUCH_SCREEN__
  #ifndef __CALC_FTE_SLIM_USE_SLICE_RES__
    <IMAGE id="IMG_ID_CALC_MAIN" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\main.jpg"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY0" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\0.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY1" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\01.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY2" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\02.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY3" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\03.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY4" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\04.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY5" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\05.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY6" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\06.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY7" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\07.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY8" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\08.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY9" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\09.PNG"</IMAGE>

    <IMAGE id="IMG_ID_CALC_DOT" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\doc.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_EQUAL" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\Equal.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_PLUS" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\Plus.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_SUB" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\Subtract.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MULTI" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\Multi.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_DIVIDE" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\Divide.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY00" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\00.PNG"</IMAGE>
  #else   
    <IMAGE id="IMG_ID_CALC_KEY_NONHILIGHT_SLICE" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\number.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY_HILIGHT_SLICE" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\number_s.9slice.png"</IMAGE>
    
    <IMAGE id="IMG_ID_CALC_EQUAL" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\equal.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_PLUS_AND_SUB_SLICE" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\horizontal_s.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MULTI_AND_DIVIDE_SLICE" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\vertical_s.9slice.png"</IMAGE>
    
    <IMAGE id="IMG_ID_CALC_MAIN_COUNT" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keytouch\\\\count.png"</IMAGE>
  #endif/*__CALC_FTE_SLIM_USE_SLICE_RES__*/
#else
    <IMAGE id="IMG_ID_CALC_MAIN" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keyonly\\\\main.jpg"</IMAGE>
    <IMAGE id="IMG_ID_CALC_EQUAL" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keyonly\\\\EQUAL.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_PLUS" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keyonly\\\\PLUS.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_SUB" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keyonly\\\\SUBTRACT.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MULTI" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keyonly\\\\MULTI.PNG"</IMAGE>
    <IMAGE id="IMG_ID_CALC_DIVIDE" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\keyonly\\\\Divide.PNG"</IMAGE>
#endif

#elif defined(__MMI_SLIM_IMG_RES__)
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id="IMG_ID_CALC_MAIN" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_main.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY0" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY1" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY2" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY3" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY4" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY5" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY6" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY7" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY8" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY9" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>

    <IMAGE id="IMG_ID_CALC_DOT" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_EQUAL" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_PLUS" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_SUB" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MULTI" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_DIVIDE" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MP" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MS" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MR" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MC" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_P.9slice.png"</IMAGE>
#else
    <IMAGE id="IMG_ID_CALC_MAIN" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\MAP.png"</IMAGE>
    <IMAGE id="IMG_ID_CALC_EQUAL" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\Equal.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_PLUS" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\Plus.bmp"</IMAGE>
   #ifndef __CALC_SLIM_FOR_61__
    <IMAGE id="IMG_ID_CALC_SUB" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\Subtract.bmp"</IMAGE>
   #endif/*__CALC_SLIM_FOR_61__*/
    <IMAGE id="IMG_ID_CALC_MULTI" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\Multi.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_DIVIDE" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\Divide.bmp"</IMAGE>
#endif

#else
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id="IMG_ID_CALC_MAIN" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_main.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY0" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_key0.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY1" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_key1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY2" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_key2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY3" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_key3.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY4" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_key4.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY5" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_key5.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY6" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_key6.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY7" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_key7.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY8" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_key8.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_KEY9" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_key9.bmp"</IMAGE>

    <IMAGE id="IMG_ID_CALC_DOT" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_dot.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_EQUAL" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_equal.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_PLUS" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_plus.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_SUB" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_subtract.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MULTI" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_multi.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_DIVIDE" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_div.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MP" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_mp.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MS" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_mm.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MR" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_mr.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MC" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\Th_calc_mc.bmp"</IMAGE>
#else
    <IMAGE id="IMG_ID_CALC_MAIN" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\map.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_PLUS" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Plus.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_SUB" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Subtract.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MULTI" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Multi.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_DIVIDE" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Divide.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MP" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Mp.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MS" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Mm.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MR" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Mr.bmp"</IMAGE>
    <IMAGE id="IMG_ID_CALC_MC" >CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Mc.bmp"</IMAGE>
#endif
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <MENU id="EXTRA_CALCULATOR_MENU" str="STR_ID_CALC_MENU" img="IMG_ID_CALC_MENU_ICON" highlight="HighlightCalcMenu" 
    shortcut="ON" shortcut_img="IMG_ID_CALC_MENU_ICON" launch="CalcPreEntryApp">
    </MENU>
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_CALC"/>
    <SCREEN id="SCR_ID_CALC_APP"/>
    
#if !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_SLIM_IMG_RES__) 
	<SCREEN id="GRP_ID_CALC_OPTION"/>
	
    <MENUITEM id="MENU_ID_CALC_MP" str="STR_ID_CALC_MP"/>
    <MENUITEM id="MENU_ID_CALC_MM" str="STR_ID_CALC_MM"/>
    <MENUITEM id="MENU_ID_CALC_MR" str="STR_ID_CALC_MR"/>
    <MENUITEM id="MENU_ID_CALC_MC" str="STR_ID_CALC_MC"/>
    <MENUITEM id="MENU_ID_CALC_EQUAL" str="STR_ID_CALC_EQUAL"/>

    <MENU id="EXTRA_CALCULATOR_OPTIONS_MENU" type="OPTION" str="STR_ID_CALC_MENU">
        <MENUITEM_ID>MENU_ID_CALC_MP</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CALC_MM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CALC_MR</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CALC_MC</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CALC_EQUAL</MENUITEM_ID>
    </MENU>
#endif /* !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__) */ 

</APP>
#endif /* defined(__MMI_CALCULATOR__) && !defined(__COSMOS_MMI_PACKAGE__) */

