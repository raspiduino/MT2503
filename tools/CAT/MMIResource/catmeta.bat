@echo off

REM Usage catmeta outputfile [-s codebase]

REM Reset ENV variables
set CAT_PY_HOME=
set CAT_ROOT=

REM search for the python folder
if exist .\tools\python25 set CAT_PY_HOME=.\tools\python25
if exist ..\..\python25 set CAT_PY_HOME=.\python25

REM search for the catmeta root
if exist .\tools\CAT\MMIResource\catmeta.py set CAT_ROOT=.\tools\CAT\MMIResource
if exist .\catmeta.py set CAT_ROOT=.


REM check python path
if .%CAT_PY_HOME%==. goto ENV_ERR
if .%CAT_ROOT%==. goto NO_CAT_ROOT

REM execute the main python script of the command
if  .%1==.  goto USAGE
%CAT_PY_HOME%\python.exe %CAT_ROOT%\catmeta.py %1 %2 %3
GOTO END:

:ENV_ERR
echo Error!! Can't find ptyhon in the codebase
EXIT /B 1
:NO_CAT_ROOT
echo Error!! Can't find catmeta.py in the codebase
EXIT /B 1

:USAGE
echo Usage: catmeta [meta file name] [-s codebase]
EXIT /B 1
:END