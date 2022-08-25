@set configFile=%1
@set outputFolder=%2
@set outputPrefix=%3
@set internalFlag=%4

@echo [iotgen]Para1:%configFile%
@echo [iotgen]Para2:%outputFolder%
@echo [iotgen]Para3:%outputPrefix%
@echo [iotgen]Para4:%internalFlag%
@echo [iotgen]Para5:%partialFlag%

@set IMMaker=.\tools\CardDownload\IM_Maker.exe
@set IOTMaker=.\tools\IOTFota\UpdateImagePacker.exe
@set IOT_INI_GEN=.\tools\IOTFota\gen_IOT_ini.pl
@set IOT_COMPRESSED=.\tools\IOTFota\gen_compressed_bin.pl
@set IOTConfig=%outputFolder%\IOT_%outputPrefix%.ini
@set IOTPKGConfig=.\tools\IOTFota\iot_pkg_config.ini
@set 
@if %internalFlag%==TRUE set XIMMaker=.\tools\CardDownload\XIM_Maker.exe
@if %internalFlag%==FALSE set XIMMaker=.\mtk_tools\CardDownload\XIM_Maker.exe
@echo [ximgen]XIMMaker Path: %XIMMaker%
@if NOT EXIST %XIMMaker% echo [ximgen]XIMMaker Path: %XIMMaker% not exist, please build one! 
@if NOT EXIST %XIMMaker% goto ERROR

Gen ini for IOT FOTA
@perl %IOT_INI_GEN% %configFile% %IOTConfig% %IOTPKGConfig%

%IOTMaker% -i %IOTConfig% -o %outputFolder%\%outputPrefix%.IoT
@IF %ERRORLEVEL% NEQ 0 goto IMAGEMAKER_ERROR


%IMMaker% -i %IOTConfig%  -x %outputFolder%\XIM_Maker_IOT.ini  
@if %ERRORLEVEL% neq 0 goto ERROR

@echo ===================
@echo  IM_Maker Passed!
@echo ===================

%XIMMaker% -s %outputFolder%\XIM_Maker_IOT.ini -i %outputFolder%\%outputPrefix%.IoT -o %outputFolder%\%outputPrefix%_IOT.XIM
@if %ERRORLEVEL% neq 0 goto ERROR

@perl %IOT_COMPRESSED% %outputFolder%\%outputPrefix%_IOT.XIM  %outputFolder%\%outputPrefix%_IOT_raw.XIM  %IOTPKGConfig%



@echo ===================
@echo  XIM_Maker Passed!
@echo ===================

:OK
@goto END

:ERROR
@echo ========
@echo  ERROR!
@echo ========
@exit /b 1


:END