#include <iostream>

int main() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused"
  int i = 0, &r = i;
  auto a = r;
  const int ci = i, &cr = ci;
  auto b = ci;
  auto c = cr;
  auto d = &i;
  auto e = &ci;
  const auto &g = ci;
  const auto &j = 42;
  a = 1;
  std::cout << "a = 1; => i=" << i << std::endl;
  b = 2;
  std::cout << "b = 2; => ci=" << ci << std::endl;
  c = 3;
  std::cout << "c = 3x => ci=" << ci << std::endl;
  std::cout << "d = 4;  // d is a pointer" << std::endl;
  std::cout << "e = 4;  // e is a pointer" << std::endl;
  std::cout << "g = 4;  // g does not have modifiable lvalue" << std::endl;
#pragma clang diagnostic pop
  return 0;
}
