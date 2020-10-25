#include <iostream>

int main() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused"
  int i = -1;
  // int &r = 0;  // Not referrencing an object or a const
  int i2 = 1;
  int *const p2 = &i2;  // The pointer is constant
  std::cout << "int *const p2 = &i2; => "
            << "*p2=" << *p2 << std::endl;
  std::cout << "p2 = &i;  // Not allowed since the pointer is constant"
            << std::endl;
  *p2 = 42;
  std::cout << "*p2 = 42; => "
            << "*p2=" << *p2 << " i2=" << i2 << std::endl;
  const int i3 = -1, &r = 0;  // The qualifier applies to all definitions
  // From: https://www.learncpp.com/cpp-tutorial/610-pointers-and-const/
  // A const pointer to a const value can not be set to point to another
  // address, nor can the value it is pointing to be changed through the
  // pointer.
  const int *const p3 = &i2;
  std::cout << "int i2 = 1;" << std::endl;
  std::cout << "const int *const p3 = &i2; => "
            << "*p3=" << *p3 << std::endl;
  i2 = 2;
  std::cout << "i2 = 2; => "
            << "*p3=" << *p3 << std::endl;
  std::cout << "*p3 = 4;  // Not allowed to change the value due to the 'const "
               "int' part"
            << std::endl;
  std::cout << "p3 = &i;  // Not allowed through the '*const part'"
            << std::endl;
  const int *p1 = &i2;
  std::cout << "const int &const r3=i;  // const qualifier may not be applied "
               "to a reference"
            << std::endl;
  const int i4 = i, &r3 = i;
  std::cout << "const int i4 =i, &r3 =i; r3 = 77;  // last expression fails as "
               "not modifiable lvalue"
            << std::endl;
#pragma clang diagnostic pop
  return 0;
}
