#include <cctype>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string s;
  cout << "I will turn your string to x's. Enter a string" << endl;
  getline(cin, s);
  cout << "You entered:\n" << s << endl;
  for (char &c : s) {
    if (isalnum(c)) {
      c = 'X';
    }
  }
  cout << "I turned it into\n" << s << endl;
  return 0;
}
