#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string l1, l2;
  cout << "Write two strings (end with newline):" << endl;
  getline(cin, l1);
  getline(cin, l2);
  cout << endl;

  cout << "You wrote:" << endl;
  cout << l1 << endl;
  cout << l2 << endl;
  cout << endl;

  if (l1 > l2) {
    cout << l1 << " is larger than " << l2 << endl;
  } else if (l1 < l2) {
    cout << l2 << " is larger than " << l1 << endl;
  } else {
    cout << l1 << " is equal " << l2 << endl;
  }

  cout << endl;

  if (l1.size() > l2.size()) {
    cout << l1 << " is longer than " << l2 << endl;
  } else if (l1.size() < l2.size()) {
    cout << l2 << " is longer than " << l1 << endl;
  } else {
    cout << l1 << " is of equal length as " << l2 << endl;
  }

  return 0;
}
