# $1 should be Debug or Release or RelWithDebInfo
# $2 should be Clang or Clang-san or Gcc-san or Coverage

if [ "$(uname -s)" = "MSYS_NT-10.0-WOW" ]; then
  echo Windows Build
  cmake . -Bbuild -DCMAKE_BUILD_TYPE=$1 -G "Visual Studio 15 2017 Win64"
  cmake --build build --target ALL_BUILD --config $1
  ./build/lhstest/$1/lhstest.exe
elif [ "$2" = "Clang" ]; then
  # sudo apt-get install clang llvm
  echo Clang Build
  export CC=clang
  export CXX=clang++
  cmake . -Bclangbuild -DCMAKE_BUILD_TYPE=$1 -DBUILD_TYPE=$2 -D_CMAKE_TOOLCHAIN_PREFIX='llvm-'  
  cmake --build clangbuild
  ./clangbuild/lhstest/lhstest
elif [ "$2" = "Clang-san" ]; then
  # sudo apt-get install clang llvm
  echo Clang SAN Build
  export CC=clang
  export CXX=clang++
  cmake . -Bclangsanbuild -DCMAKE_BUILD_TYPE=$1 -DBUILD_TYPE=$2 -D_CMAKE_TOOLCHAIN_PREFIX='llvm-'  
  cmake --build clangsanbuild
  ./clangsanbuild/lhstest/lhstest
elif [ "$2" = "Gcc-san" ]; then
  echo Linux SAN Build
  cmake . -Bgccsanbuild -DCMAKE_BUILD_TYPE=$1 -DBUILD_TYPE=$2
  cmake --build gccsanbuild
  ./gccsanbuild/lhstest/lhstest
elif [ "$2" = "Coverage" ]; then
  echo Linux Coverage Build
  cmake . -Bcoveragebuild -DCMAKE_BUILD_TYPE=$1 -DBUILD_TYPE=$2
  cmake --build coveragebuild
  ./coveragebuild/lhstest/lhstest
else
  echo Linux Build
  cmake . -Bbuild -DCMAKE_BUILD_TYPE=$1 -DBUILD_TYPE=$2
  cmake --build build
  ./build/lhstest/lhstest
fi


