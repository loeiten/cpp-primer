#include <iostream>
using std::cout;
using std::endl;

int* getPtr(const int& i) { return &i; }

int main() {
  int ival = 42;
  int* pi = getPtr(ival);

  cout << ival << endl;
  cout << *pi << endl;

  *pi = 0;

  cout << ival << endl;
  cout << *pi << endl;

  int* pi2;
  // NOTE: We are checking if this is not the null pointer, not that the value
  // is 0
  if ((pi2 = getPtr(ival)) != 0) {
    cout << "getPtr(ival)) != 0" << endl;
    cout << "*pi2 = " << *pi2 << endl;
  }

  ival = 1024;

  cout << ival << endl;
  cout << *pi << endl;
  cout << *pi2 << endl;

  if (ival == 1024) {
    cout << "SUCCESS" << endl;
  }
  return 0;
}
