#include <iostream>
using std::cout;
using std::endl;

int main() {
  double dval;
  int ival;
  int dummy = 1;
  int* pi = &dummy;
  dval = ival = 15;
  *pi = 45;
  cout << dval << endl;
  cout << ival << endl;
  cout << *pi << endl;
  dval = ival = *pi = 99;
  cout << dval << endl;
  cout << ival << endl;
  cout << *pi << endl;
  return 0;
}
