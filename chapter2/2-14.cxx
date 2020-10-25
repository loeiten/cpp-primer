#include <iostream>

int main() {
  int i = 100, sum = 0;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"
  for (int i = 0; i != 10; ++i) {
    sum += i;
  }
#pragma clang diagnostic pop
  std::cout << i << " " << sum << std::endl;
  return 0;
}
