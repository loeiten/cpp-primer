#include <iostream>
using std::cout;
using std::endl;

int main() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-float-conversion"
  float fval = 3.14;
#pragma clang diagnostic pop
  double dval = 2.71;
  int ival = 42;
  char cval = 2;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-conversion"
  if (fval) {
#pragma clang diagnostic pop
    cout << "fval is non-zero" << endl;
  }

  fval = 0.0;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-conversion"
  if (!fval) {
#pragma clang diagnostic pop
    cout << "fval was set to 0.0" << endl;
  }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-float-conversion"
  fval = 3.14;
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
  dval = fval + ival;
#pragma clang diagnostic pop

  cout << "dval = " << dval << endl;
  cout << dval + ival * cval << endl;

  return 0;
}
