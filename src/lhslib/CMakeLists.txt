include_directories(${LHSLIB_SOURCE_DIR}/bclib)

add_library(lhslib STATIC geneticLHS.cpp improvedLHS.cpp maximinLHS.cpp optimumLHS.cpp optSeededLHS.cpp randomLHS.cpp utilityLHS.cpp)

