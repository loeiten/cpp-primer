#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string new_line, concatenate_line, test;
  test = "Just write..." + test + "I will concatenate";
  cout << test << endl;
  while (cin >> new_line) {
    cout << endl;
    concatenate_line += " " + new_line;
    cout << concatenate_line << endl;
  }
  return 0;
}
