#!/bin/bash

CC=gcc-8 && CXX=g++-8

mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make unit_tests gui
./unit_tests/bin/unit_tests
