#include <iostream>

#include "my_third_hello.hxx"
#include "second_hello.hxx"
using std::cout;
using std::endl;

int main() {
  cout << "Hello, world!" << endl;
  second_hello();
  third_hello();
  return 0;
}
