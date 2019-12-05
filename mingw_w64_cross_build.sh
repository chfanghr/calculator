#!/usr/bin/env bash

set -e

mkdir .__deps
cd .__deps

export CFLAGS=-I$PWD/include
export CPPFLAGS=-I$PWD/include
export LDFLAGS=-L$PWD/lib
export CMAKE_PREFIX_PATH=$PWD

wget https://ftp.gnu.org/gnu/readline/readline-8.0.tar.gz
wget https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.1.tar.gz

tar -xf readline-8.0.tar.gz
tar -xf ncurses-6.1.tar.gz

cd ncurses-6.1
./configure --prefix=$PWD/.. --host=x86_64-w64-mingw32 --disable-shared --enable-static --enable-term-driver --enable-sp-funcs
make -j8
make install
cd ..

cd readline-8.0
./configure --prefix=$PWD/.. --host=x86_64-w64-mingw32 --disable-shared --enable-static
make -j8
make install
cd ..

cd ..

mkdir mingw_w64_build
cd mingw_w64_build

cmake -DCMAKE_BUILD_TYPE=Release  \
      -DCMAKE_TOOLCHAIN_FILE=../cmake/i686-w64-mingw32.cmake \
      -DBUILD_TESTING=OFF \
      -DCMAKE_PREFIX_PATH="${CMAKE_PREFIX_PATH}" ..

exit 0