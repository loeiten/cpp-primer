#include <vector>
using std::vector;

#include <string>
using std::getline;
using std::string;
using std::toupper;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  vector<string> text;
  cout << "Enter text:" << endl;
  string line;
  while (getline(cin, line)) {
    text.push_back(line);
  }
  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
    for (auto &c : *it) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
      // May overflow when converting size_type to int in toupper
      // https://stackoverflow.com/a/22184543/2786884
      c = toupper(c);
#pragma clang diagnostic pop
    }
  }
  for (auto it = text.cbegin(); it != text.cend(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
