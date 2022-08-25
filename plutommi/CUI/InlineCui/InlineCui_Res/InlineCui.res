
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_INLINE_EDITOR" name = "STR_INLINE_EDITOR" hidden_in_mainmenu = "true">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

  <MEMORY  base="INLINE_CUI_INSTANCE_SIZE"  inc="..\\plutommi\\CUI\\InlineCui\\InlineCui.h"/>
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="CUI_INLINE_MAIN_SCREEN_SCRN_ID"/>
    <SCREEN id="CUI_INLINE_FULLSCREEN_EDIT_SCRN_ID"/>s
    <SCREEN id="CUI_INLINE_FULLSCREEN_OPTION_LIST_SCRN_ID"/>
    <SCREEN id="CUI_INLINE_IMAGETEXT_EDIT_SCRN_ID"/>
    <SCREEN id="CUI_INLINE_IMAGETEXT_OPIONT_LIST_SCRN_ID"/>


</APP>

