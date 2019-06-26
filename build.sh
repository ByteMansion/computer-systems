#!/usr/bin/sh

# create build directory
if [ -e build -a -d build ]
then
    cd build
else
    mkdir build && cd build
fi

# compile source files and build executables
cmake .. && cmake --build ./

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

