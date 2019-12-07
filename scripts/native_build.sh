#!/usr/bin/env bash

set -e

kernel=$(uname | tr '[:upper:]' '[:lower:]')
NPROCS=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null)

if [ -d "${kernel}_build_debug" ]; then rm -rf ${kernel}_build_debug; fi
if [ -d "${kernel}_build_debug" ]; then rm -rf ${kernel}_build_debug; fi
if [ -d "${kernel}_release" ]; then rm -rf ${kernel}_release; fi

mkdir ${kernel}_release

cmake -DCMAKE_BUILD_TYPE=Debug \
  -DBUILD_TESTS=ON \
  -H. -B"${kernel}_build_debug"
cmake --build ${kernel}_build_debug

cmake -DCMAKE_INSTALL_PREFIX=${PWD}/${kernel}_release \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_TESTS=OFF \
  -H. -B"${kernel}_build_release"
cd ${kernel}_build_release
make -j${NPROC}
make install
cd ..

zip -r ${kernel}_build.zip ${kernel}_build_debug ${kernel}_build_release

zip -r ${kernel}_release.zip ${kernel}_release
