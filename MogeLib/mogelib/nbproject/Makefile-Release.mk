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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/511e4115/ConsoleUtilities.o \
	${OBJECTDIR}/_ext/511e4115/Engine.o \
	${OBJECTDIR}/_ext/511e4115/FPSCounterConcrete.o \
	${OBJECTDIR}/_ext/511e4115/File.o \
	${OBJECTDIR}/_ext/511e4115/Frustum.o \
	${OBJECTDIR}/_ext/511e4115/IFPSCounter.o \
	${OBJECTDIR}/_ext/511e4115/IKey.o \
	${OBJECTDIR}/_ext/511e4115/IKeyboardObservable.o \
	${OBJECTDIR}/_ext/511e4115/IKeyboardObservableImp.o \
	${OBJECTDIR}/_ext/511e4115/IKeyboardObserver.o \
	${OBJECTDIR}/_ext/511e4115/IMogeApp.o \
	${OBJECTDIR}/_ext/511e4115/INode.o \
	${OBJECTDIR}/_ext/511e4115/INodeCreator.o \
	${OBJECTDIR}/_ext/511e4115/IObservable.o \
	${OBJECTDIR}/_ext/511e4115/IObservableData.o \
	${OBJECTDIR}/_ext/511e4115/IObservableImpl.o \
	${OBJECTDIR}/_ext/511e4115/IPositionFactory.o \
	${OBJECTDIR}/_ext/511e4115/IRenderable.o \
	${OBJECTDIR}/_ext/511e4115/IRenderer.o \
	${OBJECTDIR}/_ext/511e4115/ITexture.o \
	${OBJECTDIR}/_ext/511e4115/ITime.o \
	${OBJECTDIR}/_ext/511e4115/ITimer.o \
	${OBJECTDIR}/_ext/511e4115/IVector3D.o \
	${OBJECTDIR}/_ext/511e4115/Iterator.o \
	${OBJECTDIR}/_ext/511e4115/KeySDL.o \
	${OBJECTDIR}/_ext/511e4115/KeyboardData.o \
	${OBJECTDIR}/_ext/511e4115/Line.o \
	${OBJECTDIR}/_ext/511e4115/ListFactory.o \
	${OBJECTDIR}/_ext/511e4115/MogeLibMain.o \
	${OBJECTDIR}/_ext/511e4115/MultiPointFactory.o \
	${OBJECTDIR}/_ext/511e4115/MyString.o \
	${OBJECTDIR}/_ext/511e4115/Node.o \
	${OBJECTDIR}/_ext/511e4115/NodeFactory2D.o \
	${OBJECTDIR}/_ext/511e4115/NodeFactory3D.o \
	${OBJECTDIR}/_ext/511e4115/PositionDouble2D.o \
	${OBJECTDIR}/_ext/511e4115/PositionDouble3D.o \
	${OBJECTDIR}/_ext/511e4115/Quaternion.o \
	${OBJECTDIR}/_ext/511e4115/Rectangle.o \
	${OBJECTDIR}/_ext/511e4115/RenderableSDLTexture.o \
	${OBJECTDIR}/_ext/511e4115/SDL2WrapperAdapter.o \
	${OBJECTDIR}/_ext/511e4115/SDLRenderer.o \
	${OBJECTDIR}/_ext/511e4115/Scale.o \
	${OBJECTDIR}/_ext/511e4115/Singleton.o \
	${OBJECTDIR}/_ext/511e4115/Size.o \
	${OBJECTDIR}/_ext/511e4115/SizeDouble2D.o \
	${OBJECTDIR}/_ext/511e4115/SizeDouble3D.o \
	${OBJECTDIR}/_ext/511e4115/TextureSDL.o \
	${OBJECTDIR}/_ext/511e4115/TimeConcrete.o \
	${OBJECTDIR}/_ext/511e4115/TimerChrono.o \
	${OBJECTDIR}/_ext/511e4115/Vector3DFactory.o \
	${OBJECTDIR}/_ext/511e4115/Visible.o


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
LDLIBSOPTIONS=-L../../deps/SDL2Wrapper/deps/CUL/CUL/libcul/../../build/Cygwin-Windows-Debug -lcul -L../../deps/SDL2Wrapper/deps/CUL/CUL/libcul/../../build/Cygwin-Windows-Release -lcul ../../deps/SDL2Wrapper/deps/SDL2-2.0.7/Build-Cygwin/libSDL2.dll.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../build/${CND_PLATFORM}-${CND_CONF}/mogelib.${CND_DLIB_EXT}
	${CP} ../../deps/SDL2Wrapper/deps/CUL/CUL/libcul/../../build/Cygwin-Windows-Debug/libcul.dll ../../build/${CND_PLATFORM}-${CND_CONF}
	${CP} ../../deps/SDL2Wrapper/deps/CUL/CUL/libcul/../../build/Cygwin-Windows-Release/libcul.dll ../../build/${CND_PLATFORM}-${CND_CONF}

