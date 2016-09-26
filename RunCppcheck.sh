#!/bin/bash -xe
ROOTDIR=`pwd`
MOGELIB_ROOT="-I MogeLib/inc "
MOGELIB_RO="-I MogeLib/RenderableObject/inc -I MogeLib/RenderableObject/src "
MOGELIB_SCENE="-I MogeLib/Scene/inc "
MOGELIB_STRING="-I String/inc "
MOGEMATH_ROOT="-I MogeMath/inc "
TESTS="-I Tests/inc/"
TETRIS_ROOT="-I inc"
INCLUDES="$MOGELIB_ROOT $MOGELIB_RO $MOGELIB_SCENE $MOGELIB_STRING $MOGEMATH_ROOT $TETRIS_ROOT $TESTS" 
PREPROCESOR='-D MogeLib_EXPORT=True'
SETTINGS="--enable=all --std=c++11 --suppress=missingIncludeSystem"
cppcheck "$ROOTDIR" --check-config $SETTINGS $PREPROCESOR $INCLUDES 2> "CppCheckConfig.log"
cppcheck "$ROOTDIR" $SETTINGS $PREPROCESOR $INCLUDES 2> StaticAnalysis.txt
