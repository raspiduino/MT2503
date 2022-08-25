# Define the specified compile options to COMP_DEFS

# Define source file lists to SRC_LIST
SRC_LIST =

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Lib\m3d_adaption.c \
             vendor\intergrafx_hw\LW\Lib\M3DDummyGroup.c \
             vendor\intergrafx_hw\LW\Lib\M3DEventQueue.c \
             vendor\intergrafx_hw\LW\Lib\M3DMemory.c \
             vendor\intergrafx_hw\LW\Lib\M3DModel.c \
             vendor\intergrafx_hw\LW\Lib\M3DNodeStatus.c \
             vendor\intergrafx_hw\LW\Lib\M3DPhysics.c \
             vendor\intergrafx_hw\LW\Lib\M3DRenderer.c \
             vendor\intergrafx_hw\LW\Lib\M3DTextureManager.c \
             vendor\intergrafx_hw\LW\Lib\M3DUtils.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\vapp_wallpaper_mimosa.cpp
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\M3DLWMimosa.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\M3DLWMimosaContent.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pod_mimosa01.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pod_mimosa02.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pod_mimosa03.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pod_mimosa04.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pod_mimosa05.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pod_mimosa06.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pod_mimosa07.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pod_mimosa08.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pod_mimosa09.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pod_mimosa10.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa01.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa01a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa01n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa02.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa02a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa02n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa03.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa03a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa03n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa04.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa04a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa04n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa05.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa05a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa05n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa06.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa06a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa06n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa07.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa07a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa07n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa08.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa08a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa08n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa09.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa09a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa09n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa10.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa10a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa10n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa11.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa11a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa11n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa12.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa12a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa12n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa13.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa13a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa13n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa14.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa14a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa14n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa15.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa15a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa15n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa16.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa16a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa16n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa17.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa17a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa17n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa18.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa18a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa18n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa19.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa19a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa19n.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa20.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa20a.c
SRC_LIST += vendor\intergrafx_hw\LW\Mimosa\data\pvr_mimosa20n.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Girl\vapp_wallpaper_girl.cpp
SRC_LIST += vendor\intergrafx_hw\LW\Girl\M3DLWGirl.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\M3DLWGirlContent.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pod_girl01.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pod_girl02.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pod_girl03.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pod_girl04.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pod_girl05.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pod_girl06.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pod_girl07.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pod_girl08.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pod_girl09.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pod_girl10.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl01.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl01a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl01n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl02.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl02a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl02n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl03.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl03a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl03n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl04.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl04a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl04n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl05.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl05a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl05n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl06.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl06a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl06n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl07.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl07a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl07n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl08.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl08a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl08n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl09.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl09a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl09n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl10.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl10a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl10n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl11.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl11a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl11n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl12.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl12a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl12n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl13.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl13a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl13n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl14.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl14a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl14n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl15.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl15a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl15n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl16.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl16a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl16n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl17.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl17a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl17n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl18.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl18a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl18n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl19.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl19a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl19n.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl20.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl20a.c
SRC_LIST += vendor\intergrafx_hw\LW\Girl\data\pvr_girl20n.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Clock\vapp_wallpaper_clock.cpp
SRC_LIST += vendor\intergrafx_hw\LW\Clock\M3DLWClock.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\M3DLWClockContent.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pod_clock01.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pod_clock02.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pod_clock03.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pod_clock04.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pod_clock05.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pod_clock06.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pod_clock07.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pod_clock08.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pod_clock09.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pod_clock10.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock01.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock01a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock01n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock02.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock02a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock02n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock03.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock03a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock03n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock04.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock04a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock04n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock05.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock05a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock05n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock06.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock06a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock06n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock07.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock07a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock07n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock08.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock08a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock08n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock09.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock09a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock09n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock10.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock10a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock10n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock11.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock11a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock11n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock12.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock12a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock12n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock13.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock13a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock13n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock14.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock14a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock14n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock15.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock15a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock15n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock16.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock16a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock16n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock17.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock17a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock17n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock18.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock18a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock18n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock19.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock19a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock19n.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock20.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock20a.c
SRC_LIST += vendor\intergrafx_hw\LW\Clock\data\pvr_clock20n.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Horse\vapp_wallpaper_horse.cpp
SRC_LIST += vendor\intergrafx_hw\LW\Horse\M3DLWHorse.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\M3DLWHorseContent.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pod_horse01.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pod_horse02.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pod_horse03.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pod_horse04.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pod_horse05.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pod_horse06.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pod_horse07.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pod_horse08.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pod_horse09.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pod_horse10.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse01.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse01a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse01n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse02.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse02a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse02n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse03.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse03a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse03n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse04.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse04a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse04n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse05.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse05a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse05n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse06.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse06a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse06n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse07.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse07a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse07n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse08.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse08a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse08n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse09.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse09a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse09n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse10.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse10a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse10n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse11.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse11a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse11n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse12.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse12a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse12n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse13.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse13a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse13n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse14.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse14a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse14n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse15.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse15a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse15n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse16.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse16a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse16n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse17.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse17a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse17n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse18.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse18a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse18n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse19.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse19a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse19n.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse20.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse20a.c
SRC_LIST += vendor\intergrafx_hw\LW\Horse\data\pvr_horse20n.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\vapp_wallpaper_daydream.cpp
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\M3DLWDaydream.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\M3DLWDaydreamContent.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pod_daydream01.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pod_daydream02.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pod_daydream03.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pod_daydream04.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pod_daydream05.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pod_daydream06.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pod_daydream07.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pod_daydream08.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pod_daydream09.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pod_daydream10.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream01.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream01a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream01n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream02.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream02a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream02n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream03.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream03a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream03n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream04.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream04a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream04n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream05.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream05a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream05n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream06.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream06a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream06n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream07.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream07a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream07n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream08.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream08a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream08n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream09.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream09a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream09n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream10.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream10a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream10n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream11.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream11a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream11n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream12.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream12a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream12n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream13.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream13a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream13n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream14.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream14a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream14n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream15.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream15a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream15n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream16.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream16a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream16n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream17.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream17a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream17n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream18.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream18a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream18n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream19.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream19a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream19n.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream20.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream20a.c
SRC_LIST += vendor\intergrafx_hw\LW\Daydream\data\pvr_daydream20n.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\vapp_wallpaper_lighthouse.cpp
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\M3DLWLighthouse.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\M3DLWLighthouseContent.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pod_lighthouse01.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pod_lighthouse02.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pod_lighthouse03.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pod_lighthouse04.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pod_lighthouse05.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pod_lighthouse06.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pod_lighthouse07.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pod_lighthouse08.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pod_lighthouse09.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pod_lighthouse10.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse01.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse01a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse01n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse02.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse02a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse02n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse03.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse03a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse03n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse04.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse04a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse04n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse05.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse05a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse05n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse06.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse06a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse06n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse07.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse07a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse07n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse08.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse08a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse08n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse09.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse09a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse09n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse10.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse10a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse10n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse11.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse11a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse11n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse12.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse12a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse12n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse13.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse13a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse13n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse14.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse14a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse14n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse15.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse15a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse15n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse16.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse16a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse16n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse17.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse17a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse17n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse18.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse18a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse18n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse19.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse19a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse19n.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse20.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse20a.c
SRC_LIST += vendor\intergrafx_hw\LW\Lighthouse\data\pvr_lighthouse20n.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\vapp_wallpaper_puppy.cpp
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\M3DLWPuppy.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\M3DLWPuppyContent.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pod_puppy01.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pod_puppy02.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pod_puppy03.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pod_puppy04.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pod_puppy05.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pod_puppy06.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pod_puppy07.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pod_puppy08.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pod_puppy09.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pod_puppy10.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy01.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy01a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy01n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy02.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy02a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy02n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy03.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy03a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy03n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy04.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy04a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy04n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy05.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy05a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy05n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy06.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy06a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy06n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy07.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy07a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy07n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy08.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy08a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy08n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy09.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy09a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy09n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy10.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy10a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy10n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy11.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy11a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy11n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy12.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy12a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy12n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy13.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy13a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy13n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy14.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy14a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy14n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy15.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy15a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy15n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy16.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy16a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy16n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy17.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy17a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy17n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy18.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy18a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy18n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy19.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy19a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy19n.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy20.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy20a.c
SRC_LIST += vendor\intergrafx_hw\LW\Puppy\data\pvr_puppy20n.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Solar\vapp_wallpaper_solar.cpp
SRC_LIST += vendor\intergrafx_hw\LW\Solar\M3DLWSolar.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\M3DLWSolarContent.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pod_solar01.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pod_solar02.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pod_solar03.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pod_solar04.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pod_solar05.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pod_solar06.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pod_solar07.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pod_solar08.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pod_solar09.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pod_solar10.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar01.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar01a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar01n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar02.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar02a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar02n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar03.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar03a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar03n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar04.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar04a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar04n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar05.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar05a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar05n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar06.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar06a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar06n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar07.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar07a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar07n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar08.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar08a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar08n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar09.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar09a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar09n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar10.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar10a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar10n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar11.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar11a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar11n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar12.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar12a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar12n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar13.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar13a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar13n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar14.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar14a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar14n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar15.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar15a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar15n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar16.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar16a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar16n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar17.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar17a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar17n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar18.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar18a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar18n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar19.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar19a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar19n.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar20.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar20a.c
SRC_LIST += vendor\intergrafx_hw\LW\Solar\data\pvr_solar20n.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Fish\vapp_wallpaper_fish.cpp \
            vendor\intergrafx_hw\LW\Fish\M3DLWFish.c \
            vendor\intergrafx_hw\LW\Fish\M3DLWFishContent.c \
            vendor\intergrafx_hw\LW\Fish\data\pod_fish01.c \
            vendor\intergrafx_hw\LW\Fish\data\pod_fish02.c \
            vendor\intergrafx_hw\LW\Fish\data\pod_fish03.c \
            vendor\intergrafx_hw\LW\Fish\data\pod_fish04.c \
            vendor\intergrafx_hw\LW\Fish\data\pod_fish05.c \
            vendor\intergrafx_hw\LW\Fish\data\pod_fish06.c \
            vendor\intergrafx_hw\LW\Fish\data\pod_fish07.c \
            vendor\intergrafx_hw\LW\Fish\data\pod_fish08.c \
            vendor\intergrafx_hw\LW\Fish\data\pod_fish09.c \
            vendor\intergrafx_hw\LW\Fish\data\pod_fish10.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish01.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish01a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish01n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish02.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish02a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish02n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish03.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish03a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish03n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish04.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish04a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish04n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish05.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish05a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish05n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish06.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish06a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish06n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish07.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish07a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish07n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish08.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish08a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish08n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish09.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish09a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish09n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish10.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish10a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish10n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish11.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish11a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish11n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish12.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish12a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish12n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish13.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish13a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish13n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish14.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish14a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish14n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish15.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish15a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish15n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish16.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish16a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish16n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish17.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish17a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish17n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish18.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish18a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish18n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish19.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish19a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish19n.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish20.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish20a.c \
            vendor\intergrafx_hw\LW\Fish\data\pvr_fish20n.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\vapp_wallpaper_transformer.cpp
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\M3DLWTransformer.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\M3DLWTransformerContent.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pod_transformer01.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pod_transformer02.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pod_transformer03.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pod_transformer04.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pod_transformer05.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pod_transformer06.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pod_transformer07.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pod_transformer08.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pod_transformer09.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pod_transformer10.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer01.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer01a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer01n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer02.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer02a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer02n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer03.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer03a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer03n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer04.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer04a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer04n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer05.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer05a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer05n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer06.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer06a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer06n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer07.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer07a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer07n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer08.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer08a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer08n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer09.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer09a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer09n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer10.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer10a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer10n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer11.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer11a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer11n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer12.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer12a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer12n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer13.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer13a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer13n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer14.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer14a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer14n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer15.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer15a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer15n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer16.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer16a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer16n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer17.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer17a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer17n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer18.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer18a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer18n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer19.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer19a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer19n.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer20.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer20a.c
SRC_LIST += vendor\intergrafx_hw\LW\Transformer\data\pvr_transformer20n.c
endif


