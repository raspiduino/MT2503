#include "MMI_features.h"
#ifdef __MMI_STREAMING__
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_STREAMING">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    
    <!-------------------------------------------- String Resource Area ----------------------------------------------->
    <STRING id="STR_ID_STREAMING"/>
    <STRING id="STR_ID_STREAMING_COLON"/>
    <STRING id="STR_ID_STREAMING_PROF_NAME"/>
    <STRING id="STR_ID_STREAMING_PROFILE_DEFAULT_NAME"/>
    <STRING id="STR_ID_STREAMING_IS_USE_PROXY"/>
    <STRING id="STR_ID_STREAMING_PROXY_ADDR"/>    
    <STRING id="STR_ID_STREAMING_PROXY_PORT"/>    
    <STRING id="STR_ID_STREAMING_MIN_UDP_PORT"/>    
    <STRING id="STR_ID_STREAMING_MAX_UDP_PORT"/>    
    <STRING id="STR_ID_STREAMING_END"/>  

    <!---------------------------------------------- Image Resource Area ---------------------------------------------->         

    <!------------------------------------------------- Screen ID ----------------------------------------------------->

    <SCREEN id = "SCR_ID_STREAMING_START"/>
    <SCREEN id = "GRP_ID_STREAMING_OTA_INSTALLATION"/>
    <SCREEN id = "GRP_ID_STREAMING_OTA_REPLACE_LIST"/>
    <SCREEN id = "SCR_ID_STREAMING_OTA_INSTALLATION"/>
    <SCREEN id = "SCR_ID_STREAMING_OTA_REPLACE_LIST"/>    
    <SCREEN id = "SCR_ID_STREAMING_END"/>


    <!--------------------------------------------- Menu Resource Area ------------------------------------------------>

   
    
	<!----------------------------------------------- Other Resource -------------------------------------------------->
    
</APP>

#endif  /* __MMI_STREAMING__ */
