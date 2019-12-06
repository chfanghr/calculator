#!/usr/bin/env bash

set -e

echo "Applying patch..."
cd cmd/calc/third_party/cpp-linenoise
git submodule init
git submodule update --remote
git reset --hard
git apply ../cpp_linenoise_patch_mingw.patch
