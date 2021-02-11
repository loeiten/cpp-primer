#include <iostream>
using std::cout;
using std::endl;

#include "screen_7-29.hxx"

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 7-29.cxx screen_7-29.cxx -o 7-29 && ./7-29
*/
int main() {
  Screen myScreen{5, 5, 'X'};
  myScreen.moveCursor(4, 0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
  return 0;
}
