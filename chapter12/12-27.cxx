#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include "queryResult_12-27.hxx"
#include "textQuery_12-27.hxx"

void runQueries(ifstream &inFile) {
  TextQuery tq(inFile);

  while (true) {
    cout << "Enter the word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q") {
      break;
    }
    print(cout, tq.query(s)) << endl;
  }
}

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 12-27.cxx textQuery_12-27.cxx queryResult_12-27.cxx
-o 12-27 && ./12-27
*/
int main() {
  string fileName = "../chapter3/lorem.txt";
  ifstream inFile(fileName);

  if (!inFile.is_open()) {
    cerr << "Could not open \"" << fileName << "\"" << endl;
  }

  runQueries(inFile);
  return 0;
}
