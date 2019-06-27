#!/bin/bash

do_clean=0
light_clean=0

USAGE="Usage: $0 [-c] [-l] [-h]
Options:
    -c  Clean build and all old CMake files.
    -l  Light clean build (but not clean CMake files).
    -h  Give help description."

while getopts "clh" opt; do
    case "$opt" in
    c) do_clean=1
       light_clean=0
       ;;
    l) light_clean=1
       do_clean=0
       ;;
    h) echo "$USAGE"
       exit
       ;;
    *) echo "Invalid Option!"
       echo "$USAGE"
       exit
       ;;
    esac
done

# do clean
if test $do_clean -eq 1
then
    if [ -e build -a -d build ]; then
        rm -fr build
    fi
    if [ -e bin -a -d bin ]; then
        rm -fr bin
    fi
fi

# do light Clean
if test $light_clean -eq 1
then
    if [ -e bin -a -d bin ]; then
        rm -fr bin
    fi
fi

# create build directory
if [ -e build -a -d build ]
then
    cd build
else
    mkdir build && cd build
fi

# compile source files and build executables
cmake ..
cmake --build .

# create binary library
if ( test $? -eq 0 ); then
    cd ..
    if [ -e bin -a -d bin ]; then
        cd bin && rm -fr *
    else
       mkdir bin && cd bin
    fi
    cp ../build/ch2/src/cs-* ./
fi

