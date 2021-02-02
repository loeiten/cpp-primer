#include <iostream>
using std::cout;
using std::endl;

int main() {
  int i;
  double d;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wliteral-conversion"
  d = i = 3.5;
#pragma clang diagnostic pop
  cout << "i=" << i << endl;
  cout << "d=" << d << endl;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-conversion"
  i = d = 3.5;
#pragma clang diagnostic pop
  cout << "i=" << i << endl;
  cout << "d=" << d << endl;
  return 0;
}
