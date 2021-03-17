# Learning profiling

## Installation

`callgrind` is already bundled with the `valgrind` installation.

For visualization `qcachegrind` or `kcahcegrind` should be installed. On mac:

```sh
brew install qcachegrind
```

## Include only part of program

If you are only interested in a part of the program, you can profile by adding `CALLGRIND` macros like so

```c++
#include <valgrind/callgrind.h>

void my_func(){
    CALLGRIND_START_INSTRUMENTATION;  // Together with --instr-atstart=no
    CALLGRIND_TOGGLE_COLLECT;  // Together with --collect-atstart=no
    /* Code to profile */
    CALLGRIND_TOGGLE_COLLECT;
    CALLGRIND_STOP_INSTRUMENTATION;
}

int main(){
    my_func()
    return 0;
}
```

you can also dump a file at a certain point by using the `CALLGRIND_DUMP_STATS` macro. This will add a `.1`, `.2` etc. to the main file for all flag points

## Compile

You need to add the `-pg` flag to your compilation with `gcc`. However, the following seems to work with `clang`:

```sh
clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2 -Wundef -Wconversion -g3 -Os hello_profile.cxx -o hello_profile
```

## Run

Running the `callgrind` tool (use `--instr-atstart=no` and `--collect-atstart=no` to take effect of `CALLGRIND_START_INSTRUMENTATION` and `CALLGRIND_TOGGLE_COLLECT`)

```sh
valgrind --callgrind-out-file=callgrind.out.hello_profile --instr-atstart=no --collect-atstart=no ./hello_profile
```

This will create a `callgrind.out.*` file, which can be read by `qcachegrind` like this

```sh
qcachegrind calgrind.out.*
```

## Interpretation

**NOTE**: The percentage, number of calls and template values can be toggled in the GUI

- `Incl.` - Sum of itself + all child calls as a percentage of the whole.
- `Self` - Exclusive count spent in the selected function
- `Called` - Number of times the function was called
- `Ir` - The number of instructions executed in total by the selected function after being called by this caller
- `Ir per call` - The number of instructions executed per call.
- `Count` - The number of times the selected function was called by the caller.
- `Caller` - The function that directly called the selected function.

## Links

- [Short tutorial](https://medium.com/@jacksonbelizario/profiling-a-c-program-with-valgrind-callgrind-b41f15b31527)
- [More detailed tutorial](https://developer.mantidproject.org/ProfilingWithValgrind.html)
- [How to interpret the results](https://stackoverflow.com/questions/23786152/how-to-interpret-results-from-kcachegrind)
