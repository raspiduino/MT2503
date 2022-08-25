#include "MMI_features.h" 
#include "custresdef.h"

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_PICT_BRIDGE">
    
<!-- 
**************************************** Image section ****************************************
-->
    <IMAGE id="IMG_ID_PICT_PRINTING">CUST_IMG_PATH"\\\\MAINLCD\\\\Bluetooth\\\\BPP\\\\BPP_PRINT.gif"</IMAGE>
    <IMAGE id="IMG_ID_PICT_LAYOUT1">CUST_IMG_PATH"\\\\MAINLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side1_Cnt1.gif"</IMAGE>
    <IMAGE id="IMG_ID_PICT_LAYOUT2">CUST_IMG_PATH"\\\\MAINLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side1_Cnt2.gif"</IMAGE>
    <IMAGE id="IMG_ID_PICT_LAYOUT4">CUST_IMG_PATH"\\\\MAINLCD\\\\Bluetooth\\\\BPP\\\\BPP_P_Side1_Cnt4.gif"</IMAGE>

<!-- 
**************************************** String section ***************************************
-->    
    <STRING id="STR_ID_PICT_TITLE"/>
    <STRING id="STR_ID_PICT_CONFIGURATION"/>
    <STRING id="STR_ID_PICT_SETTINGS"/>
    <STRING id="STR_ID_PICT_PREVIEW"/>
    <STRING id="STR_ID_PICT_PRINTING"/>
    <STRING id="STR_ID_PICT_QUERY"/>
    <STRING id="STR_ID_PICT_BRIDGE"/>
    <STRING id="STR_ID_PICT_PAPER_SIZE"/>
    <STRING id="STR_ID_PICT_COPIES"/>    
    <STRING id="STR_ID_PICT_PAGE_FORMAT"/>
    <STRING id="STR_ID_PICT_LAYOUT"/>
    <STRING id="STR_ID_PICT_BORDER"/>
    <STRING id="STR_ID_PICT_DATE_PRINT"/>
    <STRING id="STR_ID_PICT_FILENAME_PRINT"/>
    <STRING id="STR_ID_PICT_CROPPING"/>
    <STRING id="STR_ID_PICT_FIXED_SIZE"/>    
    
    <STRING id="STR_ID_PICT_ENABLE"/>
    <STRING id="STR_ID_PICT_DISABLE"/>
    <STRING id="STR_ID_PICT_STANDARD"/>
    <STRING id="STR_ID_PICT_MULTIPLE"/>
    <STRING id="STR_ID_PICT_INDEX"/>
    
    <STRING id="STR_ID_PICT_PAPER_POSTCARD"/>
    <STRING id="STR_ID_PICT_PAPER_4x6"/>
    <STRING id="STR_ID_PICT_PAPER_LETTER"/>
    <STRING id="STR_ID_PICT_PAPER_A4"/>
    
    <STRING id="STR_ID_PICT_ERROR"/>
    <STRING id="STR_ID_PICT_ERROR_ASK"/>
    <STRING id="STR_ID_PICT_ERROR_PAPER"/>
    <STRING id="STR_ID_PICT_ERROR_INK"/>
    <STRING id="STR_ID_PICT_ERROR_HARDWARE"/>
    <STRING id="STR_ID_PICT_ERROR_FILE"/>
    <STRING id="STR_ID_PICT_NO_PAPER"/>
    <STRING id="STR_ID_PICT_NO_INK"/>
    <STRING id="STR_ID_PICT_PRINTER_BUSY"/>
    <STRING id="STR_ID_PICT_PRINTER_REMOVED"/>
    <STRING id="STR_ID_PICT_PRINTER_CONNECTED"/>
    
#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__    
    <STRING id="STR_ID_PICT_MAX_FILES"/>
#endif
    
    <STRING id="STR_ID_PICT_X_COORDINATE"/>
    <STRING id="STR_ID_PICT_Y_COORDINATE"/>
    <STRING id="STR_ID_PICT_X_ARIX"/>
    <STRING id="STR_ID_PICT_Y_ARIX"/>
    
    <STRING id="STR_ID_PICT_CONNECT_TO_PC"/>
    <STRING id="STR_ID_PICT_INCOMPATIBLE_FILE"/>
    <STRING id="STR_ID_PICT_FILE_DELETED"/>
    <STRING id="STR_ID_PICT_INDEX_ALL"/>
    <STRING id="STR_ID_PICT_CMD_NOT_EXECUTED"/>
    <STRING id="STR_ID_PICT_USB_RESET"/>
    <STRING id="STR_ID_PICT_INVALID_JPG_FILE"/>
            
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
    <STRING id="STR_ID_PICT_JPG_FILE_SELECTED"/>
    <STRING id="STR_ID_PICT_JPG_FILES_SELECTED"/>
    <STRING id="STR_ID_PICT_JPG_FILES_LIMITATION"/>
    <STRING id="STR_ID_PICT_DRM_FILE_SELECTED"/>
    <STRING id="STR_ID_PICT_DRM_FILES_SELECTED"/>
    <STRING id="STR_ID_PICT_DRM_FILES_LIMITATION"/>
    <STRING id="STR_ID_PICT_BAD_FILE_SELECTED"/>
    <STRING id="STR_ID_PICT_BAD_FILES_SELECTED"/>
    <STRING id="STR_ID_PICT_BAD_FILES_LIMITATION"/>
    <STRING id="STR_ID_PICT_INV_FILE_SELECTED"/>
    <STRING id="STR_ID_PICT_INV_FILES_SELECTED"/>
    <STRING id="STR_ID_PICT_INV_FILES_LIMITATION"/>
    <STRING id="STR_ID_PICT_CONFIRM_FMGR_TO_PRINT"/>
    <STRING id="STR_ID_PICT_CONFIRM_FMGR_GO_BACK"/>    
#endif /* __MMI_FMGR_MULTI_SELECT_SUPPORT__ */

    <STRING id="STR_ID_PICT_CAPABILITY_CHANGE"/>    
    <STRING id="STR_ID_PICT_PAPER_L"/>    
    <STRING id="STR_ID_PICT_PAPER_2L"/>    
    <STRING id="STR_ID_PICT_PRINT_ABORTED"/>    
    <STRING id="STR_ID_PICT_MIN_APP"/>    
    

<!-- 
**************************************** Menu section *****************************************
-->

</APP>

#endif
