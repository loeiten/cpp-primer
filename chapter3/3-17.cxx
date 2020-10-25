#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

using std::string;
using std::toupper;

int main() {
  vector<string> v1;
  string s;
  cout << "Enter a string: " << endl;
  while (cin >> s) {
    v1.push_back(s);
    cout << "Enter a string: " << endl;
  }
  cout << "Transforming to uppercase:" << endl;

  for (auto &r : v1) {
    for (auto &c : r) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
      // May overflow when converting size_type to int in toupper
      // https://stackoverflow.com/a/22184543/2786884
      c = toupper(c);
#pragma clang diagnostic pop
    }
  }
  cout << "Printing 8 words per line:" << endl;

  int i = 0;
  for (auto &r : v1) {
    cout << r;
    if (i == 7) {
      i = 0;
      cout << endl;
    } else {
      cout << " ";
    }

    ++i;
  }

  return 0;
}
