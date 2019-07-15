function(add_solution name)
    enable_testing()
    set(_sources ${ARGN})
    add_executable(${name} ${_sources})
    add_test(NAME ${name}
             COMMAND  ./${name})
endfunction()

add_subdirectory(src)