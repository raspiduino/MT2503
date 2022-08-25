
ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_SLIM)
SRC_LIST = vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_File.c \
           vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_HWPlat.c \
           vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_SMDSysPort.c \
           vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_SystemPlat.c \
           vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_WG_PlatUi.c \
           vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_WG_SYSApp.c \
           vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_PlatIme.c \
           vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_WG_LACInf.c \
           vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_WG_NetSearch.c
           
					 
# Define include path lists to INC_DIR
ifeq ($(strip $(MMIDIR)),plutommi)
INC_DIR = applib\mem\include \
          vendor\inputmethod\GUOBI\project\plutommi\v5_2_demo\inc \
          vendor\InputMethod\GUOBI\project\plutommi\v5_2_slim\inc \
          plutommi\Service\SimCtrlSrv \
          plutommi\Service\UmmsSrv \
          plutommi\service\smssrv\
          plutommi\CUI\Inc \
          plutommi\Framework\BIDI\BIDIInc \
          plutommi\Framework\IndicLanguages\IndicLanguagesInc \
          plutommi\mmi\asyncevents\AsyncEventsInc \
          plutommi\mmi\Audio\AudioInc \
          plutommi\mmi\PROFILES\ProfilesInc \
          plutommi\mmi\GSMCallApplication\CommonFiles\CommonInc \
          plutommi\mmi\GSMCallApplication\outgoingcallmanagement\outgoinginc \
          plutommi\mmi\GSMCallApplication\incomingcallmanagement\incominginc \
          plutommi\mmi\DateTime\DateTimeInc \
          plutommi\Framework\DebugLevels\debuglevelInc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\History\historyInc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\mmi\FunAndGames\FunAndGamesInc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\MMI\IdleScreen\IdleScreenInc\DemoAppInc \
          plutommi\mmi\inc \
          plutommi\mmi\calllog\callloginc \
          plutommi\Framework\Interface \
          plutommi\Framework\scenario \
          plutommi\mmi\inc\MenuID \
          plutommi\mmi\MainMenu\MainMenuInc \
          plutommi\mmi\Messages\MessagesInc \
          plutommi\mmi\miscframework\miscframeworkinc \
          plutommi\mmi\phonebook\PhonebookInc \
          plutommi\mmi\sat\satInc \
          plutommi\mmi\Setting\SettingInc \
          plutommi\Service\DtcntSrv \
          plutommi\Framework\CommonScreens\CommonScreensInc \
          plutommi\MtkApp\MtkAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
          plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
          plutommi\MtkApp\SoundRecorder\SoundRecorderInc \
          plutommi \
          plutommi\customer\customerinc \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\MtkApp\AudioPlayer\AudioPlayerInc \
          plutommi\MtkApp\FileMgr\FileMgrInc \
          plutommi\Framework\GDI\GDIInc \
          applib\misc\include \
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\ui\ui_Inc \
          plutommi\mmi\browserapp\browser\browserinc \
          plutommi\service\browsersrv \
          plutommi\service\wappushsrv \
          plutommi\mtkapp\searchweb\searchwebinc \
          venusmmi\app \
          venusmmi\app\Cosmos\Alarm \
          venusmmi\app\Cosmos\AppManager \
          venusmmi\app\Cosmos\Bluetooth \
          venusmmi\app\Cosmos\CBApp \
          venusmmi\app\Cosmos\CallLog \
          venusmmi\app\Cosmos\CallSetting \
          venusmmi\app\Cosmos\Certman \
          venusmmi\app\Cosmos\Dataaccount \
          venusmmi\app\Cosmos\DeviceApp \
          venusmmi\app\Cosmos\EngineerMode \
          venusmmi\app\Cosmos\FMRadio \
          venusmmi\app\Cosmos\FileMgr \
          venusmmi\app\Cosmos\Gallery \
          venusmmi\app\Cosmos\GestureTest \
          venusmmi\app\Cosmos\JavaApp \
          venusmmi\app\Cosmos\Message \
          venusmmi\app\Cosmos\MusicPlayer \
          venusmmi\app\Cosmos\NCenter \
          venusmmi\app\Cosmos\Notes \
          venusmmi\app\Cosmos\OomScr \
          venusmmi\app\Cosmos\RightsMgr \
          venusmmi\app\Cosmos\Sat \
          venusmmi\app\Cosmos\ScreenLock \
          venusmmi\app\Cosmos\SupplementaryService \
          venusmmi\app\Cosmos\Sync \
          venusmmi\app\Cosmos\Tethering \
          venusmmi\app\Cosmos\UnifiedComposer \
          venusmmi\app\Cosmos\Widget \
          venusmmi\app\Cosmos\WidgetDelegator \
          venusmmi\app\Cosmos\Wlan \
          venusmmi\app\Cosmos\WorldClock \
          venusmmi\app\Cosmos\dataaccount \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\Cosmos\interface\cp \
          venusmmi\app\Cosmos\interface\cui \
          venusmmi\app\Cosmos\setting\network_connectivity \
          venusmmi\app\Cosmos\setting\setting_framework \
          venusmmi\app\common \
          venusmmi\app\common\clipboard \
          venusmmi\app\common\data \
          venusmmi\app\common\ime \
          venusmmi\app\common\interface\cp \
          venusmmi\app\common\interface\service \
          venusmmi\app\common\message \
          venusmmi\app\common\platform \
          venusmmi\app\common\wallpaper \
          venusmmi\app\cosmos\Calculator \
          venusmmi\app\cosmos\Calendar \
          venusmmi\app\cosmos\Dialer \
          venusmmi\app\cosmos\contact\ContactCore \
          venusmmi\app\cosmos\contact\ContactUI \
          venusmmi\app\pluto_variation \
          venusmmi\app\pluto_variation\MultiTouchTest \
          venusmmi\app\pluto_variation\ShellApp\panel\MsgViewer \
          venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\Framework \
          venusmmi\app\pluto_variation\adapter\MultiTouchTest \
          venusmmi\app\pluto_variation\adapter\ime \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\app\pluto_variation\adapter\interface\trc \
          venusmmi\framework \
          venusmmi\framework\interface \
          venusmmi\framework\mmi_core \
          venusmmi\framework\ui_core\base \
          venusmmi\framework\ui_core\mvc \
          venusmmi\framework\ui_core\pme \
          venusmmi\framework\xml \
          venusmmi\test \
          venusmmi\visual \
          venusmmi\visual\cp \
          venusmmi\visual\interface \
          venusmmi\vrt\interface \
          venusmmi\app\pluto_variation\Launcher\AppWidget \
          venusmmi\app\pluto_variation\Interface
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  INC_DIR += venusmmi\app\Cosmos\ucm
else
  INC_DIR += plutommi\mmi\ucm\ucminc
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
INC_DIR = vendor\inputmethod\GUOBI\adaptation\inc \
          plutommi\Service\SimCtrlSrv \
          plutommi\Service\UmmsSrv \
          plutommi\CUI\Inc \
          plutommi\Framework\BIDI\BIDIInc \
          plutommi\Service\SmsSrv \
          plutommi\mmi\ucm\ucminc \
          lcmmi\mmi\IndicLanguages\IndicLanguagesInc \
          lcmmi\mmi\asyncevents\AsyncEventsInc \
          lcmmi\mmi\Audio\AudioInc \
          lcmmi\mmi\PROFILES\ProfilesInc \
          lcmmi\mmi\callmanagement\CommonFiles\CommonInc \
          lcmmi\mmi\callmanagement\outgoingcallmanagement\outgoinginc \
          lcmmi\mmi\callmanagement\incomingcallmanagement\incominginc \
          lcmmi\mmi\Calls\CallsInc \
          lcmmi\mmi\Connect\ConnectInc \
          lcmmi\mmi\custresource \
          lcmmi\mmi\DateTime\DateTimeInc \
          lcmmi\mmi\debuglevels\debuglevelInc \
          lcmmi\mmi\EMS\EmsInc \
          lcmmi\mmi\FontData \
          lcmmi\mmi\framework\tasks\tasksinc \
          lcmmi\mmi\framework\osl\oslInc \
          lcmmi\mmi\framework\history\historyInc \
          lcmmi\mmi\framework\EventHandling\EventsInc \
          lcmmi\mmi\FunAndGames\FunAndGamesInc \
          lcmmi\mmi\gui\gui_inc \
          lcmmi\MMI\IdleScreen\IdleScreenInc \
          lcmmi\MMI\IdleScreen\IdleScreenInc\DemoAppInc \
          lcmmi\mmi\inc \
          lcmmi\mmi\inc\ImgID \
          lcmmi\mmi\inc\MenuID \
          lcmmi\mmi\inc\StringID \
          lcmmi\mmi\MainMenu\MainMenuInc \
          lcmmi\mmi\Messages\MessagesInc \
          lcmmi\mmi\miscframework\miscframeworkinc \
          lcmmi\mmi\phonebook\PhonebookInc \
          lcmmi\mmi\sat\satInc \
          lcmmi\mmi\Setting\SettingInc \
          lcmmi\mmi\CommonScreens\CommonScreensInc \
          lcmmi\MtkApp\MtkAppInc \
          lcmmi\MtkApp\EngineerMode\EngineerModeInc \
          lcmmi\MtkApp\SoundRecorder\SoundRecorderInc \
          lcmmi \
          lcmmi\customer\customerinc \
          lcmmi\MtkApp\Camera\CameraInc \
          lcmmi\MtkApp\AudioPlayer\AudioPlayerInc \
          lcmmi\MtkApp\FileMgr\FileMgrInc \
          lcmmi\MtkApp\GDI\GDIInc \
          applib\misc\include \
          lcmmi\mmi\InputMethod\Inc \
          lcmmi\mmi\InputMethod\Engine\Engine_Inc \
          lcmmi\mmi\InputMethod\ui\ui_Inc \
          lcmmi\mmi\BIDI\BIDIInc \
          venusmmi\app \
          venusmmi\app\Cosmos\Alarm \
          venusmmi\app\Cosmos\AppManager \
          venusmmi\app\Cosmos\Bluetooth \
          venusmmi\app\Cosmos\CBApp \
          venusmmi\app\Cosmos\CallLog \
          venusmmi\app\Cosmos\CallSetting \
          venusmmi\app\Cosmos\Certman \
          venusmmi\app\Cosmos\Dataaccount \
          venusmmi\app\Cosmos\DeviceApp \
          venusmmi\app\Cosmos\EngineerMode \
          venusmmi\app\Cosmos\FMRadio \
          venusmmi\app\Cosmos\FileMgr \
          venusmmi\app\Cosmos\Gallery \
          venusmmi\app\Cosmos\GestureTest \
          venusmmi\app\Cosmos\JavaApp \
          venusmmi\app\Cosmos\Message \
          venusmmi\app\Cosmos\MusicPlayer \
          venusmmi\app\Cosmos\NCenter \
          venusmmi\app\Cosmos\Notes \
          venusmmi\app\Cosmos\OomScr \
          venusmmi\app\Cosmos\RightsMgr \
          venusmmi\app\Cosmos\Sat \
          venusmmi\app\Cosmos\ScreenLock \
          venusmmi\app\Cosmos\SupplementaryService \
          venusmmi\app\Cosmos\Sync \
          venusmmi\app\Cosmos\Tethering \
          venusmmi\app\Cosmos\UnifiedComposer \
          venusmmi\app\Cosmos\Widget \
          venusmmi\app\Cosmos\WidgetDelegator \
          venusmmi\app\Cosmos\Wlan \
          venusmmi\app\Cosmos\WorldClock \
          venusmmi\app\Cosmos\dataaccount \
          venusmmi\app\Cosmos\interface\app \
          venusmmi\app\Cosmos\interface\cp \
          venusmmi\app\Cosmos\interface\cui \
          venusmmi\app\Cosmos\setting\network_connectivity \
          venusmmi\app\Cosmos\setting\setting_framework \
          venusmmi\app\Cosmos\ucm \
          venusmmi\app\common \
          venusmmi\app\common\clipboard \
          venusmmi\app\common\data \
          venusmmi\app\common\ime \
          venusmmi\app\common\interface\cp \
          venusmmi\app\common\interface\service \
          venusmmi\app\common\message \
          venusmmi\app\common\platform \
          venusmmi\app\common\wallpaper \
          venusmmi\app\cosmos\Calculator \
          venusmmi\app\cosmos\Calendar \
          venusmmi\app\cosmos\Dialer \
          venusmmi\app\cosmos\contact\ContactCore \
          venusmmi\app\cosmos\contact\ContactUI \
          venusmmi\app\pluto_variation \
          venusmmi\app\pluto_variation\MultiTouchTest \
          venusmmi\app\pluto_variation\ShellApp\panel\MsgViewer \
          venusmmi\app\pluto_variation\adapter \
          venusmmi\app\pluto_variation\adapter\Framework \
          venusmmi\app\pluto_variation\adapter\MultiTouchTest \
          venusmmi\app\pluto_variation\adapter\ime \
          venusmmi\app\pluto_variation\adapter\interface \
          venusmmi\app\pluto_variation\adapter\interface\res \
          venusmmi\app\pluto_variation\adapter\interface\trc \
          venusmmi\framework \
          venusmmi\framework\interface \
          venusmmi\framework\mmi_core \
          venusmmi\framework\ui_core\base \
          venusmmi\framework\ui_core\mvc \
          venusmmi\framework\ui_core\pme \
          venusmmi\framework\xml \
          venusmmi\test \
          venusmmi\visual \
          venusmmi\visual\cp \
          venusmmi\visual\interface \
          venusmmi\vrt\interface \
          venusmmi\app\pluto_variation\Launcher\AppWidget \
          venusmmi\app\pluto_variation\Interface
