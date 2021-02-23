#include <iostream>
using std::cout;
using std::endl;

#include "strBlob_12-1.hxx"

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 12-1.cxx strBlob_12-1.cxx -o 12-1 && ./12-1
*/
int main() {
  StrBlob b1;
  {
    StrBlob b2{"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
    cout << "b2.size()=" << b2.size() << endl;
  }
  cout << "b1.size()=" << b1.size() << endl;
  return 0;
}
