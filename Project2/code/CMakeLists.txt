cmake_minimum_required(VERSION 3.22)
project(calculator_struct)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculator_struct main.cpp numberSaver.cpp numberSaver.h printTools.cpp printTools.h Operator.cpp Operator.h divide_internet.cpp divide_internet.h)
