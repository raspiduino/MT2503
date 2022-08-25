# Microsoft Developer Studio Project File - Name="DevResource" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=DevResource - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DevResource.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DevResource.mak" CFG="DevResource - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DevResource - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "DevResource - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DevResource - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "DevResource - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /Zp1 /W3 /Gm /GX /ZI /Od /I "..\..\Customer\CustomerInc" /I ".\Resources" /I "..\..\MMI\Inc" /I "..\..\Framework\GUI\GUI_INC" /I "..\..\MtkApp\MtkAppInc" /I "..\..\MtkApp\EngineerMode\EngineerModeInc" /I "..\..\MMI\MiscFramework\MiscFrameworkInc" /I "..\..\Framework\Osl\OslInc" /I "..\..\Framework\Tasks\TasksInc" /I "..\..\MtkApp\AudioPlayer\AudioPlayerInc" /I "..\..\MtkApp\SoundRecorder\SoundRecorderInc" /I "..\..\MtkApp\Camera\CameraInc" /I "..\..\MtkApp\ExtDevice\ExtDeviceInc" /I "..\..\MtkApp\FileMgr\FileMgrInc" /I "..\..\MMI\Inc\MenuID" /I "..\..\Framework\CommonScreens\CommonScreensInc" /I "..\..\Framework\History\HistoryInc" /I "..\..\Framework\EventHandling\EventsInc" /I "..\..\MMI\DateTime\DateTimeInc" /I "..\..\Framework\GDI\GDIInc" /I "..\..\MMI\IdleScreen\IdleScreenInc" /I "..\..\MMI\Setting\SettingInc" /I "..\..\..\kal\include" /D "MMI_ON_WIN32" /D "__UCS2_ENCODING" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "DevResource - Win32 Release"
# Name "DevResource - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Resources\DevAppAdoDataHW.h
# End Source File
# Begin Source File

SOURCE=.\Resources\DevAppAdoMap.c
# End Source File
# Begin Source File

SOURCE=.\Resources\DevAppAdoRes.c
# End Source File
# Begin Source File

SOURCE=.\Resources\DevAppImgDataHW.h
# End Source File
# Begin Source File

SOURCE=.\Resources\DevAppImgMap.c
# End Source File
# Begin Source File

SOURCE=.\Resources\DevAppImgRes.c
# End Source File
# Begin Source File

SOURCE=.\Resources\DevAppMenuRes.c
# End Source File
# Begin Source File

SOURCE=.\Resources\DevAppStrMap.c
# End Source File
# Begin Source File

SOURCE=.\Resources\DevAppStrRes.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
