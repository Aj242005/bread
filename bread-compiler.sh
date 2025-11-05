#!/bin/bash

echo "Compiling the provided bread script named $1 "

g++ process.cpp -o bread-compiler

./bread-compiler $1