cmake_minimum_required(VERSION 3.22)
project(Matrix_Class)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wnon-template-friend")
add_executable(Matrix_Class main.cpp JChannel2.cpp JChannel2.h)
