# Define source file lists to SRC_LIST
SRC_LIST = vendor\mcare\adaption\api\McfOsWrapper.c \
           vendor\mcare\adaption\MAdpConfig.c \
           vendor\mcare\adaption\MAdpMenu.c \
           vendor\mcare\adaption\api\McfZlib.c \
           vendor\mcare\adaption\vapp_mcare_ncenter.cpp \
           vendor\mcare\adaption\resource\romizeddata\MAdpResData.c \
           vendor\mcare\adaption\resource\romizeddata\MAdpCfgRomData.c \
           vendor\mcare\adaption\vapp_mcare.cpp \
           vendor\mcare\adaption\MadpDummy.c
 
# Define include path lists to INC_DIR
INC_DIR = plutommi\mtkapp\Camcorder\CamcorderInc \
            plutommi\MtkApp\MtkAppInc \
            plutommi\MtkApp\Connectivity\ConnectivityInc \
            plutommi\MtkApp\Connectivity\ConnectivityInc\BtCommon \
            plutommi\MtkApp\SoundRecorder\SoundRecorderInc \
            plutommi\MtkApp\AudioPlayer\AudioPlayerInc \
            plutommi\MtkApp\ABRepeater\ABRepeaterInc \
            plutommi\mmi\asyncevents\AsyncEventsInc \
            plutommi\mmi\Audio\AudioInc \
            plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc \
            plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc \
            plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc \
            plutommi\Customer\custresource \
            plutommi\mmi\DateTime\DateTimeInc \
            plutommi\Framework\DebugLevels\debuglevelInc \
            plutommi\Framework\CommonFiles\CommonInc \
            plutommi\Framework\Tasks\tasksinc \
            plutommi\Framework\History\historyInc \
            plutommi\Framework\EventHandling\EventsInc \
            plutommi\Framework\MemManager\MemManagerInc \
            plutommi\Framework\NVRAMManager\NVRAMManagerInc \
            plutommi\Framework\ThemeManager\ThemeManagerInc \
            plutommi\mmi\FunAndGames\FunAndGamesInc \
            plutommi\Framework\GUI\gui_inc \
            plutommi\Framework\GUI\oem_inc \
            plutommi\MMI\IdleScreen\IdleScreenInc \
            plutommi\MMI\IdleScreen\IdleScreenInc\DemoAppInc \
            plutommi\mmi\inc \
            plutommi\Framework\Interface \
            plutommi\Framework\InputMethod\inc \
            plutommi\mmi\inc\MenuID \
            plutommi\mmi\MainMenu\MainMenuInc \
            plutommi\mmi\Messages\MessagesInc \
            plutommi\MMI\Messages \
            plutommi\mmi\miscframework\miscframeworkinc \
            plutommi\mmi\phonebook\PhonebookInc \
            plutommi\mmi\profiles\ProfilesInc \
            plutommi\mmi\sat\satInc \
            plutommi\mmi\Setting\SettingInc \
            plutommi\MMI\gpio\gpioInc \
            plutommi\MMI\DataAccount\DataAccountInc \
            plutommi\MMI\Help\HelpInc \
            plutommi\MMI\Organizer\OrganizerInc \
            plutommi\MMI\Extra\ExtraInc \
            plutommi\mmi\ATHandler\ATHandlerInc \
            plutommi\mmi\NITZHandler\NITZInc \
            fs\fat\include \
            plutommi\Framework\CommonScreens\commonscreensInc \
            plutommi\mmi\CPHS\CPHSInc \
            plutommi\customer\customerinc \
            plutommi\MtkApp\FileMgr\FileMgrInc \
            plutommi\MtkApp\Camera\CameraInc \
            plutommi\MtkApp\Video\VideoInc \
            plutommi\Framework\GDI\GDIInc \
            plutommi\MtkApp\mmiapi\include \
            interface\hwdrv \
            wapadp\include \
            fmt\include \
            irda\inc \
            plutommi\MtkApp\vObjects\vObjectInc \
            plutommi\MtkApp\FMRadio\FMRadioInc \
            plutommi\MtkApp\FMScheduleRec\FMScheduleRecInc \
            plutommi\MMI\EmailApp\EmailAppInc \
            drm\include \
            plutommi\MtkApp\VRSD\VRSDInc \
            plutommi\MtkApp\VRSI\VRSIInc \
            plutommi\MtkApp\PhotoEditor\PhotoEditorInc \
            applib\misc\include \
            plutommi\MtkApp\BGSound\BGSoundInc \
            xmlp\include \
            plutommi\MtkApp\JavaAgency\JavaAgencyInc \
            plutommi\VendorApp\DevApp\DevAppInc \
            plutommi\VendorApp\APPSDK\APPSDKInc \
            plutommi\VendorApp\DevConfig\DevConfigInc \
            applib\mem\include \
            plutommi\AppCore\Ucm \
            plutommi\CUI\Inc \
            plutommi\Service\Inc \
            venusmmi\vrt\interface \
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
            venusmmi\test \
            venusmmi\app \
            venusmmi\app\pluto_variation \
            venusmmi\app\pluto_variation\interface \
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
            venusmmi\visual\cp\fte \
            venusmmi\visual\cp\cosmos \
            venusmmi\app\Cosmos\interface\app \
            venusmmi\app\Cosmos\interface\cui \
            plutommi\Service\Dtcntsrv \
            plutommi\Customer\CustResource\PLUTO_MMI \
            interface\wap\
            plutommi\service\MDI\MDIInc \
            plutommi\mtkapp\MREAPP\MREAPPInc \
            plutommi\framework\commonfiles\commoninc \
            plutommi\framework\commonfiles\commoninc\depreciation \
            plutommi\Framework\bidi\bidiinc \
            plutommi\framework\history\historysrc\
            plutommi\service\inc \
            plutommi\AppCore\SSC \
            venusmmi\app\common\ncenter \
            vendor\mcare\adaption\api\inc \
            vendor\mcare\adaption\resource \
            vendor\mcare\adaption\resource\romizeddata \
            plutommi\Service\ProfilesSrv \
            venusmmi\app\common\interface\app



ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
		INC_DIR +=          venusmmi\app\Cosmos\ucm 
else
		INC_DIR +=           plutommi\mmi\ucm\ucminc 
endif


# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P  \
            _TENCENT_MCARE_ADP_

ifneq ($(filter PLUTO_MMI COSMOS_MMI,$(strip $(call Upper,$(MMI_VERSION)))),)
ifeq ($(call Upper,$(strip $(LEVEL))),VENDOR)
  COMP_DEFS += __DEVAPP_RESOURCE_OUTPUT__
endif
endif
