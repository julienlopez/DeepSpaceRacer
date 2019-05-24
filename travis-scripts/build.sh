#!/bin/bash

CC=gcc-9 && CXX=g++-9

mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make unit_tests gui
./unit_tests/unit_tests
