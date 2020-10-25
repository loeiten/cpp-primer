#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main() {
  const string s = "Keep out!";
  for (auto &c : s) {
    // c = 'x';  // c is const
    cout << c << endl;
  }
  return 0;
}
