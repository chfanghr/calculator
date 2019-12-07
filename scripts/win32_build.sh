#!/usr/bin/env bash

set -e

if [ -d ".__deps" ]; then rm -rf ".__deps"; fi

NPROCS=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null)

if [ -d "Win32_build_release" ]; then rm -rf "Win32_build_release"; fi
if [ -d "Win32_build_debug" ]; then rm -rf "Win32_build_debug"; fi
if [ -d "Win32_deps" ]; then rm -rf "Win32_deps"; fi
if [ -d "win32_release" ]; then rm -rf "win32_release"; fi

mkdir Win32_build_release
cd Win32_build_release

cmake -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_TOOLCHAIN_FILE=../cmake/i686-w64-mingw32.cmake \
  -DBUILD_TESTING=OFF \
  -DCMAKE_PREFIX_PATH="${CMAKE_PREFIX_PATH}" ..

make -j"${NPROCS}"

cd ..

mkdir Win32_build_debug
cd Win32_build_debug

cmake -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_TOOLCHAIN_FILE=../cmake/i686-w64-mingw32.cmake \
  -DBUILD_TESTING=OFF \
  -DCMAKE_PREFIX_PATH="${CMAKE_PREFIX_PATH}" ..

make -j"${NPROCS}"

cd ..

mkdir Win32_deps
cd Win32_deps

cp /usr/lib/gcc/x86_64-w64-mingw32/*-win32/*.dll . >/dev/null 2>&1 || cp \
  /usr/local/Cellar/mingw-w64/*/toolchain-x86_64/x86_64-w64-mingw32/lib/*.dll . >/dev/null 2>&1

cd ..

zip -r Win32_build.zip Win32_deps Win32_build_debug Win32_build_release

mkdir win32_release
cd win32_release

cp ../Win32_deps/libstdc++-*.dll .
cp ../Win32_deps/libgcc_s_seh-1.dll .

mkdir cmd
cp ../Win32_build_release/cmd/calc/calc.exe ./cmd/

mkdir examples
cp ../Win32_build_release/examples/*.exe ./examples

cd ..

zip -r win32_release.zip win32_release

exit 0
