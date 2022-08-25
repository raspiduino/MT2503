# Define the specified compile options to COMP_DEFS

# Define source file lists to SRC_LIST
SRC_LIST =

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\WPLib\CMemory.c
SRC_LIST += vendor\intergrafx\LW\WPLib\CNodeStatus.c
SRC_LIST += vendor\intergrafx\LW\WPLib\CUtils.c
SRC_LIST += vendor\intergrafx\LW\WPLib\V3DataDef.c
SRC_LIST += vendor\intergrafx\LW\WPLib\V3Renderer.c
SRC_LIST += vendor\intergrafx\LW\WPLib\V3Retained.c
SRC_LIST += vendor\intergrafx\LW\WPLib\V3TextureManager.c
SRC_LIST += vendor\intergrafx\LW\WPLib\V3UI.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_01.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_02.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_03.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_04.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_05.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_06.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_07.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_08.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_09.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_10.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_11.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_12.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_13.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_14.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_15.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_16.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_17.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_18.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_19.c
SRC_LIST += vendor\intergrafx\LW\WPLib\data\png_WPLib_20.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\Mimosa\vapp_wallpaper_mimosa.cpp
SRC_LIST += vendor\intergrafx\LW\Mimosa\WP1-A-GameApp.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\WP1-A-Name.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\WP1-A-Status.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\igf_WP1_A.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_01.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_02.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_03.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_04.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_05.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_06.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_07.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_08.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_09.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_10.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_11.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_12.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_13.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_14.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_15.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_16.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_17.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_18.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_19.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_20.c
SRC_LIST += vendor\intergrafx\LW\Mimosa\data\png_WP1_A_back.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\Girl\vapp_wallpaper_girl.cpp
SRC_LIST += vendor\intergrafx\LW\Girl\WP2-B-GameApp.c
SRC_LIST += vendor\intergrafx\LW\Girl\WP2-B-GirlStatus.c
SRC_LIST += vendor\intergrafx\LW\Girl\WP2-B-Name.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\igf_WP2_B.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_01.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_02.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_03.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_04.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_05.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_06.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_07.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_08.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_09.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_10.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_11.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_12.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_13.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_14.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_15.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_16.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_17.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_18.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_19.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_20.c
SRC_LIST += vendor\intergrafx\LW\Girl\data\png_WP2_B_back.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\Clock\vapp_wallpaper_clock.cpp
SRC_LIST += vendor\intergrafx\LW\Clock\WP2-C-GameApp.c
SRC_LIST += vendor\intergrafx\LW\Clock\WP2-C-Name.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\igf_WP2_C.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_01.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_02.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_03.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_04.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_05.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_06.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_07.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_08.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_09.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_10.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_11.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_12.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_13.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_14.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_15.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_16.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_17.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_18.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_19.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_20.c
SRC_LIST += vendor\intergrafx\LW\Clock\data\png_WP2_C_back.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\Horse\vapp_wallpaper_horse.cpp
SRC_LIST += vendor\intergrafx\LW\Horse\WP2-D-GameApp.c
SRC_LIST += vendor\intergrafx\LW\Horse\WP2-D-HorseStatus.c
SRC_LIST += vendor\intergrafx\LW\Horse\WP2-D-Name.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\igf_WP2_D.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_01.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_02.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_03.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_04.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_05.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_06.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_07.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_08.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_09.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_10.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_11.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_12.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_13.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_14.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_15.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_16.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_17.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_18.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_19.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_20.c
SRC_LIST += vendor\intergrafx\LW\Horse\data\png_WP2_D_back.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\Daydream\vapp_wallpaper_daydream.cpp
SRC_LIST += vendor\intergrafx\LW\Daydream\WP2-E-CashStatus.c
SRC_LIST += vendor\intergrafx\LW\Daydream\WP2-E-GameApp.c
SRC_LIST += vendor\intergrafx\LW\Daydream\WP2-E-Name.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\igf_WP2_E.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_01.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_02.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_03.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_04.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_05.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_06.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_07.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_08.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_09.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_10.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_11.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_12.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_13.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_14.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_15.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_16.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_17.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_18.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_19.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_20.c
SRC_LIST += vendor\intergrafx\LW\Daydream\data\png_WP2_E_back.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\Lighthouse\vapp_wallpaper_lighthouse.cpp
SRC_LIST += vendor\intergrafx\LW\Lighthouse\WP3-A-GameApp.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\WP3-A-Name.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\igf_WP3_A.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_01.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_02.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_03.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_04.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_05.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_06.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_07.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_08.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_09.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_10.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_11.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_12.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_13.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_14.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_15.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_16.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_17.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_18.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_19.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_20.c
SRC_LIST += vendor\intergrafx\LW\Lighthouse\data\png_WP3_A_back.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\Puppy\vapp_wallpaper_puppy.cpp
SRC_LIST += vendor\intergrafx\LW\Puppy\WP3-B-DogStatus.c
SRC_LIST += vendor\intergrafx\LW\Puppy\WP3-B-GameApp.c
SRC_LIST += vendor\intergrafx\LW\Puppy\WP3-B-Name.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\igf_WP3_B.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_01.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_02.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_03.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_04.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_05.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_06.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_07.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_08.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_09.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_10.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_11.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_12.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_13.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_14.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_15.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_16.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_17.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_18.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_19.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_20.c
SRC_LIST += vendor\intergrafx\LW\Puppy\data\png_WP3_B_back.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\Solar\vapp_wallpaper_solar.cpp
SRC_LIST += vendor\intergrafx\LW\Solar\WP3-C-GameApp.c
SRC_LIST += vendor\intergrafx\LW\Solar\WP3-C-Name.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\igf_WP3_C.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_01.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_02.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_03.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_04.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_05.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_06.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_07.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_08.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_09.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_10.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_11.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_12.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_13.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_14.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_15.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_16.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_17.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_18.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_19.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_20.c
SRC_LIST += vendor\intergrafx\LW\Solar\data\png_WP3_C_back.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\Fish\vapp_wallpaper_fish.cpp
SRC_LIST += vendor\intergrafx\LW\Fish\WP3-D-FishStatus.c
SRC_LIST += vendor\intergrafx\LW\Fish\WP3-D-GameApp.c
SRC_LIST += vendor\intergrafx\LW\Fish\WP3-D-Name.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\igf_WP3_D.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_01.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_02.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_03.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_04.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_05.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_06.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_07.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_08.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_09.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_10.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_11.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_12.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_13.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_14.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_15.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_16.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_17.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_18.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_19.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_20.c
SRC_LIST += vendor\intergrafx\LW\Fish\data\png_WP3_D_back.c
endif

