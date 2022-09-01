#!/bin/bash
# cmake wrapper

if [ $clean -eq 1 ]; then
  echo "--- CLEAN: clean build dir..."
  mkdir -p build
  rm -rv build
  mkdir -p install
  rm -rv install
fi

cmake -B build -S . -D CMAKE_INSTALL_PREFIX=install
cmake --build build -j4 -- install
