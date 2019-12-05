#!/usr/bin/env bash

set -e

if [ -d ".__gtest_deps" ]; then rm -rf ".__gtest_deps"; fi

mkdir .__gtest_deps
cd .__gtest_deps

NPROCS=$(nproc 2>/dev/null ||
  sysctl -n hw.ncpu 2>/dev/null ||
  getconf _NPROCESSORS_ONLN 2>/dev/null)

wget https://github.com/google/googletest/archive/release-1.10.0.tar.gz
tar -xf release-1.10.0.tar.gz
cd googletest-release-1.10.0/
cmake .
make -j"$NPROCS"
make install
ldconfig

cd ..
cd ..

rm -rf .__gtest_deps
