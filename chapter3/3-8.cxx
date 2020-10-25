#include <cctype>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string s;
  cout << "I will turn your string to capitals, then x's. Enter a string"
       << endl;
  getline(cin, s);
  cout << "You entered:\n" << s << endl;
  decltype(s.size()) l = 0;
  while (l < s.size()) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
    // May overflow when converting size_type to int in toupper
    // https://stackoverflow.com/a/22184543/2786884
    s[l] = toupper(s[l]);
#pragma clang diagnostic pop
    ++l;
  }
  cout << "I turned it into\n" << s << endl;
  for (decltype(s.size()) i = 0; i < s.size(); ++i) {
    if (isalnum(s[i])) {
      s[i] = 'X';
    }
  }
  cout << "And to\n" << s << endl;
  return 0;
}