ifneq ($(filter __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__,$(strip $(MODULE_DEFS))),)
SRC_LIST += vendor\intergrafx\LW\Transformer\vapp_wallpaper_transformer.cpp
SRC_LIST += vendor\intergrafx\LW\Transformer\WP4-A-GameApp.c
SRC_LIST += vendor\intergrafx\LW\Transformer\WP4-A-Name.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\igf_WP4_A.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_01.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_02.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_03.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_04.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_05.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_06.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_07.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_08.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_09.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_10.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_11.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_12.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_13.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_14.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_15.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_16.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_17.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_18.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_19.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_20.c
SRC_LIST += vendor\intergrafx\LW\Transformer\data\png_WP4_A_back.c
endif


ifneq ($(filter __COSMOS_MMI_PACKAGE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += vendor\intergrafx\Game\Vapp_3d_game.cpp
endif

ifneq ($(filter __MMI_3D_GAME_INTERGRAFX__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += vendor\intergrafx\Game\Launcher\IG_background.c \
           vendor\intergrafx\Game\Launcher\IG_BrickGameStart.c \
           vendor\intergrafx\Game\Launcher\IG_Brick_Title.c \
           vendor\intergrafx\Game\Launcher\IG_Button.c \
           vendor\intergrafx\Game\Launcher\IG_Button1.c \
           vendor\intergrafx\Game\Launcher\IG_Button2.c \
           vendor\intergrafx\Game\Launcher\IG_Button3.c \
           vendor\intergrafx\Game\Launcher\IG_DanceGameStart.c \
           vendor\intergrafx\Game\Launcher\IG_DA_Title.c \
           vendor\intergrafx\Game\Launcher\IG_Exit.c \
           vendor\intergrafx\Game\Launcher\IG_FlowerGameStart.c \
           vendor\intergrafx\Game\Launcher\IG_Flower_Title.c \
           vendor\intergrafx\Game\Launcher\IG_LA_bosha.c \
           vendor\intergrafx\Game\Launcher\IG_LA_backgroung_02.c \
           vendor\intergrafx\Game\Launcher\IG_LA_ch_01.c \
           vendor\intergrafx\Game\Launcher\IG_LA_ch_02.c \
           vendor\intergrafx\Game\Launcher\IG_LA_ch_03.c \
           vendor\intergrafx\Game\Launcher\IG_LA_ch_04.c \
           vendor\intergrafx\Game\Launcher\IG_LA_ch_05.c \
           vendor\intergrafx\Game\Launcher\IG_Start.c \
           vendor\intergrafx\Game\Launcher\IG_TankGameStart.c \
           vendor\intergrafx\Game\Launcher\IG_TF_Title.c \
           vendor\intergrafx\Game\Launcher\IG_LA_Utils.c \
           vendor\intergrafx\Game\Launcher\IG_LA_ST_02.c \
           vendor\intergrafx\Game\Launcher\Launcher.c \
           vendor\intergrafx\Game\adaptation\ig3d_adaptation.c   
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
          vendor\intergrafx\Engine\IGV3Inc \
          vendor\intergrafx\LW\WPLib \
          vendor\intergrafx\LW\Mimosa \
          vendor\intergrafx\LW\Girl \
          vendor\intergrafx\LW\Clock \
          vendor\intergrafx\LW\Horse \
          vendor\intergrafx\LW\Daydream \
          vendor\intergrafx\LW\Lighthouse \
          vendor\intergrafx\LW\Puppy \
          vendor\intergrafx\LW\Solar \
          vendor\intergrafx\LW\Fish \
          vendor\intergrafx\LW\Transformer \
          vendor\intergrafx\Game\Adaptation \
          vendor\intergrafx\Game\Launcher

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
INC_DIR += venusmmi\app\Cosmos\Ucm
else
INC_DIR += plutommi\mmi\Ucm\UcmInc
endif