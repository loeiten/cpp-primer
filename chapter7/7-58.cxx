#include <iostream>
using std::cout;
using std::endl;

#include "example_7-58.hxx"

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 7-58.cxx example_7-58.cxx -o 7-58 && ./7-58
*/
int main() {
  cout << Example::rate << endl;
  cout << Example::vecSize << endl;
  cout << Example::vec.size() << endl;
  return 0;
}