ifneq ($(filter __COSMOS_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += vendor\intergrafx_hw\Game\Vapp_3d_game.cpp
endif

ifneq ($(filter __MMI_3D_GAME_INTERGRAFX__, $(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx_hw\Game\ig3d_adaptation56.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_Background.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_Background_A.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_CHS_WordTexure.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_CHS_WordTexure_A.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_ENG_WordTexure.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_ENG_WordTexure_A.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_Function.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_Launcher.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_Main.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_SomeTexure.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_SomeTexure_A.c \
            vendor\intergrafx_hw\Game\Launcher\IG_LA_Var.c
endif


# Define include path lists to INC_DIR
INC_DIR = venusmmi\vrt\interface \
          venusmmi\framework \
          venusmmi\framework\interface \
          venusmmi\visual \
          venusmmi\visual\interface \
          venusmmi\app\common \
          venusmmi\app\common\interface \
          venusmmi\app\common\interface\cp \
          venusmmi\app\common\interface\service \
          venusmmi\app\common\clipboard \
          venusmmi\app\common\wallpaper \
          venusmmi\app\common\platform \
          venusmmi\app\common\message \
          venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\test\common \
          venusmmi\test\app \
          venusmmi\test\cp \
          venusmmi\test\vrt \
          venusmmi\test\framework\ui_core \
          venusmmi\test\framework\mmi_core \
          venusmmi\test\framework\xml \
          venusmmi\app \
          venusmmi\app\pluto_variation \
          venusmmi\framework\mmi_core \
          venusmmi\framework\ui_core\base \
          venusmmi\framework\ui_core\mvc \
          venusmmi\framework\ui_core\pme \
          venusmmi\framework\xml \
          venusmmi\app\common\data \
          venusmmi\app\common\ime \
          venusmmi\app\pluto_variation\adapter\interface\trc \
          venusmmi\app\pluto_variation\adapter\Framework \
          venusmmi\app\pluto_variation\adapter\GUI \
          venusmmi\visual\cp \
          venusmmi\visual\cp\common \
          venusmmi\visual\cp\cosmos \
          venusmmi\visual\cp\fte \
          applib\inet\engine\include \
          applib\mem\include \
          applib\misc\include \
          applib\kazlib \
          drv\include \
          fmt\include \
          fs\fat\include \
          interface\hwdrv \
          plutommi\customer\customerinc \
          plutommi\customer\customize \
          plutommi\customer\custresource \
          plutommi\mmi\asyncevents\asynceventsinc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\menuid \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\EventHandling\eventsinc \
          plutommi\Framework\History\historyinc \
          plutommi\Framework\MemManager\memmanagerinc \
          plutommi\Framework\NVRAMManager\nvrammanagerinc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\ThemeManager\thememanagerinc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\cui\inc \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\Framework\GDI\gdiinc \
          plutommi\service\mdi\mdiinc \
          plutommi\mtkapp\mtkappinc \
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\InputMethod\UI\UI_Inc \
          plutommi\mmi\CubeApp\CubeAppInc \
          plutommi\mmi\ShellApp\ShellAppInc \
          btstacka\inc \
          drm\include \
          irda\inc \
          media\image\include \
          media\rtp\inc \
          media\stream\include \
          usb\include \
          verno \
          wapadp\include \
          xmlp\include \
          plutommi\mmi\athandler\athandlerinc \
          plutommi\mmi\audio\audioinc \
          plutommi\Framework\BIDI\bidiinc \
          plutommi\Framework\CommonScreens\commonscreensinc \
          plutommi\mmi\cphs\cphsinc \
          plutommi\mmi\customerservice\customerserviceinc \
          plutommi\mmi\dataaccount\dataaccountinc \
          plutommi\mmi\datetime\datetimeinc \
          plutommi\Framework\DebugLevels\debuglevelinc \
          plutommi\mmi\dictionary\dictinc \
          plutommi\mmi\ebookreader\ebookinc \
          plutommi\mmi\emailapp\emailappinc \
          plutommi\mmi\extra\extrainc \
          plutommi\mmi\funandgames\funandgamesinc \
          plutommi\mmi\gpio\gpioinc \
          plutommi\service\gpiosrv \
          plutommi\mmi\gsmcallapplication\commonfiles\commoninc \
          plutommi\mmi\gsmcallapplication\incomingcallmanagement\incominginc \
          plutommi\mmi\gsmcallapplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\help\helpinc \
          plutommi\mmi\idlescreen\idlescreeninc \
          plutommi\mmi\idlescreen\idlescreeninc\demoappinc \
          plutommi\MMI\Idle\IdleInc \
          plutommi\MMI\Dialer\DialerInc \
          plutommi\MMI\ScrLocker\ScrLockerInc \
          plutommi\MMI\ScrSaver\ScrSaverInc \
          plutommi\mmi\imps\impsinc \
          plutommi\Framework\IndicLanguages\indiclanguagesinc \
          plutommi\Framework\LangModule\LangModuleInc \
          plutommi\mmi\mainmenu\mainmenuinc \
          plutommi\mmi\messages \
          plutommi\mmi\messages\messagesinc \
          plutommi\mmi\mobileservice\mobileserviceinc \
          plutommi\Framework\MTE\mteinc \
          plutommi\Framework\MSLT\msltinc \
          plutommi\mmi\nitzhandler\nitzinc \
          plutommi\mmi\organizer\organizerinc \
          plutommi\mmi\phonebook\phonebookinc \
          plutommi\mmi\profiles\profilesinc \
          plutommi\mmi\resource\inc \
          plutommi\mmi\sat\satinc \
          plutommi\mmi\setting\settinginc \
          plutommi\mmi\smartmessage\smartmessageinc \
          plutommi\AppCore\ssc \
          plutommi\MMI\SimSpace\SimSpaceInc \
          plutommi\Service\Inc \
          plutommi\Service\UmSrv \
          plutommi\Service\UmmsSrv \
          plutommi\mmi\unifiedcomposer\unifiedcomposerinc \
          plutommi\mmi\unifiedmessage\unifiedmessageinc \
          plutommi\mmi\unifiedmms\mmsapp\mmsappinc \
          plutommi\mmi\voip\voipinc \
          plutommi\mtkapp\abrepeater\abrepeaterinc \
          plutommi\mtkapp\audioplayer\audioplayerinc \
          plutommi\mtkapp\MediaPlayer\MediaPlayerInc \
          plutommi\mtkapp\avatar\avatarinc \
          plutommi\mtkapp\barcodereader\barcodereaderinc \
          plutommi\mtkapp\bgsound\bgsoundinc \
          plutommi\mtkapp\camera\camerainc \
          plutommi\mtkapp\ImageView\ImageViewInc \
          plutommi\mtkapp\camcorder\camcorderinc \
          plutommi\mtkapp\centralconfigagent\centralconfigagentinc \
          plutommi\mtkapp\connectivity\connectivityinc \
          plutommi\mtkapp\connectivity\connectivityinc\btcommon \
          plutommi\mtkapp\connectivity\connectivityinc\btmtk \
          plutommi\Framework\CSBrowser\csbrowserinc \
          plutommi\mtkapp\DCD\DCDInc \
          plutommi\mtkapp\dlagent\dlagentinc \
          plutommi\mtkapp\dmuiapp\dmuiappinc \
          plutommi\mtkapp\filemgr\filemgrinc \
          plutommi\mtkapp\fmradio\fmradioinc \
          plutommi\mtkapp\fmschedulerec\fmschedulerecinc \
          plutommi\mtkapp\GPS\GPSInc \
          plutommi\mtkapp\javaagency\javaagencyinc \
          plutommi\mtkapp\mmiapi\include \
          plutommi\mtkapp\mobiletvplayer\mobiletvplayerinc \
          plutommi\mtkapp\myfavorite\myfavoriteinc \
          plutommi\mtkapp\photoeditor\photoeditorinc \
          plutommi\mtkapp\pictbridge\pictbridgeinc \
          plutommi\mtkapp\rightsmgr\rightsmgrinc \
          plutommi\MtkApp\SoftwareTracer\SoftwareTracerInc \
          plutommi\mtkapp\soundrecorder\soundrecorderinc \
          plutommi\mtkapp\sndrec\sndrecinc \
          plutommi\mtkapp\answermachine\answermachineinc \
          plutommi\mtkapp\swflash\swflashinc \
          plutommi\mtkapp\syncml\syncmlinc \
          plutommi\mtkapp\video\videoinc \
          plutommi\mtkapp\vobjects\vobjectinc \
          plutommi\mtkapp\vrsd\vrsdinc \
          plutommi\mtkapp\vrsi\vrsiinc \
          plutommi\mtkapp\MREAPP\MREAPPInc \
          plutommi\vendorapp\devapp\devappinc \
          plutommi\Service\PlstSrv \
          plutommi\Service\MediaCacheSrv \
          plutommi\mmi\ipsecapp\ipsecappinc \
          plutommi\mmi\UDX\UDXInc \
          plutommi\mtkapp\SearchWeb\SearchWebInc \
          plutommi\Service\inc \
          applib\sqlite3\inc \
          vendor\player\ipeer\inc \
          plutommi\MtkApp\WgtMgrApp\WgtMgrAppInc \
          plutommi\MtkApp\NPPlg\NPPlgInc \
          vendor\widget\google\adaptation\extensions\maui_audio_framework \
          vendor\widget\google\adaptation \
          plutommi\MtkApp\WidgetDelegator\WidgetDelegatorInc \
          vendor\opera\browser\v1_official\opdev\include \
          vendor\opera\browser\adaptation\inc \
          plutommi\mmi\CallLog\CallLogInc \
          plutommi\Service\ProfilesSrv \
          plutommi\CUI\ImageViewCui \
          plutommi\MMI\PhoneBook\Core \
          venusmmi\app\pluto_variation\ShellApp\base \
          venusmmi\app\pluto_variation\ShellApp\panel \
          venusmmi\app\pluto_variation\ShellApp\panel\HomeScreen \
          venusmmi\app\pluto_variation\ShellApp\panel\RecentCalls \
          venusmmi\app\pluto_variation\ShellApp\panel\ImageViewer \
          venusmmi\app\pluto_variation\ShellApp\panel\Shortcuts \
          venusmmi\app\pluto_variation\ShellApp\panel\MsgViewer \
          venusmmi\app\pluto_variation\ShellApp\panel\FavoriteContacts \
          venusmmi\app\pluto_variation\ShellApp\panel\MediaPlayer \
          venusmmi\app\pluto_variation\ShellApp\panel\Settings \
          venusmmi\app\pluto_variation\ShellApp\panel\OP01HomeScreen \
          venusmmi\app\pluto_variation\adapter\ShellApp\base \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\HomeScreen \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\MediaPlayer \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\ImageViewer \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\Shortcuts \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\MsgViewer \
          venusmmi\app\pluto_variation\adapter\ShellApp\panel\OP01HomeScreen \
          venusmmi\app\pluto_variation\adapter\MediaWall \
          venusmmi\app\pluto_variation\adapter\MultiTouchTest \
          venusmmi\app\pluto_variation\MultiTouchTest \
          venusmmi\app\Cosmos\interface\cui \
          venusmmi\app\Cosmos\WidgetDelegator \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\pluto_variation\adapter\ime \
          plutommi\Framework\InputMethod\inc \
          interface\hal\drv_sw_def \
          venusmmi\app\pluto_variation\ImageFlow \
          vendor\intergrafx_hw\LW\Mimosa \
          vendor\intergrafx_hw\LW\Girl \
          vendor\intergrafx_hw\LW\Clock \
          vendor\intergrafx_hw\LW\Horse \
          vendor\intergrafx_hw\LW\Daydream \
          vendor\intergrafx_hw\LW\Lighthouse \
          vendor\intergrafx_hw\LW\Puppy \
          vendor\intergrafx_hw\LW\Solar \
          vendor\intergrafx_hw\LW\Fish \
          vendor\intergrafx_hw\LW\Transformer \
          vendor\intergrafx_hw\Game \
          vendor\intergrafx_hw\LW\Include \
          vendor\intergrafx_hw\Game\Launcher \
          vendor\intergrafx_hw\Engine\IGV5Inc

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif
