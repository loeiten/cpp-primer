#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string in_line;
  cout << "Enter a string:" << endl;
  while (cin >> in_line) {
    if (in_line == "stop") {
      break;
    }
    cout << "You wrote: " << in_line << "\n" << endl;
    cout << "Enter a string:" << endl;
  }
  cout << "Enter a string:" << endl;
  while (getline(cin, in_line)) {
    if (in_line == "stop") {
      break;
    }
    cout << "You wrote: " << in_line << "\n" << endl;
    cout << "Enter a string:" << endl;
  }
  return 0;
}
