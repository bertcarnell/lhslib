#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=RTools-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/lhs_r.o \
	${OBJECTDIR}/lhs_r_utilities.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64 -Wall -pedantic
CXXFLAGS=-m64 -Wall -pedantic

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/Program\ Files/R/R-3.0.1/library/Rcpp/lib/x64 -L/C/Program\ Files/R/R-3.0.1/bin/x64 -L/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib/dist/Debug/RTools-Windows -lR -lRcpp -llhslib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblhs_r.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblhs_r.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblhs_r.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared

${OBJECTDIR}/lhs_r.o: lhs_r.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Program\ Files/R/R-3.0.1/include -I/C/Program\ Files/R/R-3.0.1/library/Rcpp/include -I../bclib -std=c++98 -Wall -pedantic  -MMD -MP -MF $@.d -o ${OBJECTDIR}/lhs_r.o lhs_r.cpp

${OBJECTDIR}/lhs_r_utilities.o: lhs_r_utilities.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Program\ Files/R/R-3.0.1/include -I/C/Program\ Files/R/R-3.0.1/library/Rcpp/include -I../bclib -std=c++98 -Wall -pedantic  -MMD -MP -MF $@.d -o ${OBJECTDIR}/lhs_r_utilities.o lhs_r_utilities.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblhs_r.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
