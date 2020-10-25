#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"
int i = 42;
#pragma clang diagnostic pop

int main() {
  int i = 100;
  int j = i;
  std::cout << j << std::endl;
  return 0;
}
