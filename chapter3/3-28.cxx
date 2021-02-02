#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
// NOTE: Global strings are not permitted
string sa[3];  // NOLINT
int ia[3];
#pragma clang diagnostic pop

int main() {
  string sa2[3];
  int ia2[3];
  cout << "Printing contents of sa (global)" << endl;
  for (auto s : sa) {
    cout << s << endl;
  }
  cout << "Printing contents of sa2 (inside main)" << endl;
  for (auto s : sa2) {
    cout << s << endl;
  }
  cout << "Printing contents of ia (global)" << endl;
  for (auto i : ia) {
    cout << i << endl;
  }
  cout << "Printing contents of ia2 (inside main)" << endl;
  for (auto i : ia2) {
    cout << i << endl;
  }
  return 0;
}