../../build/${CND_PLATFORM}-${CND_CONF}/mogelib.${CND_DLIB_EXT}: ../../deps/SDL2Wrapper/deps/CUL/CUL/libcul/../../build/Cygwin-Windows-Debug/libcul.dll

../../build/${CND_PLATFORM}-${CND_CONF}/mogelib.${CND_DLIB_EXT}: ../../deps/SDL2Wrapper/deps/CUL/CUL/libcul/../../build/Cygwin-Windows-Release/libcul.dll

../../build/${CND_PLATFORM}-${CND_CONF}/mogelib.${CND_DLIB_EXT}: ../../deps/SDL2Wrapper/deps/SDL2-2.0.7/Build-Cygwin/libSDL2.dll.a

../../build/${CND_PLATFORM}-${CND_CONF}/mogelib.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ../../build/${CND_PLATFORM}-${CND_CONF}
	g++ -o ../../build/${CND_PLATFORM}-${CND_CONF}/mogelib.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -Wl,--out-implib,../../build/${CND_PLATFORM}-${CND_CONF}/libmoge.a -shared

${OBJECTDIR}/_ext/511e4115/ConsoleUtilities.o: ../src/ConsoleUtilities.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/ConsoleUtilities.o ../src/ConsoleUtilities.cpp

${OBJECTDIR}/_ext/511e4115/Engine.o: ../src/Engine.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Engine.o ../src/Engine.cpp

${OBJECTDIR}/_ext/511e4115/FPSCounterConcrete.o: ../src/FPSCounterConcrete.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/FPSCounterConcrete.o ../src/FPSCounterConcrete.cpp

${OBJECTDIR}/_ext/511e4115/File.o: ../src/File.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/File.o ../src/File.cpp

${OBJECTDIR}/_ext/511e4115/Frustum.o: ../src/Frustum.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Frustum.o ../src/Frustum.cpp

${OBJECTDIR}/_ext/511e4115/IFPSCounter.o: ../src/IFPSCounter.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IFPSCounter.o ../src/IFPSCounter.cpp

${OBJECTDIR}/_ext/511e4115/IKey.o: ../src/IKey.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IKey.o ../src/IKey.cpp

${OBJECTDIR}/_ext/511e4115/IKeyboardObservable.o: ../src/IKeyboardObservable.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IKeyboardObservable.o ../src/IKeyboardObservable.cpp

${OBJECTDIR}/_ext/511e4115/IKeyboardObservableImp.o: ../src/IKeyboardObservableImp.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IKeyboardObservableImp.o ../src/IKeyboardObservableImp.cpp

${OBJECTDIR}/_ext/511e4115/IKeyboardObserver.o: ../src/IKeyboardObserver.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IKeyboardObserver.o ../src/IKeyboardObserver.cpp

