cmake_minimum_required(VERSION 3.22)
project(matrix C)

set(CMAKE_C_STANDARD 99)

add_executable(matrix main.c cmatrix.h cmatrix.c)
