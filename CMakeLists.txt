cmake_minimum_required(VERSION 3.16)
project(GelfLogger)

set(CMAKE_CXX_STANDARD 20)

add_library(GelfLogger library.cpp library.h)