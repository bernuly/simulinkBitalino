@echo OFF
set MATLAB_DIR=C:\Program Files\MATLAB\R2018b
set MATLAB_ROOT=C:\PROGRA~1\MATLAB\R2018b
set WIN_SDK_DIR=C:\Program Files\Microsoft SDKs\Windows\v7.1\


set LIBS=-lWs2_32 -lwinmm

set FLAGS=-g -D_WIN64 -D_WINDOWS
REM -DNDEBUG


echo %LIBDIRS%
echo %LIBS%
echo %INCL%

call "%MATLAB_DIR%\bin\mex.bat" %FLAGS%  %LIBDIRS% %LIBS% %INCL% simulinkBitalino.cpp simulinkBitalino_wrapper.cpp simulinkBitalino_mycode.cpp bitalino.cpp

REM -outdir Release

REM pause




  
