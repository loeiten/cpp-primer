add_library(MyLibrary my_third_hello.cxx)

# Consumers will require this due to INTERFACE
target_include_directories(MyLibrary INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
