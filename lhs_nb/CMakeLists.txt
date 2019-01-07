cmake_minimum_required(VERSION 2.8)
project(LHS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64 -Wall -pedantic -mtune=native -fPIC -Werror -Wno-unknown-pragmas -Wno-long-long")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS} -O2 -g")

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")
  message(STATUS "CXXFLAGS: ${CMAKE_CXX_FLAGS}")
elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "Debug CXXFLAGS: ${CMAKE_CXX_FLAGS_DEBUG}")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
  message(STATUS "Release CXXFLAGS: ${CMAKE_CXX_FLAGS_RELEASE}")
else()
  message(STATUS "CXXFLAGS: ${CMAKE_CXX_FLAGS}")
endif()

message(STATUS "Linker FLAGS: ${CMAKE_EXE_LINKER_FLAGS}")

add_subdirectory(lhslib)
add_subdirectory(lhstest)

# don't forget git submodule init, git submodule update
