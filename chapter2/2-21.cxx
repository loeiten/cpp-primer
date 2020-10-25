#include <iostream>

int main() {
  int i = 0;
// double* dp = &i;  // a value of type "int *" cannot be used to initialize an
// entity of type "double *" int *ip = i;  // int cannot initialize int*
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused"
  int *ip = &i;
#pragma clang diagnostic pop
  return 0;
}
