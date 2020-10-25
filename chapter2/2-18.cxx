#include <iostream>

int main() {
  int i = 0, j = 1, *ptr;
  ptr = &i;
  std::cout << "ptr = &i => "
            << "i, j *ptr = " << i << ", " << j << ", " << *ptr << std::endl;
  ptr = &j;
  std::cout << "ptr = &j => "
            << "i, j *ptr = " << i << ", " << j << ", " << *ptr << std::endl;
  *ptr = 2;
  std::cout << "*ptr = 2 => "
            << "i, j *ptr = " << i << ", " << j << ", " << *ptr << std::endl;
  return 0;
}
