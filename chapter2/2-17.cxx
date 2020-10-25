#include <iostream>

int main() {
  int i = 42, &ri = i;
  i = 5;
  ri = 10;
  std::cout << i << " " << ri << std::endl;
  return 0;
}
