echo off

:: Rtools uses CYGWIN for these file operations
set CYGWIN=nodosfilewarning
:: Deploy to lhs repository at r-forge.r-project.org
:: change this destination to match your path
set DESTINATION=F:\Repositories\lhs\pkg\lhs\src
:: dos2unix
set DOS2UNIX="C:\MinGW\msys\1.0\bin\dos2unix.exe"

echo ****
echo **** copying sources ****
echo ****
cp ./lhslib/*.h %DESTINATION%
cp ./lhslib/*.cpp %DESTINATION%
cp ./lhs_r/*.h %DESTINATION%
cp ./lhs_r/*.cpp %DESTINATION%
cp ./bclib/*.h %DESTINATION%

:: ensure only unix line endings
echo ****
echo **** dos2unix ****
echo ****
for /r "%DESTINATION%" %%x in (*.cpp) do %DOS2UNIX% "%%x"
for /r "%DESTINATION%" %%x in (*.h) do %DOS2UNIX% "%%x"

echo on

PAUSE
