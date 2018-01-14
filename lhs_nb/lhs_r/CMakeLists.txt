include_directories(${LHS_SOURCE_DIR}/bclib)
include_directories(${LHS_SOURCE_DIR}/lhslib)
include_directories(${RCPP_INCLUDE_DIR})
include_directories(${R_INCLUDE_DIR})

link_directories(${LHS_SOURCE_DIR}/lhslib)
link_directories(${RCPP_LINKER_DIR})
link_directories(${R_LINKER_DIR})

add_library(lhs_r SHARED lhs_r.cpp lhs_r_utilities.cpp)

# order dependent, R is changed to -lR and finds libR.so
#  Rcpp was not handled properly, nor was RCPP_LIBRARY, -l:Rcpp.so is all that worked
target_link_libraries(lhs_r R -l:Rcpp.so lhslib) 
