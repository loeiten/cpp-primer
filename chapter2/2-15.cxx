#include <iostream>

int main() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wliteral-conversion"
  int ival = 1.01;
#pragma clang diagnostic pop

// int &rval1 = 1.01;  // Cannot bind to temporary
#pragma clang diagnostic ignored "-Wunused-variable"
  int &rval2 = ival;
#pragma clang diagnostic pop
  // int &rval3;  // Requires initializer
  return 0;
}
