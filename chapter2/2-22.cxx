#include <iostream>

int main() {
  int i = 0;  // False
  int *p = &i;
  if (!(*p)) {
    std::cout << "(!(*p)) is true since *p=" << *p << std::endl;
  }
  if (p) {
    std::cout << "p since p is a valid pointer with value p=" << p << std::endl;
  }
  return 0;
}
