#!/usr/bin/env bash

set -e

echo "Applying patch..."
cd cmd/calc/third_party/cpp-linenoise
git submodule init
git submodule update --remote
git checkout 13e90d3b85e82c8b2ef057d5365340e44397d802 # lock dep version
git reset --hard
git apply ../cpp_linenoise_patch_mingw.patch