endif

INC_DIR += vendor\search_engine\GUOBI\winguo\adapter\winguo_inc \
           vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_inc 
           
					
COMP_DEFS = GB_PACKAGE					
SRC_PATH = vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src \

endif

ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_ULTRA_SLIM)
SRC_LIST = vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_WG_ultra_app.c \
           vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src\GB_WG_ultra_SerchScreen.c
# Define include path lists to INC_DIR

INC_DIR = plutommi\Service\SimCtrlSrv \
          plutommi\Service\UmmsSrv \
          plutommi\CUI\Inc \
          plutommi\Framework\BIDI\BIDIInc \
          plutommi\Service\SmsSrv \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\mmi\browserapp\browser\browserinc \
          plutommi\service\browsersrv \
          plutommi\service\wappushsrv \
          plutommi\mtkapp\searchweb\searchwebinc \
          plutommi\mmi\ucm\ucminc  \
          plutommi\Framework\IndicLanguages\IndicLanguagesInc \
          plutommi\mmi\setting\settinginc \
          plutommi\mmi\inc

SRC_PATH = vendor\search_engine\GUOBI\winguo\adapter\winguo_platform\platform_src
endif					 

ifeq ($(strip $(GUOBI_WINGUO_SUPPORT)),WINGUO_SLIM_V2)
# Define source file lists to SRC_LIST
SRC_LIST = vendor\search_engine\guobi\winguo_v2\src\common\platform\src\GB_WG_PlatformDebug.c \
           vendor\search_engine\guobi\winguo_v2\src\common\platform\src\GB_WG_PlatformString.c \
           vendor\search_engine\guobi\winguo_v2\src\common\platform\src\GB_WG_PlatformFun.c \
           vendor\search_engine\guobi\winguo_v2\src\model\platform\src\GB_SMD_PlatformElement.c \
           vendor\search_engine\guobi\winguo_v2\src\model\platform\src\GB_SMD_PlatformElementApp.c \
           vendor\search_engine\guobi\winguo_v2\src\model\platform\src\GB_SMD_PlatformElementCallLog.c \
           vendor\search_engine\guobi\winguo_v2\src\model\platform\src\GB_SMD_PlatformElementOther.c \
           vendor\search_engine\guobi\winguo_v2\src\model\platform\src\GB_SMD_PlatformElementPhoneNum.c \
           vendor\search_engine\guobi\winguo_v2\src\view\src\GB_WG_ultra_app.c  \
           vendor\search_engine\guobi\winguo_v2\src\view\src\GB_WG_NetSearch.c

