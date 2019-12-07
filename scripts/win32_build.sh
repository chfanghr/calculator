#!/usr/bin/env bash

set -e

if [ -d ".__deps" ]; then rm -rf ".__deps"; fi

NPROCS=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null)

if [ -d "win32_build_release" ]; then rm -rf "win32_build_release"; fi
if [ -d "win32_build_debug" ]; then rm -rf "win32_build_debug"; fi
if [ -d "win32_deps" ]; then rm -rf "win32_deps"; fi
if [ -d "win32_release" ]; then rm -rf "win32_release"; fi

mkdir win32_build_release
cd win32_build_release

cmake -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_TOOLCHAIN_FILE=../cmake/i686-w64-mingw32.cmake \
  -DBUILD_TESTS=OFF \
  -DCMAKE_PREFIX_PATH="${CMAKE_PREFIX_PATH}" ..

make -j"${NPROCS}"

cd ..

mkdir win32_build_debug
cd win32_build_debug

cmake -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_TOOLCHAIN_FILE=../cmake/i686-w64-mingw32.cmake \
  -DBUILD_TESTS=OFF \
  -DCMAKE_PREFIX_PATH="${CMAKE_PREFIX_PATH}" ..

make -j"${NPROCS}"

cd ..

mkdir win32_deps
cd win32_deps

cp /usr/lib/gcc/x86_64-w64-mingw32/*-win32/*.dll . >/dev/null 2>&1 || cp \
  /usr/local/Cellar/mingw-w64/*/toolchain-x86_64/x86_64-w64-mingw32/lib/*.dll . >/dev/null 2>&1

cd ..

zip -r win32_build.zip win32_deps win32_build_debug win32_build_release

mkdir win32_release
cd win32_release

mkdir bin
cp ../win32_build_release/cmd/calc/calc.exe ./bin

mkdir lib
cp ../win32_build_release/libcalculator.a ./lib

cp -r ../include .

cp ../win32_deps/libstdc++-*.dll ./lib
cp ../win32_deps/libgcc_s_seh-1.dll ./lib

cd ..

zip -r win32_release.zip win32_release

exit 0
