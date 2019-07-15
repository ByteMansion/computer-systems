# Computer Systems - A Programmer's Perspective

## Why this repo?
- List solutions to Homework Problems of the classic cs book - Computer Systems: a programmer's perspective $ 3^{rd}$.
- Document some important points.

## Prerequisite
This repo created an project to compile all source files and build executables.
I do my utmost to simplify the compile and build process.

First of all, the system should meet below basic demands.
1. install [CMake](https://cmake.org/)
2. you host should be 32-bit or beyond.

## Build
Execute `cs_build.sh` script to build all files.
`cs_build.sh` supports several options:
1. -c  Clean build.
2. -l  Light clean and build.
3. -h  Help

Above command will create 2 folders `build` and `bin` in current path.
`build` folder is for build files and `bin` folder is for all executables.

## Execution
Enter `bin` folder and find all executables. If you want to execute a certain executables,just use like following command:
```
./cs-showbytes
```

## Catalogue

[Chapter2 Representing and Manipulating Information信息的表示和处理](./ch2/)


