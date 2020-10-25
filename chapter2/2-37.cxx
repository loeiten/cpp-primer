#include <iostream>

int main() {
  int a = 3, b = 4;
  decltype(a) c = a;  // c is int
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunevaluated-expression"
  decltype(a = b) d = a;  // d is int& referring to a, a =  b not evaluated
#pragma clang diagnostic pop
  std::cout << "(a,b,c,d)=(" << a << "," << b << "," << c << "," << d << ")"
            << std::endl;
  return 0;
}
