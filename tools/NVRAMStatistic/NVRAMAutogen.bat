@echo off
path ..\..\tools;..\..\..\tools;..\..\..\Tools\MSYS\bin;..\..\..\..\Tools\MSYS\bin;..\..\Tools\MinGW\bin;..\..\..\Tools\MinGW\bin;..\..\..\tools\MinGW\lib\gcc-lib\mingw32\3.3.1;..\debug;.\debug;..\..\..\Tools;%path%;
if  .%1==.  goto NVRAM_AUTO_GEN_ERROR_1

if %WISDOM_CUSTOM_BUILD%INTERNAL==INTERNAL set WISDOM_CUSTOM_BUILD=FALSE

if %WISDOM_CUSTOM_BUILD%==TRUE (set MSYS_FOLDER=MSYS_WISDOM) else set MSYS_FOLDER=MSYS
if %WISDOM_CUSTOM_BUILD%==TRUE (if not exist tools\%MSYS_FOLDER% (if exist tools\MSYS (rename tools\MSYS %MSYS_FOLDER%)))

cd Tools\NVRAMStatistic
if not exist debug mkdir debug

perl nvram_pre_gen.pl

cd src

SET ERROR_LOG=..\..\..\build\%1\log\nvram_gen.log
SET FULL_LOG=..\..\..\build\%1\log\nvram_gen_full_log.log

if exist %ERROR_LOG% del %ERROR_LOG%
if exist %FULL_LOG% del %FULL_LOG%

if exist ..\debug\*.d del ..\debug\*.d
if exist ..\debug\nvram_auto_gen.dep del ..\debug\nvram_auto_gen.dep

echo Parameter 1 = %1 >> %FULL_LOG%
echo Parameter 2 = %2 >> %FULL_LOG%
echo Parameter 3 = %3 >> %FULL_LOG%
echo Parameter 4 = %4 >> %FULL_LOG%
echo Parameter 5 = %5 >> %FULL_LOG%
echo Parameter 6 = %6 >> %FULL_LOG%

echo ************************************************************ >> %FULL_LOG%
echo ************* Start to Generate NVRAM Info ***************** >> %FULL_LOG%
echo ************************************************************ >> %FULL_LOG%
echo [NVRAM Auto Gen]

if .%5==.VENDOR (
  if .%6==.TRUE goto VDR
)
if .%5==.LEVEL2_OBJ (
  if not .%6==.FALSE goto SRC
)
if exist ..\debug\nvram_data_items.o del ..\debug\nvram_data_items.o
:SRC
if not .%5==. (echo LEVEL = %5 >> ..\include\custom_option.txt)
if not .%6==. (echo CUSTOM_RELEASE = %6 >> ..\include\custom_option.txt)
::if exist ..\debug\nvram_auto_gen.exe    del ..\debug\nvram_auto_gen.exe
::if exist ..\debug\mmi_cache_gen.exe     del ..\debug\mmi_cache_gen.exe
::if exist ..\debug\nvram_common_config.o del ..\debug\nvram_common_config.o
::if exist ..\debug\nvram_cust_pack.o     del ..\debug\nvram_cust_pack.o
::if exist ..\debug\nvram_gen_util.o      del ..\debug\nvram_gen_util.o
:VDR
if not .%5==. (echo LEVEL = %5 >> ..\include\custom_option.txt)
if not .%6==. (echo CUSTOM_RELEASE = %6 >> ..\include\custom_option.txt)
::if exist ..\debug\nvram_auto_gen.exe    del ..\debug\nvram_auto_gen.exe
::if exist ..\debug\mmi_cache_gen.exe     del ..\debug\mmi_cache_gen.exe
::if exist ..\debug\nvram_user_config.o   del ..\debug\nvram_user_config.o

if exist ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h   del ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
if exist ..\..\..\custom\common\hal\nvram\nvram_lid_statistics.h   copy ..\..\..\custom\common\hal\nvram\nvram_lid_statistics.h ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h

