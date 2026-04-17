cmake_minimum_required(VERSION 3.20)
project(lhslib)
set(CMAKE_VERBOSE_MAKEFILE ON)

# CMAKE_BUILD_TYPE expected Release, Debug, RelWithDebInfo
message(VERBOSE, "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
# BUILD_TYPE Clang, Coverage, Clang-san, Gcc-san
message(VERBOSE, "BUILD_TYPE: ${BUILD_TYPE}")

file(READ bclib/BCLIBVERSION version_data)
string(STRIP "${version_data}" version_data)
file(READ bclib/bclibVersion.h.in version_header)
string(REGEX REPLACE "0[.]0[.]0" "${version_data}" new_version_header "${version_header}")
file(WRITE bclib/bclibVersion.h "${new_version_header}")

file(READ LHSLIBVERSION version_data)
string(STRIP "${version_data}" version_data)
file(READ lhslib/lhslibVersion.h.in version_header)
string(REGEX REPLACE "0[.]0[.]0" "${version_data}" new_version_header "${version_header}")
file(WRITE lhslib/lhslibVersion.h "${new_version_header}")

file(READ doxygen.config doxygen_data)
string(REGEX REPLACE "PROJECT[_]NUMBER[ ]*[=][ ]*[0-9]*[.][0-9]*[.][0-9]*" "PROJECT_NUMBER         = ${version_data}" new_version_header "${doxygen_data}")
file(WRITE doxygen.config "${new_version_header}")

if (MSVC)
    message(VERBOSE, "Windows Build")
    # 26439 is special_noexcept
    # 4100 is The formal parameter is not referenced in the body of the function
    # 4702 is unreachable code for the assertion code
	# 4127 is constant conditional expression
	# 26495 is not initialized variables
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /std:c++17 /W4 /WX /wd4100 /wd26439 /wd4702 /wd4127 /wd26495")
    set(CMAKE_CXX_FLAGS_DEBUG "/Od /Zi")
    set(CMAKE_CXX_FLAGS_RELEASE "/Ox")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/O2 /Zi")
elseif (BUILD_TYPE STREQUAL "Clang")
    message(VERBOSE, "Clang Build")
    # sudo apt-get install clang llvm
    # compiler options from https://www.stats.ox.ac.uk/pub/bdr/Rconfig/r-devel-linux-x86_64-fedora-clang
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -pedantic -frtti")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O2")
elseif (BUILD_TYPE STREQUAL "Clang-san")
    message(VERBOSE, "Clang-san Build")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -pedantic -frtti")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fno-sanitize=float-divide-by-zero -fno-sanitize=alignment -fno-omit-frame-pointer")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O1")
    set(CMAKE_CXX_FLAGS_RELEASE "-g -O1")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O1")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined,address")
else ()
    message(VERBOSE, "Gcc Build")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -m64 -Wall -pedantic -mtune=native -Werror -Wno-unknown-pragmas -Wno-long-long")

    if (BUILD_TYPE STREQUAL "Coverage")
        message(VERBOSE, "Gcc Coverage Build")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
        set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
        set(CMAKE_CXX_FLAGS_RELEASE "-g -O0")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O0")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")
    elseif (BUILD_TYPE STREQUAL "Gcc-san")
        message(VERBOSE, "Gcc-san Build")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined,bounds-strict -fno-omit-frame-pointer")
        set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
        set(CMAKE_CXX_FLAGS_RELEASE "-g -O2")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O2")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address,undefined -pthread")
    else ()
        message(VERBOSE, "Gcc Build")
        set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
        set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O2")
    endif()  
endif()

message(VERBOSE, "CXXFLAGS: ${CMAKE_CXX_FLAGS}")
message(VERBOSE, "Debug: ${CMAKE_CXX_FLAGS_DEBUG}")
message(VERBOSE, "Release: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "Linker FLAGS: ${CMAKE_EXE_LINKER_FLAGS}")

add_subdirectory(lhslib)
add_subdirectory(lhstest)

# don't forget git submodule init, git submodule update
