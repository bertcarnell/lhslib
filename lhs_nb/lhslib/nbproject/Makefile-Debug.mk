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
	${OBJECTDIR}/geneticLHS.o \
	${OBJECTDIR}/improvedLHS.o \
	${OBJECTDIR}/maximinLHS.o \
	${OBJECTDIR}/optSeededLHS.o \
	${OBJECTDIR}/optimumLHS.o \
	${OBJECTDIR}/randomLHS.o \
	${OBJECTDIR}/utilityLHS.o


# C Compiler Flags
CFLAGS=-m64

# CC Compiler Flags
CCFLAGS=-m64 -Wall -pedantic
CXXFLAGS=-m64 -Wall -pedantic

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=--64

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblhslib.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblhslib.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblhslib.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblhslib.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblhslib.a

${OBJECTDIR}/geneticLHS.o: geneticLHS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -I../bclib -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/geneticLHS.o geneticLHS.cpp

${OBJECTDIR}/improvedLHS.o: improvedLHS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -I../bclib -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/improvedLHS.o improvedLHS.cpp

${OBJECTDIR}/maximinLHS.o: maximinLHS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -I../bclib -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/maximinLHS.o maximinLHS.cpp

${OBJECTDIR}/optSeededLHS.o: optSeededLHS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -I../bclib -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/optSeededLHS.o optSeededLHS.cpp

${OBJECTDIR}/optimumLHS.o: optimumLHS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -I../bclib -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/optimumLHS.o optimumLHS.cpp

${OBJECTDIR}/randomLHS.o: randomLHS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -I../bclib -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/randomLHS.o randomLHS.cpp

${OBJECTDIR}/utilityLHS.o: utilityLHS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -I../bclib -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utilityLHS.o utilityLHS.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblhslib.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
