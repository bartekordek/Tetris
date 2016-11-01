#!/bin/bash -xe
ROOTDIR=`pwd`
MOGELIB_ROOT="-I MogeLib/inc -I MogeLib/src"
MOGELIB_RO="-I MogeLib/RenderableObject/inc -I MogeLib/RenderableObject/src"
MOGELIB_SCENE="-I MogeLib/Scene/inc -I MogeLib/Scene/src"
MOGELIB_STRING="-I String/inc -I String/src"
MOGEMATH_ROOT="-I MogeMath/inc -I MogeMath/src -I MogeMath/Point"
TESTS="-I Tests/inc/ -I Tests/src/"
TETRIS_ROOT="-I Tetris/inc -I Tetris/src"
INCLUDES="$MOGELIB_ROOT $MOGELIB_RO $MOGELIB_SCENE $MOGELIB_STRING $MOGEMATH_ROOT $TETRIS_ROOT $TESTS" 
PREPROCESOR='-D MogeLib_EXPORT=True'
SETTINGS="--enable=all --std=c++11 --suppress=missingIncludeSystem"
#cppcheck "$ROOTDIR" --check-config $SETTINGS $PREPROCESOR $INCLUDES 2> "CppCheckConfig.log"
cppcheck "$ROOTDIR" $SETTINGS $PREPROCESOR $INCLUDES 2> StaticAnalysis.txt
find . -name '*.h' > HeaderList.txt
find . -name '*.cpp' > SourceList.txt
