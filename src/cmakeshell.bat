rm -rf build
mkdir build
cd build

IF "%1"=="MinGW" (GOTO :section1) ELSE (GOTO :section2)

:section1

"C:\Program Files\CMake\bin\cmake.exe" -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=C:/Rtools/mingw_64/bin/g++.exe -DCMAKE_C_COMPILER=C:/Rtools/mingw_64/bin/gcc.exe -DCMAKE_MAKE_PROGRAM=C:/Rtools/mingw_64/bin/mingw32-make.exe -DCMAKE_BUILD_TYPE=Debug ..
C:\Rtools\mingw_64\bin\mingw32-make.exe

.\lhstest\lhstest.exe

GOTO :section3

:section2

cmake .. -G "Visual Studio 15 2017 Win64"

"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MsBuild.exe" LHSLIB.sln /t:Rebuild /p:Configuration=Debug

.\lhstest\Debug\lhstest.exe

GOTO :section3

:section3
PAUSE
