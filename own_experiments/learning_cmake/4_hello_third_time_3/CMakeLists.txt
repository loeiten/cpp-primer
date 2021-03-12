cmake_minimum_required(VERSION 3.10)

project(Third_hello_two VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# NOTE: This makes MyLibrary and contains its own CMakeLists.txt
add_subdirectory(third_hello)

add_executable(my_bin main.cxx second_hello.cxx)

target_link_libraries(my_bin PUBLIC MyLibrary)
