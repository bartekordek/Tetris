#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
CND_PLATFORM=Cygwin-Windows
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build
CND_DLIB_EXT=dll
NBTMPDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tmp-packaging
TMPDIRNAME=tmp-packaging
OUTPUT_PATH=../../build/${CND_PLATFORM}-${CND_CONF}/mogelib.${CND_DLIB_EXT}
OUTPUT_BASENAME=mogelib.${CND_DLIB_EXT}
PACKAGE_TOP_DIR=libmogelib.dll/

# Functions
function checkReturnCode
{
    rc=$?
    if [ $rc != 0 ]
    then
        exit $rc
    fi
}
function makeDirectory
# $1 directory path
# $2 permission (optional)
{
    mkdir -p "$1"
    checkReturnCode
    if [ "$2" != "" ]
    then
      chmod $2 "$1"
      checkReturnCode
    fi
}
function copyFileToTmpDir
# $1 from-file path
# $2 to-file path
# $3 permission
{
    cp "$1" "$2"
    checkReturnCode
    if [ "$3" != "" ]
    then
        chmod $3 "$2"
        checkReturnCode
    fi
}

# Setup
cd "${TOP}"
mkdir -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package
rm -rf ${NBTMPDIR}
mkdir -p ${NBTMPDIR}

# Copy files and create directories and links
cd "${TOP}"
makeDirectory "${NBTMPDIR}/libmogelib.dll/lib"
copyFileToTmpDir "../../build/${CND_PLATFORM}-${CND_CONF}/libcul.dll" "${NBTMPDIR}/${PACKAGE_TOP_DIR}lib/libcul.dll" 0644

cd "${TOP}"
makeDirectory "${NBTMPDIR}/libmogelib.dll/lib"
copyFileToTmpDir "../../build/${CND_PLATFORM}-${CND_CONF}/libcul.dll" "${NBTMPDIR}/${PACKAGE_TOP_DIR}lib/libcul.dll" 0644

cd "${TOP}"
makeDirectory "${NBTMPDIR}/libmogelib.dll/lib"
copyFileToTmpDir "${OUTPUT_PATH}" "${NBTMPDIR}/${PACKAGE_TOP_DIR}lib/${OUTPUT_BASENAME}" 0644


# Generate tar file
cd "${TOP}"
rm -f ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/libmogelib.dll.tar
cd ${NBTMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/libmogelib.dll.tar *
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${NBTMPDIR}
