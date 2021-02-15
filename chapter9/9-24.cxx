#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <exception>
using std::exception;

#include <vector>
using std::vector;

int main() {
  vector<int> foo;
  try {
    cout << foo.at(0) << endl;
  } catch (const exception& e) {
    cerr << "Caugth error: e.what()=" << e.what() << '\n';
  }

  // The rest leads to segfault
  // cout << foo[0] << endl;
  // cout << *foo.begin() << endl;
  // cout << *foo.end() << endl;
  return 0;
}
