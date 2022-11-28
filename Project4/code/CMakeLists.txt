cmake_minimum_required(VERSION 3.22)
project(Matrix_Ultra C)

set(CMAKE_C_STANDARD 99)

#O3
set(CMAKE_C_FLAGS "-O3")

#openMP
FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
endif()

#avx
#set(CMAKE_C_FLAGS "-mavx2")

add_executable(Matrix_Ultra main.c matrix.c matrix.h data.c)
#add_executable(Matrix_Ultra main.c matrix.c matrix.h)