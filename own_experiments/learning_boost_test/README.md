# Learning Boost.Test

- [Modern tutorial](https://www.boost.org/doc/libs/1_75_0/libs/test/doc/html/index.html)
- [Archaic tutorial](https://www.boost.org/doc/libs/1_45_0/libs/test/doc/html/tutorials/hello-the-testing-world.html)

## Installing boost

```sh
brew install boost
```

**OR**

Download the `*.tar.bz2` from https://www.boost.org/users/download/#live.
The [following](https://www.boost.org/doc/libs/1_75_0/libs/test/doc/html/boost_test/adv_scenarios/build_utf.html) installs boost to `/usr/local`

```sh
tar -xvzf boost_*.tar.bz2
cd boost_*
./bootstrap.sh
./b2
./b2 install
```

## Compile and run test

If you get any errors, see [Troubleshooting](#Troubleshooting) below.

### The stand alone test

One need to specify the path to the library when compiling as explained [here](https://cppsecrets.com/users/14249710697121115114971069748525564103109971051084699111109/C00-BoostTest.php)

```sh
clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2 -Wundef -Wconversion -g3 -Os test_stand_alone.cxx /path/to/libboost_unit_test_framework.a  -o test_stand_alone && ./test_stand_alone
```

In my case `/path/to/libboost_unit_test_framework.a` is `/usr/local/lib/libboost_unit_test_framework.a`

Notice that we are not using the [`-L${DIR} -l${LIB}`](https://www.rapidtables.com/code/linux/gcc/gcc-l.html) (i.e. `-L/path/to/lib -lboost_unit_test_framework` instead of `/path/to/libboost_unit_test_framework.a`) as [`main` is defined in another file](https://stackoverflow.com/questions/550455/compile-error-undefined-symbols-main-referenced-from-start-in-crt1-10-5-o). It could be that [these](https://stackoverflow.com/questions/33143345/boosttest-compiling-and-running-a-hello-world-program) [guys](https://stackoverflow.com/questions/9881288/compiling-a-boost-test-with-cmake) succeeds as they are using a different linker than the one `clang` uses.

Note that [-I${DIR}](https://www.rapidtables.com/code/linux/gcc/gcc-i.html) is not needed as we are not adding headers

More about the compilation process [here](https://medium.com/@dreamanip/c-static-library-and-dynamic-library-d7803ae8eef5)

### The add test

Here we need to add `add.cxx` in order for the test to see the `add` function. Compile and run with

```sh
clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2 -Wundef -Wconversion -g3 -Os test_add.cxx add.cxx /usr/local/lib/libboost_unit_test_framework.a -o test_add && ./test_add
```

### The multiply AND subtract test

Here we are bundling multiply and subtract into [one test](https://stackoverflow.com/questions/57168152/boost-unit-test-in-separate-cpp-files). Compile and run (with `log-level=all`) with

```sh
clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2 -Wundef -Wconversion -g3 -Os test_main_subtract_multiply.cxx test_subtract.cxx subtract.cxx test_multiply.cxx multiply.cxx /usr/local/lib/libboost_unit_test_framework.a -o test_subtract_multiply && ./test_subtract_multiply -l all
```

### Troubleshooting

#### Compile errors

In certain versions the extra check flags seems to trigger `[-Werror,-Wundef]` and `[-Werror,-Wsign-conversion]`.

A dirty hack for `[-Werror,-Wundef]` is found [in this issue](https://github.com/boostorg/config/issues/322).

A dirty hack for the other errors is to add

```c++
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtheerror"
// The line with error
#pragma clang diagnostic pop
```

with `"-Wtheerror"` being the error around the line of issue.

#### `vsc` cannot find `<boost/test/unit_test.hpp>`

Add the following to `.vscode/c_cpp_properties.json` (this file is usually automatically made when you agree to update `includePath` in the `vsc` pop-up)

```json
{
    "configurations": [
        {
            "includePath": [
                "/path/to/boost/include/**"
            ],
        }
    ],
}
```

In my case `/path/to/boost/include/**` is `/usr/local/Cellar/boost/1.75.0_2/include/**`