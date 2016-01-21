cmake_minimum_required(VERSION 3.3)
project(ex1)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(SOURCE_FILES my_stat.c)
set(CMAKE_C_FLAGS_DEBUG -g)

add_executable(ex1 ${SOURCE_FILES})