echo #ifndef NVRAM_LID_STATISTIC_H             >      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #define NVRAM_LID_STATISTIC_H            >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #ifndef NVRAM_NOT_PRESENT                >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #ifndef NVRAM_AUTO_GEN                   >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #ifndef __RESOURCE_GEN_                  >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #ifndef GEN_FOR_PC                       >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #error "nvram_auto_gen fail!"            >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #endif                                   >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #endif                                   >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #endif                                   >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #define NVRAM_OTP_SIZE    10             >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #define NVRAM_OTP_TOTAL   1              >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #define NVRAM_CUSTPACK_TOTAL  13         >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #define NVRAM_SECUPACK_SIZE  973         >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #endif                                   >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h
echo #endif                                   >>      ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h

echo generate nvram_lid_statistics_bak.h success >> %FULL_LOG%

if exist ..\..\..\custom\common\hal\nvram\nvram_gen_trc.h   del ..\..\..\custom\common\hal\nvram\nvram_gen_trc.h
echo typedef enum {                     >>      ..\..\..\custom\common\hal\nvram\nvram_gen_trc.h
echo    _NVRAM_EF_SYS_LID = 0,          >>      ..\..\..\custom\common\hal\nvram\nvram_gen_trc.h  
echo    NVRAM_TRC_LID_TOTAL             >>      ..\..\..\custom\common\hal\nvram\nvram_gen_trc.h 
echo }nvram_trc_lid_enum;               >>      ..\..\..\custom\common\hal\nvram\nvram_gen_trc.h 

echo generate nvram_gen_trc.h success >> %FULL_LOG%
echo *********************************************************** >> %FULL_LOG%
echo ********  Generate fake nvram_custpack_table.c      ******* >> %FULL_LOG%
echo *********************************************************** >> %FULL_LOG%
if exist ..\..\..\custom\common\NEPTUNE_MMI\nvram_custpack_table.c (
	echo /**/ > ..\..\..\custom\common\NEPTUNE_MMI\nvram_custpack_table.c
	echo generate NEPTUNE_MMI\nvram_custpack_table.c >> %FULL_LOG%
) 

if exist ..\..\..\custom\common\PLUTO_MMI\nvram_custpack_table.c (
	echo /**/ > ..\..\..\custom\common\PLUTO_MMI\nvram_custpack_table.c
	echo generate PLUTO_MMI\nvram_custpack_table.c >> %FULL_LOG%
)

if exist ..\..\..\custom\common\VENUS_MMI\nvram_custpack_table.c (
	echo /**/ > ..\..\..\custom\common\VENUS_MMI\nvram_custpack_table.c
	echo generate VENUS_MMI\nvram_custpack_table.c >> %FULL_LOG%
)

echo *********************************************************** >> %FULL_LOG%
echo ******************  Gen nvram_mmi_cache_cust_pack.h ******* >> %FULL_LOG%
echo *********************************************************** >> %FULL_LOG%
echo #ifndef NVRAM_NOT_PRESENT                                             >   ..\..\..\custom\app\%2\nvram_mmi_cache_cust_pack.h
echo #ifndef NVRAM_AUTO_GEN                                             >>   ..\..\..\custom\app\%2\nvram_mmi_cache_cust_pack.h
echo #error "nvram_auto_gen fail!"                                      >>  ..\..\..\custom\app\%2\nvram_mmi_cache_cust_pack.h
echo #endif                                                             >>  ..\..\..\custom\app\%2\nvram_mmi_cache_cust_pack.h
if %4 == 1 (
    echo #endif                                                             >>  ..\..\..\custom\app\%2\nvram_mmi_cache_cust_pack.h
    goto jump_sp_2
)
echo const kal_uint8 NVRAM_CACHE_BYTE_DEFAULT[NVRAM_CACHE_SIZE];		>>	..\..\..\custom\app\%2\nvram_mmi_cache_cust_pack.h
echo const kal_uint8 NVRAM_CACHE_SHORT_DEFAULT[NVRAM_CACHE_SIZE];		>>	..\..\..\custom\app\%2\nvram_mmi_cache_cust_pack.h
echo const kal_uint8 NVRAM_CACHE_DOUBLE_DEFAULT[NVRAM_CACHE_SIZE];		>>	..\..\..\custom\app\%2\nvram_mmi_cache_cust_pack.h
echo #endif                                                             >>  ..\..\..\custom\app\%2\nvram_mmi_cache_cust_pack.h

