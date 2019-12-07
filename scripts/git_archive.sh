#!/usr/bin/env bash

set -e

echo "Archiving  $(git log --pretty=format:'%h' -n 1)..."
git archive -o git_archive.zip HEAD