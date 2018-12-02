rm -rf cmakebuild
mkdir cmakebuild
cd cmakebuild
"c:\Program Files (x86)\CMake 2.8\bin\cmake.exe" -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=C:/Rtools/gcc-4.6.3/bin/g++.exe -DCMAKE_BUILD_TYPE=Debug ..

"C:\MinGW\bin\mingw32-make.exe"

bclibtest\bclibtest.exe
  
  

:: %1 is Debug, Release
if "%1"=="" (GOTO :firststop)
if "%2"=="" (echo No compiler specified, using visual studio)
GOTO :continue

:firststop
echo %0 uses command:  %0 [Debug,Release] [MinGw,VS]
PAUSE
EXIT

:continue

:: %2 is MinGW or any other (e.g. VS)

cd ..
rm -rf build
mkdir build
cd build

IF "%2"=="MinGW" (GOTO :section1) ELSE (GOTO :section2)

:section1

set path=%path:c:\Rtools\bin;=%

"c:\Program Files (x86)\CMake 2.8\bin\cmake.exe" -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=C:/Rtools/gcc-4.6.3/bin/g++.exe -DCMAKE_BUILD_TYPE=%1 ../src

"C:\MinGW\bin\mingw32-make.exe"

oatest\oatest.exe
oalhstest\oalhstest.exe

PAUSE
EXIT

:section2

"c:\Program Files (x86)\CMake 2.8\bin\cmake.exe" -G "Visual Studio 12" -DCMAKE_BUILD_TYPE=%1 ../src

"C:\Program Files (x86)\MSBuild\12.0\Bin\msbuild.exe" OA.sln /t:Rebuild /p:Configuration=Debug

oatest\Debug\oatest.exe
oalhstest\Debug\oalhstest.exe

PAUSE
EXIT
