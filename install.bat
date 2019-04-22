@echo OFF

set INSTALL_DIR=%USERPROFILE%\Documents\MATLAB\simulinkBitalino
echo copying files to %INSTALL_DIR%


mkdir %INSTALL_DIR%
copy simulinkBitalino.slx      %INSTALL_DIR%
copy slblocks.m        %INSTALL_DIR%
copy simulinkBitalino.mexw64  %INSTALL_DIR%

pause
