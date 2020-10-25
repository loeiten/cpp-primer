#include <iostream>

int main() {
  int a = 3, b = 4;
  decltype(a) c = a;    // c is int
  decltype((b)) d = a;  // d is int& referring to a
  ++c;                  // c bumped to 4
  ++d;                  // d bumped to 4, which means that a is bumped to 4
  std::cout << "(a,b,c,d)=(" << a << "," << b << "," << c << "," << d << ")"
            << std::endl;
  return 0;
}
