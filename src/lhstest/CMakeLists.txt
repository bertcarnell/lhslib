add_executable(lhstest geneticLHS_RTest.cpp
                       improvedLHS_RTest.cpp
					   maximinLHS_RTest.cpp
					   optimumLHS_RTest.cpp
					   optSeededLHS_RTest.cpp
					   randomLHS_RTest.cpp
					   utilityLHS_RTest.cpp
					   main.cpp)
					   
target_include_directories(lhstest PUBLIC ${CMAKE_SOURCE_DIR}/bclib ${CMAKE_SOURCE_DIR}/lhslib)

target_link_libraries(lhstest PRIVATE lhslib)
