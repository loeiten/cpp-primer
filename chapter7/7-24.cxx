#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::getline;

#include "person_7-22.hxx"

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 7-24.cxx person_7-24.cxx -o 7-24 && ./7-24
*/
int main() {
  Person p1{"Mr. Anderson", "Zion 777"};
  Person p2(cin);

  cout << "\nName\tAdress:" << endl;
  p1.print(cout) << endl;
  p2.print(cout) << endl;
  return 0;
}
