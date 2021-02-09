#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>

#include "person_7-9.hxx"
using std::getline;

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 7-9.cxx person_7-9.cxx -o 7-9 && ./7-9
*/
int main() {
  Person p1;
  p1.read(cin);

  cout << "\nName\tAdress:" << endl;
  p1.print(cout) << "\n" << endl;
  return 0;
}