echo generate nvram_mmi_cache_cust_pack.h success >> %FULL_LOG%

rem :jump_sp_1
rem if not exist %3\operator_mmi_cache_config.c goto gen_op
rem echo #include "operator_mmi_cache_config.c" > operator_mmi_cache_wrapper.c
rem goto make_nvram
rem 
rem :gen_op
rem echo ************************************************************ >> %FULL_LOG%
rem echo ******************  Gen operator config file *************** >> %FULL_LOG%
rem echo ************************************************************ >> %FULL_LOG%
rem echo #include "nvram_mmi_cache_defs.h"         >      operator_mmi_cache_wrapper.c
rem echo #ifndef NVRAM_AUTO_GEN                   >>      operator_mmi_cache_wrapper.c
rem echo #error "nvram_auto_gen fail!"            >>      operator_mmi_cache_wrapper.c
rem echo #endif                                   >>      operator_mmi_cache_wrapper.c
rem if %4 == 1 goto jump_sp_2
rem echo mmi_cache_byte_entry operator_mmi_cache_byte[] = {{0xFF, NVRAM_APP_RESERVED, NVRAM_CACHE_ID_RESERVED, KAL_FALSE, 0xFF, "", "" ,"", "" ,""}}; >> operator_mmi_cache_wrapper.c
rem echo mmi_cache_short_entry operator_mmi_cache_short[] = {{0xFF, NVRAM_APP_RESERVED, NVRAM_CACHE_ID_RESERVED, KAL_FALSE, 0xFF, 0xFF, "", "", "", "", "", ""}}; >> operator_mmi_cache_wrapper.c
rem echo mmi_cache_double_entry operator_mmi_cache_double[] = {{0xFF, NVRAM_APP_RESERVED, NVRAM_CACHE_ID_RESERVED, KAL_FALSE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, "", "", "", "", "", "", "", "", "", "", "", ""}}; >> operator_mmi_cache_wrapper.c
rem 
rem echo generate operator_mmi_cache_wrapper.c success >> %FULL_LOG%

:jump_sp_2

:make_mmi_cache
echo     [mmi_cache_gen]
echo ************************************************************ >> %FULL_LOG%
echo ******************  Build mmi_cache_gen.exe   ************* >> %FULL_LOG%
echo ************************************************************ >> %FULL_LOG%
::..\..\%MSYS_FOLDER%\bin\make -s -j 1 mmi_cache_gen 1>>%FULL_LOG% 2>>%ERROR_LOG%
copy ..\debug\mmi_cache_gen.org.exe ..\debug\mmi_cache_gen.exe
type %ERROR_LOG% >> %FULL_LOG%
if not exist ..\debug\mmi_cache_gen.exe goto NVRAM_AUTO_GEN_ERROR_2

:execute_mmi_cache
echo ************************************************************ >> %FULL_LOG%
echo ******************  Execute mmi_cache_gen.exe ************* >> %FULL_LOG%
echo ************************************************************ >> %FULL_LOG%
mmi_cache_gen.exe %1 %2 1>>%FULL_LOG% 2>>%ERROR_LOG%  
if %errorlevel% EQU 0 (
	type %ERROR_LOG% >> %FULL_LOG%
	echo execute mmi_cache_gen done >> %FULL_LOG%
) else (
	type %ERROR_LOG% >> %FULL_LOG%
	goto NVRAM_AUTO_GEN_ERROR_2
)

