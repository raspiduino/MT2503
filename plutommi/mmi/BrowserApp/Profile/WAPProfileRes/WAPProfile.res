/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#ifdef __MMI_WAP_PROF__

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_MMI_WAP_PROF" name="STR_ID_WAP_PROF_CBM_BROWSER">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
#ifdef __COSMOS_MMI_PACKAGE__
    <MEMORY base="1300*1024" heap="300*1024" />
#endif
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
	<STRING id="STR_ID_WAP_PROF_CBM_BROWSER"/>

	<STRING id="STR_ID_WAP_PROF_DTCNT_ALREADY_CONFIGURED"/>

	<STRING id="STR_ID_WAP_PROF_PROV_BOOKMARKS_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_BOOKMARK"/>
	<STRING id="STR_ID_WAP_PROF_COLON_CHAR"/>
	<STRING id="STR_ID_WAP_PROF_PROV_ERR_MSG_BKM_NOT_AVAILABLE"/>
	<STRING id="STR_ID_WAP_PROF_ERR_MSG_INVALID_DATA_ACCOUNT"/>

#if defined(__MMI_MMS_2__)
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTINGS"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_CM_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_RM_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_MA_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_MS_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_PCADDR_COLON"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_RESTRICTED"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_WARNING"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_FREE"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_DISABLE"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_ENABLE"/>
	<STRING id="STR_ID_WAP_PROF_PROV_MMS_SETTING_VALUE_LOCKED"/>
#endif 
	
  
  <!------------------------------------------------------Other Resource---------------------------------------------------------->
	<SCREEN id="GRP_ID_WAP_PROF_DTCNT_DISPLAY"/>
    <SCREEN id="SCR_ID_WAP_PROF_PLEASE_WAIT"/>
    <SCREEN id="SCR_ID_WAP_PROF_PROV_DISPLAY_INFO"/>

    <CACHEDATA type="byte" id="NVRAM_WAP_PROF_ACTIVE_WAP_WLAN_PROFILE_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active WAP WLAN profile ID </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_WAP_PROFILE_INDEX">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_WAP_PROF_ACTIVE_WAP_PROFILE_INDEX </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_MMS_PROFILE_INDEX">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_WAP_PROF_ACTIVE_MMS_PROFILE_INDEX </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_WAP_SIM1_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active WAP SIM 1 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_WAP_SIM2_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active WAP SIM 2 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_MMS_SIM1_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active MMS SIM 1 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_MMS_SIM2_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active MMS SIM 2 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_WAP_SIM3_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active WAP SIM 3 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_WAP_SIM4_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active WAP SIM 4 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_MMS_SIM3_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active MMS SIM 3 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_MMS_SIM4_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active MMS SIM 4 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

 
</APP>
#endif

