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
CND_CONF=Profile
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/geneticLHS_RTest.o \
	${OBJECTDIR}/improvedLHS_RTest.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/maximinLHS_RTest.o \
	${OBJECTDIR}/optSeededLHS_RTest.o \
	${OBJECTDIR}/optimumLHS_RTest.o \
	${OBJECTDIR}/randomLHS_RTest.o \
	${OBJECTDIR}/utilityLHS_RTest.o


# C Compiler Flags
CFLAGS=-pg

# CC Compiler Flags
CCFLAGS=-m64 -std=c++0x -pg
CXXFLAGS=-m64 -std=c++0x -pg

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib/dist/Debug/RTools-Windows -llhslib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lhstest.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lhstest.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lhstest ${OBJECTFILES} ${LDLIBSOPTIONS} -pg

${OBJECTDIR}/geneticLHS_RTest.o: geneticLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -I../bclib -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geneticLHS_RTest.o geneticLHS_RTest.cpp

${OBJECTDIR}/improvedLHS_RTest.o: improvedLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -I../bclib -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/improvedLHS_RTest.o improvedLHS_RTest.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -I../bclib -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/maximinLHS_RTest.o: maximinLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -I../bclib -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/maximinLHS_RTest.o maximinLHS_RTest.cpp

${OBJECTDIR}/optSeededLHS_RTest.o: optSeededLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -I../bclib -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/optSeededLHS_RTest.o optSeededLHS_RTest.cpp

${OBJECTDIR}/optimumLHS_RTest.o: optimumLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -I../bclib -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/optimumLHS_RTest.o optimumLHS_RTest.cpp

${OBJECTDIR}/randomLHS_RTest.o: randomLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -I../bclib -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/randomLHS_RTest.o randomLHS_RTest.cpp

${OBJECTDIR}/utilityLHS_RTest.o: utilityLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -I../bclib -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utilityLHS_RTest.o utilityLHS_RTest.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lhstest.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
