@echo off
path ..\..\..\tools;..\..\..\Tools\MSYS\bin;..\..\..\Tools\MinGW\bin;%path%;
set MTK_PROJECT_PATH=%2
echo MediaTek Inc. Resource Generator Script
echo Building resource ...
if .%1==.-t goto FROM_CMD_LINE
goto FROM_USER

:FROM_CMD_LINE
cd plutommi\VendorApp\ResGenerator
goto START

:FROM_USER
cd ..\ResGenerator
goto START

:START

@echo off

rem ************************************************************
rem *************** make and run resgen_xml.exe ************
rem ************************************************************
:make_resgen_xml
echo -----------------make and run resgen_xml.exe----------------
if exist .\temp\ rd /S/Q .\temp\ >nul
if exist .\debug\ rd /S/Q .\debug\ >nul
if exist ..\DevResource\Res_MMI\mmi_rp_*.c del ..\DevResource\Res_MMI\mmi_rp_*.c
if exist ..\..\Customer\CustomerInc\mmi_rp_app_avk_def.h del ..\..\Customer\CustomerInc\mmi_rp_app_avk_def.h
if exist ..\..\Customer\CustomerInc\mmi_rp_app_devapp_def.h del ..\..\Customer\CustomerInc\mmi_rp_app_devapp_def.h

if not exist .\debug\res md .\debug\res
if not exist ..\customerinc md ..\customerinc
if not exist .\temp\res md .\temp\res
if not exist .\temp\res_out md .\temp\res_out
if not exist .\temp\res_out\res md .\temp\res_out\res
if not exist .\temp\res_out\CustomerInc md .\temp\res_out\CustomerInc

echo -----------------resgen_xml.exe -c----------------
resgen_xml.exe -c -v > .\debug\resgen_xml_copy.log
IF ERRORLEVEL 2 goto RESGEN_COPY_XML_FILES_ERR

echo ----------------- make xml_files ----------------
..\..\..\Tools\MSYS\bin\make xml_files -k 
rem 2> .\..\..\..\build\%2\log\resgen_xml_files.log
IF ERRORLEVEL 2 goto RESGEN_BUILD_C_TO_I_ERR

echo -----------------resgen_xml.exe -p----------------
resgen_xml.exe -p > .\debug\resgen_xml.log
IF ERRORLEVEL 2 goto RESGEN_RUN_RESGEN_XML_ERR

copy .\debug\res\mmi_rp_*.c ..\DevResource\Res_MMI\. > nul

rem ************************************************************
rem ************** Start to Generate Resource ******************
rem *********** -Generate Image and Menu Resource **************
rem ************************************************************
del .\DevApp_resgenerator.exe
echo Making Resources...
del *.o
..\..\..\Tools\MSYS\bin\make DevApp_resgenerator.exe
if not exist DevApp_resgenerator.exe goto RESGEN_ERROR
DevApp_resgenerator.exe -g > DevApp_resgenerator.log

rem ************************************************************
rem *** Menu Tree Tool gen resource to copy back if needed *****
rem ************************************************************
copy ..\DevResource\CustMenuToolRes.c ..\DevResource\CustMenuRes.c

rem ************************************************************
rem ************** Start to Generate Resource ******************
rem ******** -Generate MultiLanguage String Resource ***********
rem ************************************************************
echo Generate MultiLanguage String List...
MergeStrRes ..\DevResource\Resources\CustStrList.txt ..\DevResource\Resources\ref_list.txt
del DevApp_readexcel.exe
..\..\..\Tools\MSYS\bin\make DevApp_readexcel.exe
if not exist DevApp_readexcel.exe goto READEXCEL_ERROR
DevApp_ReadExcel CustResList_out.txt
echo clear intermediate files...
del *.o
if exist .\temp\ rd /S/Q .\temp\ >nul
if exist ..\customerinc\mmi_rp_app_mem_config.h del  ..\customerinc\mmi_rp_app_mem_config.h >nul
if exist ..\customerinc\mmi_rp_file_type_def.h del  ..\customerinc\mmi_rp_file_type_def.h >nul
if exist ..\customerinc\mmi_rp_img_misc_def.h del  ..\customerinc\mmi_rp_img_misc_def.h >nul
if exist ..\customerinc\mmi_rp_menu_misc_def.h del  ..\customerinc\mmi_rp_menu_misc_def.h >nul
if exist ..\customerinc\mmi_rp_menu_shortcut_def.h del  ..\customerinc\mmi_rp_menu_shortcut_def.h >nul
if exist ..\customerinc\mmi_rp_app_data.h del  ..\customerinc\mmi_rp_app_data.h >nul
if exist ..\CustomerInc\mmi_cache_default_value.h del  ..\CustomerInc\mmi_cache_default_value.h >nul
if exist ..\CustomerInc\mmi_cache_nvram_editor.h del  ..\customerinc\mmi_cache_nvram_editor.h >nul
if exist ..\customerinc\mmi_cache_table.h del  ..\customerinc\mmi_cache_table.h >nul


REM if exist ..\customerinc\mmi_rp_all_defs.h del  ..\customerinc\mmi_rp_all_defs.h >nul

echo MultiLanguage String Resource generated successfully...

echo --
echo Complete!!
goto done

rem ************************************************************
rem ************** Error Handling and Messages *****************
rem ************************************************************
:RESGEN_ERROR
echo Error in ResGenerating Process!!
echo Please Check again!!
goto done

:READEXCEL_ERROR
echo Error in Generate MultiLanguage Strings!!
echo Please Check again!!
goto done

:RESGEN_COPY_XML_FILES_ERR
echo Error in run resgen_xml to copy files from app folder error!!
echo Please Check log file resgen_xml_copy.log !!
goto done

:RESGEN_BUILD_C_TO_I_ERR
echo Error in make .c file to .i file!!
echo Please Check log file resgen_xml_files.log !!
goto done

:RESGEN_RUN_RESGEN_XML_ERR
echo Error in run resgen_xml error!!
echo Please Check log file resgen_xml.log !!
goto done

:done
if .%1==.-t goto FROM_CMD_LINE_END
goto FROM_USER_END

:FROM_CMD_LINE_END
cd ..\..\..\
goto END

:FROM_USER_END
cd ..\DevResource
goto END

:END
