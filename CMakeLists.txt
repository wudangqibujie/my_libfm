cmake_minimum_required(VERSION 3.21)
project(my_libfm)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_libfm main.cpp util/cmdline.h)
