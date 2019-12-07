#!/usr/bin/env bash

set -e

kernel=$(uname | tr '[:upper:]' '[:lower:]')

if [ -d "${kernel}_build_debug" ]; then rm -rf ${kernel}_build_debug; fi
if [ -d "${kernel}_build_debug" ]; then rm -rf ${kernel}_build_debug; fi
if [ -d "${kernel}_release" ]; then rm -rf ${kernel}_release; fi

cmake -DCMAKE_BUILD_TYPE=Debug -H. -B"${kernel}_build_debug"
cmake --build "${kernel}_build_debug"

cmake -DCMAKE_BUILD_TYPE=Release -H. -B"${kernel}_build_release"
cmake --build "${kernel}_build_release"

zip -r ${kernel}_build.zip ${kernel}_build_debug ${kernel}_build_release

mkdir ${kernel}_release
cd ${kernel}_release

mkdir bin
cp ../${kernel}_build_release/cmd/calc/calc ./bin

mkdir lib
cp ../${kernel}_build_release/libcalculator.a ./lib

cp -r ../include .

cd ..

zip -r ${kernel}_release.zip ${kernel}_release
