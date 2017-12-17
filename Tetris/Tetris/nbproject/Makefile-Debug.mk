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
CND_PLATFORM=Cygwin-Windows
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
	${OBJECTDIR}/_ext/5c0/main.o \
	${OBJECTDIR}/_ext/511e4115/Brick.o \
	${OBJECTDIR}/_ext/511e4115/BrickFactory.o \
	${OBJECTDIR}/_ext/511e4115/Game.o \
	${OBJECTDIR}/_ext/511e4115/MainGrid.o \
	${OBJECTDIR}/_ext/511e4115/Slab.o \
	${OBJECTDIR}/_ext/511e4115/TableCoordinates.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../../deps/SDL2Wrapper/deps/CUL/build/Cygwin-Windows-Debug/libcul.a ../../deps/SDL2Wrapper/deps/CUL/build/Cygwin-Windows-Debug/libcul.dll ../../deps/SDL2Wrapper/build/Cygwin-Windows-Debug/libSDL2Wrapper.a ../../deps/SDL2Wrapper/build/Cygwin-Windows-Debug/libSDL2Wrapper.dll ../../build/Cygwin-Windows-Debug/libmoge.a ../../build/Cygwin-Windows-Debug/libmoge.dll

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../build/${CND_PLATFORM}-${CND_CONF}/tetris.exe

../../build/${CND_PLATFORM}-${CND_CONF}/tetris.exe: ../../deps/SDL2Wrapper/deps/CUL/build/Cygwin-Windows-Debug/libcul.a

../../build/${CND_PLATFORM}-${CND_CONF}/tetris.exe: ../../deps/SDL2Wrapper/deps/CUL/build/Cygwin-Windows-Debug/libcul.dll

../../build/${CND_PLATFORM}-${CND_CONF}/tetris.exe: ../../deps/SDL2Wrapper/build/Cygwin-Windows-Debug/libSDL2Wrapper.a

../../build/${CND_PLATFORM}-${CND_CONF}/tetris.exe: ../../deps/SDL2Wrapper/build/Cygwin-Windows-Debug/libSDL2Wrapper.dll

../../build/${CND_PLATFORM}-${CND_CONF}/tetris.exe: ../../build/Cygwin-Windows-Debug/libmoge.a

../../build/${CND_PLATFORM}-${CND_CONF}/tetris.exe: ../../build/Cygwin-Windows-Debug/libmoge.dll

../../build/${CND_PLATFORM}-${CND_CONF}/tetris.exe: ${OBJECTFILES}
	${MKDIR} -p ../../build/${CND_PLATFORM}-${CND_CONF}
	g++ -o ../../build/${CND_PLATFORM}-${CND_CONF}/tetris ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/5c0/main.o: ../main.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -DMogeLib_EXPORT -I../../MogeLib/inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -I../inc -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/main.o ../main.cpp

${OBJECTDIR}/_ext/511e4115/Brick.o: ../src/Brick.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -g -DMogeLib_EXPORT -I../../MogeLib/inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -I../inc -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Brick.o ../src/Brick.cpp

${OBJECTDIR}/_ext/511e4115/BrickFactory.o: ../src/BrickFactory.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -g -DMogeLib_EXPORT -I../../MogeLib/inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -I../inc -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/BrickFactory.o ../src/BrickFactory.cpp

${OBJECTDIR}/_ext/511e4115/Game.o: ../src/Game.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -g -DMogeLib_EXPORT -I../../MogeLib/inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -I../inc -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Game.o ../src/Game.cpp

${OBJECTDIR}/_ext/511e4115/MainGrid.o: ../src/MainGrid.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -g -DMogeLib_EXPORT -I../../MogeLib/inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -I../inc -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/MainGrid.o ../src/MainGrid.cpp

${OBJECTDIR}/_ext/511e4115/Slab.o: ../src/Slab.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -g -DMogeLib_EXPORT -I../../MogeLib/inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -I../inc -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Slab.o ../src/Slab.cpp

${OBJECTDIR}/_ext/511e4115/TableCoordinates.o: ../src/TableCoordinates.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -g -DMogeLib_EXPORT -I../../MogeLib/inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -I../inc -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/TableCoordinates.o ../src/TableCoordinates.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ../../build/${CND_PLATFORM}-${CND_CONF}/libcul.dll ../../build/${CND_PLATFORM}-${CND_CONF}/libSDL2Wrapper.dll ../../build/${CND_PLATFORM}-${CND_CONF}/libmoge.dll
	${RM} ../../build/${CND_PLATFORM}-${CND_CONF}/tetris.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
