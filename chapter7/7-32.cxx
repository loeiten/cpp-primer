#include <iostream>
using std::cout;
using std::endl;

#include "screen_7-32.hxx"
#include "window_mgr_7-32.hxx"

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 7-32.cxx screen_7-32.cxx window_mgr_7-32.cxx -o
7-32 && ./7-32
*/
int main() {
  Screen myScreen{5, 5, 'X'};
  Window_mgr myMgr;

  myMgr.add(&myScreen);

  myMgr.get(1)->moveCursor(4, 0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";

  cout << "Clearing" << endl;
  myMgr.clear(1);

  myMgr.get(1)->display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
  return 0;
}
