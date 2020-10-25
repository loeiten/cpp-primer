#include <iostream>

int main() {
  int i = 42, &r1 = i;
  double d = 0.01, &r2 = d;
  r2 = 3.14;
  std::cout << "r2 = 3.14 => "
            << "d=" << d << " r2=" << r2 << std::endl;
  r2 = r1;  // Implicit conversion from double to int
  std::cout << "r2 = r1 => "
            << "r1=" << r1 << " d=" << d << std::endl;
  d = 0.99;
  std::cout << "d = 0.99 => "
            << "r1=" << r1 << " r2=" << r2 << std::endl;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-conversion"
  r1 = r2;
  std::cout << "r1 = r2 => "
            << "r1=" << r1 << " d=" << d << std::endl;
  i = 77;
  std::cout << "i = 77 => "
            << "r1=" << r1 << " r2=" << r2 << std::endl;
  i = r2;
  std::cout << "i = r2 => "
            << "i=" << i << std::endl;
  r1 = d;
#pragma clang diagnostic pop
  return 0;
}