ifeq ($(strip $(MMI_VERSION)), PLUTO_MMI)
#plutommi的界面实现函数
SRC_LIST += vendor\search_engine\guobi\winguo_v2\src\view\src\fte\GB_SMD_SysControl.c \
            vendor\search_engine\guobi\winguo_v2\src\view\src\fte\GB_SMD_SysSearch.c	\
            vendor\search_engine\guobi\winguo_v2\src\view\src\fte\GB_SMD_Show_Menuitem.c
else
    ifeq ($(strip $(MMI_VERSION)), COSMOS_MMI)
        #cosmos 的界面实现函数
        SRC_LIST += vendor\search_engine\guobi\winguo_v2\src\view\src\cosmos\GB_SMD_View_App.cpp \
                vendor\search_engine\guobi\winguo_v2\src\view\src\cosmos\GB_SMD_View_List.cpp \
                vendor\search_engine\guobi\winguo_v2\src\view\src\cosmos\GB_SMD_View_Control.cpp \
                vendor\search_engine\guobi\winguo_v2\src\view\src\cosmos\GB_SMD_View_Page.cpp \
                vendor\search_engine\guobi\winguo_v2\src\view\src\cosmos\GB_SMD_View_Screen.cpp
    else
        $(warning ERROR: $(strip $(MMI_VERSION) is not support)
    endif
endif



# Define include path lists to INC_DIR
INC_DIR = vendor\search_engine\guobi\winguo_v2\inc \
          vendor\search_engine\guobi\winguo_v2\src\common\inc \
          vendor\search_engine\guobi\winguo_v2\src\model\inc \
          vendor\search_engine\guobi\winguo_v2\src\view\inc \
          applib\mem\include \
          plutommi\mmi\Inc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\mmi\Setting\SettingInc \
          plutommi\MtkApp\FileMgr\FileMgrInc \
          plutommi\mmi\CallLog\CallLogInc \
          plutommi\CUI\Inc \
          plutommi\mmi\PhoneBook\PhoneBookInc \
	  plutommi\Service\PhbSrv \
	  plutommi\mmi\Messages\MessagesInc \
	  plutommi\mmi\IdleScreen\IdleScreenInc \
	  plutommi\mmi\Audio\AudioInc \
	  plutommi\mmi\PROFILES\ProfilesInc \
	  plutommi\mmi\PhoneBook\Core \
	  plutommi\MtkApp\vObjects\vObjectInc \
	  plutommi\Framework\bidi\bidiinc \
	  plutommi\Service\ummssrv

ifeq ($(strip $(MMI_VERSION)), PLUTO_MMI)
    INC_DIR += plutommi\Framework\GUI\GUI_INC \
               vendor\search_engine\guobi\winguo_v2\src\view\src\fte \
                   plutommi\Framework\bidi\bidiinc \
                   vcard\include \
                   plutommi\mmi\Ucm\UcmInc 
else
    ifeq ($(strip $(MMI_VERSION)), COSMOS_MMI)
        INC_DIR += venusmmi\framework \
                   venusmmi\framework\interface \
                   venusmmi\framework\mmi_core \
                   venusmmi\framework\ui_core\pme \
                   venusmmi\framework\ui_core\mvc \
                   venusmmi\vrt\interface \
                   venusmmi\visual\interface \
                   venusmmi\visual\cp\common \
                   venusmmi\visual\cp\fte \
                   venusmmi\visual\cp\cosmos \
                   venusmmi\app\pluto_variation\adapter \
                   venusmmi\app\common \
                   venusmmi\app\common\ime \
                   venusmmi\app\common\interface\app \
                   venusmmi\app\common\interface\cp \
                   venusmmi\app\common\ncenter \
                   venusmmi\app\common\message \
                   venusmmi\app\Cosmos\Message \
                   venusmmi\app\Cosmos\interface\app \
                   venusmmi\app\Cosmos\interface\cui \
                   venusmmi\app\Cosmos\dialer \
                   venusmmi\app\Cosmos\Ucm \
                   venusmmi\app\Cosmos\Contact\ContactUI \
                   venusmmi\app\Cosmos\Contact\ContactCore \
                   venusmmi\app\Cosmos\interface\cp \
                   venusmmi\app\Cosmos\CallLog \
                   venusmmi\app\common\widget \
                   vendor\search_engine\guobi\winguo_v2\src\view\src\cosmos\inc 
    endif
endif




# Define the specified compile options to COMP_DEFS
COMP_DEFS = 
endif					 

				 


           
