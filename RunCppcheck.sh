#!/bin/bash -e
ROOTDIR=`pwd`
PREPROCESOR='-D MogeLib_EXPORT=True'
SUPRESS="--suppress=information:SDL_surface.h --suppress=information:gtest/gtest.h"
SETTINGS="--enable=all --std=c++11 --suppress=missingIncludeSystem $SUPRESS"
CPP_FILES=`find . -name '*.cpp' | tr '\n' ' '`
HEADERS_LIST=`find . -name '*.h*'`
HEADERS=$(dirname ${HEADERS_LIST})
HEADERS=`for i in \`echo $HEADERS\`; do
	echo $i
done | sort -u`
#HEADERS=`echo $HEADERS | tr '\.' "-\I ."`
HEADERS=`echo $HEADERS | sed 's/\./-I ./g'` 
echo "Runing cppcheck..."
if [ "$1" == "--check-config" ];then
	cppcheck $ROOTDIR $CPP_FILES $SETTINGS $PREPROCESOR $HEADERS --check-config 2> "CppCheckConfig.txt"
else
	cppcheck $ROOTDIR $CPP_FILES $SETTINGS $PREPROCESOR $HEADERS 2> StaticAnalysis.txt
fi

find . -name '*.h' > HeaderList.txt
find . -name '*.cpp' > SourceList.txt
