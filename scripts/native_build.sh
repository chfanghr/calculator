#!/usr/bin/env bash

set -e

NPROCS=$(nproc 2>/dev/null ||
  sysctl -n hw.ncpu 2>/dev/null ||
  getconf _NPROCESSORS_ONLN 2>/dev/null)

cmake -H. -B"$(uname)_build"
cmake --build "$(uname)_build" -j"${NPROCS}"
