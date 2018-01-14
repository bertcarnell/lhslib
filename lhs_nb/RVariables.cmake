message(STATUS "-------------------RVariables---------------------")

# find the R includes
execute_process(
  COMMAND R "--slave" "-e" "cat(R.home('include'))" 
  RESULT_VARIABLE R_FAIL
  OUTPUT_VARIABLE R_INCLUDE_DIR
  ERROR_VARIABLE R_ERROR
)
if(${R_FAIL})
  message(STATUS ${R_ERROR})
  message(FATAL_ERROR "Error with R ...")
endif()
message(STATUS "R_INCLUDE_DIR: ${R_INCLUDE_DIR}")

# find the R .so for linking
execute_process(
  COMMAND R "--slave" "-e" "cat(R.home('lib'))" 
  RESULT_VARIABLE R_FAIL
  OUTPUT_VARIABLE R_LINKER_DIR
  ERROR_VARIABLE R_ERROR
)
if(${R_FAIL})
  message(STATUS ${R_ERROR})
  message(FATAL_ERROR "Error with R...")
endif()
message(STATUS "R_LINKER_DIR: ${R_LINKER_DIR}")

find_library(R_LIBRARY libR.so HINTS ${R_LINKER_DIR})
message(STATUS "R_LIBRARY: ${R_LIBRARY}")

# find Rcpp Includes
execute_process(
  COMMAND R "--slave" "-e" "cat(Rcpp:::Rcpp.system.file('include'))" 
  RESULT_VARIABLE RCPP_FAIL
  OUTPUT_VARIABLE RCPP_INCLUDE_DIR
  ERROR_VARIABLE RCPP_ERROR
)
if(${RCPP_FAIL})
  message(STATUS ${RCPP_ERROR})
  message(FATAL_ERROR "Error with Rcpp...")
endif()
message(STATUS "RCPP_INCLUDE_DIR: ${RCPP_INCLUDE_DIR}")

# find Rcpp shared object
execute_process(
  COMMAND R "--slave" "-e" "cat(Rcpp:::Rcpp.system.file('libs'))" 
  RESULT_VARIABLE RCPP_FAIL
  OUTPUT_VARIABLE RCPP_LINKER_DIR
  ERROR_VARIABLE RCPP_ERROR
)
if(${RCPP_FAIL})
  message(STATUS ${RCPP_ERROR})
  message(FATAL_ERROR "Error with Rcpp...")
endif()
message(STATUS "RCPP_LINKER_DIR: ${RCPP_LINKER_DIR}")

find_library(RCPP_LIBRARY Rcpp.so HINTS ${RCPP_LINKER_DIR})
message(STATUS "RCPP_LIBRARY: ${RCPP_LIBRARY}")

message(STATUS "-------------------End RVariables---------------------")

