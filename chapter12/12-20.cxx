#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "strBlobPtr_12-20.hxx"
#include "strBlob_12-20.hxx"

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 12-20.cxx strBlob_12-20.cxx strBlobPtr_12-20.cxx -o
12-20 && ./12-20
*/
int main() {
  string fileName = "../chapter3/lorem.txt";
  ifstream inFile(fileName);
  string line;

  StrBlob b;

  if (!inFile.is_open()) {
    cerr << "Could not open \"" << fileName << "\"" << endl;
    return -1;
  }

  while (getline(inFile, line)) {
    b.push_back(line);
  }

  // NOTE: As we do not have defined ==, we need a seperate counter
  vector<string>::size_type pos = 0;
  for (auto bp = b.begin(); pos != b.size(); bp.incr(), ++pos) {
    cout << bp.deref() << endl;
  }

  cout << "\n\nNOTE: b.end().deref() would yield error, as b.end() points to "
          "one past the last element of b"
       << endl;

  return 0;
}
