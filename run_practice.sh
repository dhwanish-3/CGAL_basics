#!/bin/bash

# Find the file that was modified last
file=$(find . -name "*.cpp" -type f -printf '%T@ %p\n' | sort -n | tail -1 | cut -f2- -d" ")

# go to the directory where the file is located
cd $(dirname $file)

pwd

# create a bin directory if it does not exist
if [ ! -d "bin" ]; then
  mkdir bin
fi

cd bin

# generate make files for compiling
cmake "../"

# compile the code
make

# run the code
./$(basename $file .cpp)
