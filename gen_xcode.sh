#!/bin/bash

ROOT_DIR=$(PWD)
OUT_DIR=$ROOT_DIR/build_xcode

rm -rf $OUT_DIR/CMakeCache.txt

mkdir $OUT_DIR

cd $OUT_DIR

cmake -G "Xcode" \
-DCMAKE_CXX_COMPILER=$(xcrun -find clang++) \
-DCMAKE_C_COMPILER=$(xcrun -find clang) \
-DCMAKE_OSX_DEPLOYMENT_TARGET:STRING=11.0 \
-DENABLE_BITCODE=0 \
-DSQLITE_WINQ_BUILD_EXAMPLES=ON \
../


if [[ $? == 0 ]]; then
    xed .
fi

cd $ROOT_DIR