${OBJECTDIR}/_ext/511e4115/IMogeApp.o: ../src/IMogeApp.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IMogeApp.o ../src/IMogeApp.cpp

${OBJECTDIR}/_ext/511e4115/INode.o: ../src/INode.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/INode.o ../src/INode.cpp

${OBJECTDIR}/_ext/511e4115/INodeCreator.o: ../src/INodeCreator.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/INodeCreator.o ../src/INodeCreator.cpp

${OBJECTDIR}/_ext/511e4115/IObservable.o: ../src/IObservable.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IObservable.o ../src/IObservable.cpp

${OBJECTDIR}/_ext/511e4115/IObservableData.o: ../src/IObservableData.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IObservableData.o ../src/IObservableData.cpp

${OBJECTDIR}/_ext/511e4115/IObservableImpl.o: ../src/IObservableImpl.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IObservableImpl.o ../src/IObservableImpl.cpp

${OBJECTDIR}/_ext/511e4115/IPositionFactory.o: ../src/IPositionFactory.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IPositionFactory.o ../src/IPositionFactory.cpp

${OBJECTDIR}/_ext/511e4115/IRenderable.o: ../src/IRenderable.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IRenderable.o ../src/IRenderable.cpp

${OBJECTDIR}/_ext/511e4115/IRenderer.o: ../src/IRenderer.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IRenderer.o ../src/IRenderer.cpp

${OBJECTDIR}/_ext/511e4115/ITexture.o: ../src/ITexture.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/ITexture.o ../src/ITexture.cpp

${OBJECTDIR}/_ext/511e4115/ITime.o: ../src/ITime.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/ITime.o ../src/ITime.cpp

${OBJECTDIR}/_ext/511e4115/ITimer.o: ../src/ITimer.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/ITimer.o ../src/ITimer.cpp

${OBJECTDIR}/_ext/511e4115/IVector3D.o: ../src/IVector3D.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/IVector3D.o ../src/IVector3D.cpp

${OBJECTDIR}/_ext/511e4115/Iterator.o: ../src/Iterator.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Iterator.o ../src/Iterator.cpp

${OBJECTDIR}/_ext/511e4115/KeySDL.o: ../src/KeySDL.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/KeySDL.o ../src/KeySDL.cpp

${OBJECTDIR}/_ext/511e4115/KeyboardData.o: ../src/KeyboardData.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/KeyboardData.o ../src/KeyboardData.cpp

${OBJECTDIR}/_ext/511e4115/Line.o: ../src/Line.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Line.o ../src/Line.cpp

${OBJECTDIR}/_ext/511e4115/ListFactory.o: ../src/ListFactory.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/ListFactory.o ../src/ListFactory.cpp

${OBJECTDIR}/_ext/511e4115/MogeLibMain.o: ../src/MogeLibMain.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/MogeLibMain.o ../src/MogeLibMain.cpp

${OBJECTDIR}/_ext/511e4115/MultiPointFactory.o: ../src/MultiPointFactory.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/MultiPointFactory.o ../src/MultiPointFactory.cpp

${OBJECTDIR}/_ext/511e4115/MyString.o: ../src/MyString.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/MyString.o ../src/MyString.cpp

${OBJECTDIR}/_ext/511e4115/Node.o: ../src/Node.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Node.o ../src/Node.cpp

${OBJECTDIR}/_ext/511e4115/NodeFactory2D.o: ../src/NodeFactory2D.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/NodeFactory2D.o ../src/NodeFactory2D.cpp

${OBJECTDIR}/_ext/511e4115/NodeFactory3D.o: ../src/NodeFactory3D.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/NodeFactory3D.o ../src/NodeFactory3D.cpp

${OBJECTDIR}/_ext/511e4115/PositionDouble2D.o: ../src/PositionDouble2D.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/PositionDouble2D.o ../src/PositionDouble2D.cpp

