#!/bin/bash -xe
ROOTDIR="Tetris"
MOGELIB_ROOT="-I $ROOTDIR/MogeLib/inc "
MOGELIB_RO="-I $ROOTDIR/MogeLib/RenderableObject/inc -I $ROOTDIR/MogeLib/RenderableObject/src"
MOGELIB_SCENE="-I $ROOTDIR/MogeLib/Scene/inc"
MOGELIB_STRING="-I $ROOTDIR/String/inc"
MOGEMATH_ROOT="-I $ROOTDIR/MogeMath/inc"
TETRIS_ROOT="-I $ROOTDIR/inc"
INCLUDES="$MOGELIB_ROOT $MOGELIB_RO $MOGELIB_SCENE $MOGELIB_STRING $MOGEMATH_ROOT $TETRIS_ROOT" 
PREPROCESOR='-D MogeLib_EXPORT=True'
SETTINGS="--enable=all --std=c++11 --suppress=missingIncludeSystem"
cppcheck --check-config $SETTINGS $PREPROCESOR  "$ROOTDIR" $INCLUDES &> "CppCheckConfig.log"
cppcheck $SETTINGS $PREPROCESOR "$ROOTDIR" $INCLUDES 2> StaticAnalysis.txt
