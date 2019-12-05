#!/usr/bin/env bash

set -e

cmake -DCMAKE_BUILD_TYPE=Debug -H. -B"$(uname)_build_debug"
cmake --build "$(uname)_build_debug"

cmake -DCMAKE_BUILD_TYPE=Release -H. -B"$(uname)_build_release"
cmake --build "$(uname)_build_release"