:make_nvram
echo     [nvram_auto_gen]
echo ************************************************************ >> %FULL_LOG%
echo ******************  Build nvram_auto_gen.exe   ************* >> %FULL_LOG%
echo ************************************************************ >> %FULL_LOG%
::..\..\%MSYS_FOLDER%\bin\make -s -j 1 nvram_auto_gen 1>>%FULL_LOG% 2>>%ERROR_LOG%
copy ..\debug\nvram_auto_gen.org.exe ..\debug\nvram_auto_gen.exe
type %ERROR_LOG% >> %FULL_LOG%
if not exist ..\debug\nvram_auto_gen.exe goto NVRAM_AUTO_GEN_ERROR_2

if exist ..\debug\fs_quota_entry_dump.o del ..\debug\fs_quota_entry_dump.o
if exist ..\debug\fs_quota_entry_dump.exe del ..\debug\fs_quota_entry_dump.exe

:execute_nvram
echo ************************************************************ >> %FULL_LOG%
echo ******************  Execute nvram_auto_gen.exe ************* >> %FULL_LOG%
echo ************************************************************ >> %FULL_LOG%
nvram_auto_gen.exe %1 %2 1>>%FULL_LOG% 2>>%ERROR_LOG%  
if %errorlevel% EQU 0 (
	type %ERROR_LOG% >> %FULL_LOG%
	echo execute nvram_auto_gen done >> %FULL_LOG%
	del %ERROR_LOG%
) else (
	type %ERROR_LOG% >> %FULL_LOG%
	goto NVRAM_AUTO_GEN_ERROR_2
)

echo     [fs_quota_entry_dump]


rem if exist ..\..\..\build\%1\log\fs_quota_entry_dump.log del ..\..\..\build\%1\log\fs_quota_entry_dump.log
rem ..\..\%MSYS_FOLDER%\bin\make -s -j 1 fs_quota_entry_dump 2> ..\..\..\build\%1\log\fs_quota_entry_dump.log

rem if not exist ..\debug\fs_quota_entry_dump.exe goto FS_QUOTA_GEN_ERROR_1
rem fs_quota_entry_dump.exe

if %errorlevel% EQU 2 (	
	goto FS_QUOTA_GEN_ERROR_2
)

rem ************************************************************
rem ************* Both Procedure finished      *****************
rem ************************************************************
perl ..\..\pack_dep_gcc.pl ..\debug\nvram_auto_gen.dep ..\debug tools\NVRAMStatistic\src
cd ..\..\..\

echo --
echo Complete!!
goto done

rem ************************************************************
rem ************** Error Handling and Messages *****************
rem ************************************************************
:NVRAM_AUTO_GEN_ERROR_1
copy ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h ..\..\..\custom\common\hal\nvram\nvram_lid_statistics.h
echo Miss arguments!
goto NVRAM_AUTO_GEN_ERROR

:NVRAM_AUTO_GEN_ERROR_2
copy ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h ..\..\..\custom\common\hal\nvram\nvram_lid_statistics.h
echo NVRAM_AUTO_GEN_ERROR_2 >> %FULL_LOG%
echo Error in NVRAM Generating Process!!
echo Please Check nvram_gen_full_log.log!!
type %FULL_LOG%
cd ..\..\..\
:NVRAM_AUTO_GEN_ERROR
exit 3

:NVRAM_COMPRESS_ERROR
copy ..\..\..\custom\common\hal\nvram\nvram_lid_statistics_bak.h ..\..\..\custom\common\hal\nvram\nvram_lid_statistics.h
echo NVRAM_COMPRESS_ERROR >> %FULL_LOG%
exit 3

:FS_QUOTA_GEN_ERROR_1
cd ..\..\..\
echo Error in FS_QUOTA Generating Process!!
echo Please Check fs_quota_entry_dump.log!!
type .\build\%1\log\fs_quota_entry_dump.log
exit 3

:FS_QUOTA_GEN_ERROR_2
cd ..\..\..\
echo Please set APP_STORAGE_IN_SYS_DRV as TRUE for those projects which disable phone drive! >> %FULL_LOG%
echo Error in compile option dependency check!!
echo Error in compile option dependency check!! >> %FULL_LOG%
exit 3

:done
exit 0