${OBJECTDIR}/_ext/511e4115/PositionDouble3D.o: ../src/PositionDouble3D.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/PositionDouble3D.o ../src/PositionDouble3D.cpp

${OBJECTDIR}/_ext/511e4115/Quaternion.o: ../src/Quaternion.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Quaternion.o ../src/Quaternion.cpp

${OBJECTDIR}/_ext/511e4115/Rectangle.o: ../src/Rectangle.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Rectangle.o ../src/Rectangle.cpp

${OBJECTDIR}/_ext/511e4115/RenderableSDLTexture.o: ../src/RenderableSDLTexture.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/RenderableSDLTexture.o ../src/RenderableSDLTexture.cpp

${OBJECTDIR}/_ext/511e4115/SDL2WrapperAdapter.o: ../src/SDL2WrapperAdapter.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/SDL2WrapperAdapter.o ../src/SDL2WrapperAdapter.cpp

${OBJECTDIR}/_ext/511e4115/SDLRenderer.o: ../src/SDLRenderer.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/SDLRenderer.o ../src/SDLRenderer.cpp

${OBJECTDIR}/_ext/511e4115/Scale.o: ../src/Scale.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Scale.o ../src/Scale.cpp

${OBJECTDIR}/_ext/511e4115/Singleton.o: ../src/Singleton.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Singleton.o ../src/Singleton.cpp

${OBJECTDIR}/_ext/511e4115/Size.o: ../src/Size.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Size.o ../src/Size.cpp

${OBJECTDIR}/_ext/511e4115/SizeDouble2D.o: ../src/SizeDouble2D.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/SizeDouble2D.o ../src/SizeDouble2D.cpp

${OBJECTDIR}/_ext/511e4115/SizeDouble3D.o: ../src/SizeDouble3D.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/SizeDouble3D.o ../src/SizeDouble3D.cpp

${OBJECTDIR}/_ext/511e4115/TextureSDL.o: ../src/TextureSDL.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/TextureSDL.o ../src/TextureSDL.cpp

${OBJECTDIR}/_ext/511e4115/TimeConcrete.o: ../src/TimeConcrete.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/TimeConcrete.o ../src/TimeConcrete.cpp

${OBJECTDIR}/_ext/511e4115/TimerChrono.o: ../src/TimerChrono.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/TimerChrono.o ../src/TimerChrono.cpp

${OBJECTDIR}/_ext/511e4115/Vector3DFactory.o: ../src/Vector3DFactory.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Vector3DFactory.o ../src/Vector3DFactory.cpp

${OBJECTDIR}/_ext/511e4115/Visible.o: ../src/Visible.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e4115
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -DMogeLib_EXPORT -I../inc -I../../deps/SDL2Wrapper/deps/CUL/CUL -I../../deps/SDL2Wrapper/SDL2Wrapper/inc -I../../deps/SDL2Wrapper/deps/SDL2-2.0.7/include -I../../deps/SDL2Wrapper/deps/CUL/deps/boost_1_64_0 -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e4115/Visible.o ../src/Visible.cpp

# Subprojects
.build-subprojects:
	cd ../../deps/SDL2Wrapper/deps/CUL/CUL/libcul && ${MAKE} -j -f Makefile CONF=Debug
	cd ../../deps/SDL2Wrapper/deps/CUL/CUL/libcul && ${MAKE} -j -f Makefile CONF=Release

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ../../build/${CND_PLATFORM}-${CND_CONF}/libcul.dll ../../build/${CND_PLATFORM}-${CND_CONF}/libcul.dll
	${RM} ../../build/${CND_PLATFORM}-${CND_CONF}/mogelib.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../../deps/SDL2Wrapper/deps/CUL/CUL/libcul && ${MAKE} -j -f Makefile CONF=Debug clean
	cd ../../deps/SDL2Wrapper/deps/CUL/CUL/libcul && ${MAKE} -j -f Makefile CONF=Release clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
