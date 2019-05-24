#!/bin/bash

CC=gcc-9 && CXX=g++-9

mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make unit_tests gui
echo "."
ls -l .
echo "bin"
ls -l bin
find . -name unit_tests
bin/unit_tests

