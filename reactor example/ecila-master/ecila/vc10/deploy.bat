@ECHO OFF



REM src libraries
SET S_LIB=..\bin\ecila_d.lib
SET S_DLL=..\bin\ecila_d.dll



REM target directory
SET T_TEST=..\..\test\bin
SET T_APP=..\..\app\bin



@ECHO ON
copy libraries
copy /Y %S_LIB% %T_TEST%
copy /Y %S_DLL% %T_TEST%

copy /Y %S_LIB% %T_APP%
copy /Y %S_DLL% %T_APP%
