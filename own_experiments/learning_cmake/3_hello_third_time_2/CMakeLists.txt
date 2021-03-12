cmake_minimum_required(VERSION 3.10)

project(Third_hello_two VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# NOTE: This makes MyLibrary and contains its own CMakeLists.txt
add_subdirectory(third_hello)

add_executable(my_bin main.cxx second_hello.cxx)

target_link_libraries(my_bin PUBLIC MyLibrary)

# NOTE: This makes it possible to use
#       #include "my_third_hello.hxx"
#       instead of
#       #include "third_hello/my_third_hello.hxx"
#       in main.cxx
target_include_directories(my_bin PUBLIC ${PROJECT_SOURCE_DIR}/third_hello)
