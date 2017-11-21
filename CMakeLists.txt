cmake_minimum_required(VERSION 3.8)
project(TADSTACK)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pila.h)
add_executable(TADSTACK ${SOURCE_FILES})