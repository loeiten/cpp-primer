#include <iostream>
int main() {
  int v1 = 0, v2 = 0;
  std::cout << "Write two numbers in descending order: " << std::endl;
  std::cin >> v1 >> v2;
  while (v1 >= v2) {
    std::cout << v2 << std::endl;
    ++v2;
  }
}
