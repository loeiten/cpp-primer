#include <iostream>

int main() {
  int i = 42, *p = &i;
  *p = *p * *p;
  std::cout << "*p,i = " << *p << "," << i << std::endl;
  return 0;
}
