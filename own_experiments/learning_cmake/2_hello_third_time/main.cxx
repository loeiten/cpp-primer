#include <iostream>

#include "second_hello.hxx"
#include "third_hello/third_hello.hxx"
using std::cout;
using std::endl;

int main() {
  cout << "Hello, world!" << endl;
  second_hello();
  third_hello();
  return 0;
}
