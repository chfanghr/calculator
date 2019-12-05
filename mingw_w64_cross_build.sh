#!/usr/bin/env bash

set -e

if [ -d ".__deps" ]; then rm -rf ".__deps"; fi

NPROCS=$(nproc 2>/dev/null || \
        sysctl -n hw.ncpu 2>/dev/null || \
        getconf _NPROCESSORS_ONLN 2>/dev/null)

mkdir .__deps
cd .__deps

#export CFLAGS=-I"$PWD"/include
export CPPFLAGS=-I"$PWD"/include
export LDFLAGS=-L"$PWD"/lib
export CMAKE_PREFIX_PATH="$PWD"

wget https://ftp.gnu.org/gnu/readline/readline-8.0.tar.gz
wget https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.1.tar.gz
wget http://ftp.gnu.org/gnu/termcap/termcap-1.3.1.tar.gz

tar -xf readline-8.0.tar.gz
tar -xf ncurses-6.1.tar.gz
tar -xf termcap-1.3.1.tar.gz

cd termcap-1.3.1
./configure --prefix="$PWD"/.. --host=x86_64-w64-mingw32
make -j"${NPROCS}"
make install
cd ..

cd ncurses-6.1
./configure --prefix="$PWD"/.. --host=x86_64-w64-mingw32 --disable-shared --enable-static --enable-term-driver --enable-sp-funcs
make -j"${NPROCS}"
make install
cd ..

cd readline-8.0
./configure --prefix="$PWD"/.. --host=x86_64-w64-mingw32 --enable-shared --enable-static
make -j"${NPROCS}"
make install
cd ..

cd ..

if [ -d "mingw_w64_build" ]; then rm -rf "mingw_w64_build"; fi

mkdir mingw_w64_build
cd mingw_w64_build

cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_TOOLCHAIN_FILE=../cmake/i686-w64-mingw32.cmake \
      -DBUILD_TESTING=OFF \
      -DCMAKE_PREFIX_PATH="${CMAKE_PREFIX_PATH}" ..

make -j"${NPROCS}"

exit 0