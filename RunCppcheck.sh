#!/bin/bash -xe
ROOTDIR="Tetris"
INCLUDES="-I $ROOTDIR/MogeLib/inc -I Tetris/inc"
PREPROCESOR='-D MOGE_API'
SETTINGS="--enable=all --std=c++11 --suppress=missingIncludeSystem"
cppcheck --check-config $SETTINGS $PREPROCESOR  "$ROOTDIR" $INCLUDES &> "CppCheckConfig.log"
cppcheck $SETTINGS $PREPROCESOR "$ROOTDIR" $INCLUDES 2> StaticAnalysis.txt
