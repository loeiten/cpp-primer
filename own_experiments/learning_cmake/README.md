# Learning CMake

- [Explanatory CMake toturial](https://www.cs.swarthmore.edu/~adanner/tips/cmake.php)
- [Official CMake tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [Example repository](https://github.com/albertchan/cmake-boost-demo)

## Key takeaways

1. The `cmake` in

    ```sh
    mkdir my_build_dir
    cd my_build_dir
    cmake ../path_to_project
    ```

    genereates the `Makefile`.
2. `cmake --build .` puts compiles the binaries and put it into this directory
3. If the source files are updated, only `cmake --build .` needs to be executed again
4. Cleaning can be done by removing the contents of the build dir `rm -rf my_build_dir`
