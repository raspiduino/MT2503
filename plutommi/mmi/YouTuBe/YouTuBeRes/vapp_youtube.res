/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#if defined(__MMI_YOUTUBE_SHORTCUT__)

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_YOUTUBE"
#if defined(__MMI_APP_MANAGER_SUPPORT__)
    package_name="native.mtk.youtube" 
    name="STR_ID_APP_YOUTUBE"
    img="IMG_ID_APP_YOUTUBE" 
    launch="vapp_youtube_launch"
#else /* __MMI_APP_MANAGER_SUPPORT__ */
    name="STR_ID_APP_YOUTUBE"
#endif    
>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_APP_YOUTUBE"/> 
    
    <!-----------------------------------------------------Image Resource Area----------------------------------------------------->
    <IMAGE id="IMG_ID_APP_YOUTUBE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\Youtube.png"</IMAGE>
    
</APP>

#endif /*__MMI_YOUTUBE_SHORTCUT__*/

