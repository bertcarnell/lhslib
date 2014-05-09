cmake_minimum_required(VERSION 2.8)
project(LHS)

set(CMAKE_CXX_FLAGS "-g -std=c++0x -m64 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g -std=c++0x -m64 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -std=c++0x -m64 -Wall")
set(CMAKe_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -std=c++0x -m64 -Wall")

add_subdirectory(lhslib)
add_subdirectory(lhstest)
#add_subdirectory(lhs_r) # don't add this one because of the R requirement not on drone.io
