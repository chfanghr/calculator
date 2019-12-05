#!/usr/bin/env bash

set -e

cmake -H. -B"$(uname)_build"
cmake --build "$(uname)_build"
