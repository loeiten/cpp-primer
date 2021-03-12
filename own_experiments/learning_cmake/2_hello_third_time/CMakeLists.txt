cmake_minimum_required(VERSION 3.10)

project(Third_hello VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(hello_third main.cxx second_hello.cxx third_hello/third_hello.cxx)
