#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "factorial.hxx"

/*
Compile instructions

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os -c 6-9.cxx clang++ -std=c++14 -Wall -Wextra -Werror
-Wshadow -Wdouble-promotion -Wformat=2 -Wundef -Wconversion -g3 -Os -c
factorial.cxx clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow
-Wdouble-promotion -Wformat=2 -Wundef -Wconversion -g3 -Os  factorial.o 6-9.o -o
6-9
*/
int main() {
  int i;
  cout << "Take fatorial of what number:" << endl;
  cin >> i;
  cout << i << "! = " << factorial(i) << endl;
  return 0;
}
