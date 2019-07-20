cmake_minimum_required(VERSION 2.6)
project(cs)
enable_testing()

function(add_solution name)
    enable_testing()
    set(_sources ${ARGN})
    add_executable(${name} ${_sources})
    add_test(NAME ${name}
             COMMAND  ./${name})
endfunction()

add_subdirectory(ch2)
add_subdirectory(ch3)