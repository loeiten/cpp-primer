#include <iostream>
using std::cout;
using std::endl;

int main() {
  int x[10];
  int *p = x;

  cout << sizeof(x) / sizeof(*x) << endl;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsizeof-pointer-div"
  // NOTE: 'sizeof (p)' will return the size of the pointer, not the array
  // itself
  cout << sizeof(p) / sizeof(*p) << endl;
#pragma clang diagnostic pop

  cout << "\n" << endl;
  cout << sizeof(p) << endl;
  cout << sizeof(*p) << endl;

  return 0;
}
