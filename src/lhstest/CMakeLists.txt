include_directories(${LHSLIB_SOURCE_DIR}/bclib)
include_directories(${LHSLIB_SOURCE_DIR}/lhslib)

add_executable(lhstest geneticLHS_RTest.cpp
                       improvedLHS_RTest.cpp
					   main.cpp
					   maximinLHS_RTest.cpp
					   optimumLHS_RTest.cpp
					   optSeededLHS_RTest.cpp
					   randomLHS_RTest.cpp
					   utilityLHS_RTest.cpp)

link_directories(${LHSLIB_SOURCE_DIR}/lhslib)
target_link_libraries(lhstest lhslib)
