# Microsoft Developer Studio Project File - Name="ResgenXML_VC" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=ResgenXML_VC - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ResgenXML_VC.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ResgenXML_VC.mak" CFG="ResgenXML_VC - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ResgenXML_VC - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "ResgenXML_VC - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ResgenXML_VC - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "ResgenXML_VC - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\..\Inc" /I "..\CustResInc" /I "..\ResgenInc" /I "..\..\..\..\mmi\inc" /I "..\..\..\CustomerInc" /I "..\..\..\..\mmi\miscframework\miscframeworkinc" /I "..\..\..\..\framework\interface" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "__RESOURCE_GEN_" /D "__XML_SUPPORT__" /D "RESXML_VC_DEBUG" /D "__OPTR_NONE__" /YX /FD /GZ @"../../custom_option.txt" @"../../custom_include.txt" /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "ResgenXML_VC - Win32 Release"
# Name "ResgenXML_VC - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_audio.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_event.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_hash.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_image.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_mem_config.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_menu.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_screen.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_string.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_theme.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_timer.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_xml.c
# End Source File
# Begin Source File

SOURCE=..\ResgenSrc\mmi_rp_xml_parser.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_audio.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_event.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_hash.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_image.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_mem_config.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_menu.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_res_list.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_screen.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_string.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_theme.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_timer.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_xml.h
# End Source File
# Begin Source File

SOURCE=..\ResgenInc\mmi_rp_xml_def.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\mmi\Inc\MMIDataType.h
# End Source File
# End Group
# Begin Group "Cust Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\CustResSrc\mmi_rp_callback_mgr.c
# End Source File
# Begin Source File

SOURCE=..\CustResInc\mmi_rp_callback_mgr.h
# End Source File
# Begin Source File

SOURCE=..\CustResInc\mmi_rp_cust_res_list.h
# End Source File
# Begin Source File

SOURCE=..\CustResSrc\mmi_rp_cust_template.c
# End Source File
# Begin Source File

SOURCE=..\CustResInc\mmi_rp_cust_template.h
# End Source File
# Begin Source File

SOURCE=..\CustResSrc\mmi_rp_file_type.c
# End Source File
# Begin Source File

SOURCE=..\CustResInc\mmi_rp_file_type.h
# End Source File
# Begin Source File

SOURCE=..\CustResSrc\mmi_rp_mmi_cache.c
# End Source File
# Begin Source File

SOURCE=..\CustResInc\mmi_rp_mmi_cache.h
# End Source File
# Begin Source File

SOURCE=..\CustResSrc\mmi_rp_venus_xml.c
# End Source File
# Begin Source File

SOURCE=..\CustResInc\mmi_rp_venus_xml.h
# End Source File
# End Group
# End Target
# End Project
