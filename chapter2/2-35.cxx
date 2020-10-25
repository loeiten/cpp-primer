#include <iostream>

int main() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused"
  const int i = 42;
  auto j = i;
  const auto &k = i;
  auto *p = &i;
  const auto j2 = i, &k2 = i;
  std::cout << "++i;  // Epression has no modifiable lvalue" << std::endl;
  std::cout << "j is modifiable: Current value j=" << j << std::endl;
  ++j;
  std::cout << "++j; => j=" << j << std::endl;
  std::cout << "++k;  // Epression has no modifiable lvalue" << std::endl;
  std::cout << "*p = 1;  // & of a const is a low-level const" << std::endl;
  std::cout << "++j2;  // Epression has no modifiable lvalue" << std::endl;
  std::cout << "++k2;  // Epression has no modifiable lvalue" << std::endl;
  // Own experiment below
  int foo = 1, *bar = &foo;
  ++*bar;
  std::cout << "++*bar=" << *bar << std::endl;
#pragma clang diagnostic pop
  return 0;
}
