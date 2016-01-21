cmake_minimum_required(VERSION 3.3)
project(ex2)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(SOURCE_FILES filecopy.c)
set(CMAKE_C_FLAGS_DEBUG -g)

add_executable(ex2 ${SOURCE_FILES})