#!/bin/bash

#Download CGAL from this link
wget https://github.com/CGAL/cgal/releases/download/v5.6/CGAL-5.6.zip
unzip CGAL-5.6.zip


#extract the archive
cd CGAL-5.6
mkdir build


cd build
cmake .. -DCMAKE_BUILD_TYPE="Release" -DWITH_examples=ON -DWITH_demos=ON -DCMAKE_INSTALL_PREFIX="$HOME/.local"

make install
