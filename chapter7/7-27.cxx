#include <iostream>
using std::cout;
using std::endl;

#include "screen_7-27.hxx"

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 7-27.cxx screen_7-27.cxx -o 7-27 && ./7-27
*/
int main() {
  Screen myScreen{5, 5, 'X'};
  myScreen.moveCursor(4, 0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
  return 0;
}
