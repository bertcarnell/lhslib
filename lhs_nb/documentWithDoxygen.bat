:: document code with 

echo off

set DOXYGEN="c:\Program Files\doxygen\bin\doxygen.exe"
set CONFIGFILE=doxygen.config

:: to generate the config file the first time (with defaults)
:: %DOXYGEN% -g %CONFIGFILE%

%DOXYGEN% %CONFIGFILE%
